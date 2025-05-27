#include "DatabaseManager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager() {
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("bloodbanksystem");
    db.setUserName("postgres");
    db.setPassword("kaluLILUYA#1");
}

DatabaseManager::~DatabaseManager() {
    if (db.isOpen()) {
        db.close();
    }
}

bool DatabaseManager::connect() {
    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return false;
    }
    qDebug() << "Database connected successfully!";
    return true;
}

bool DatabaseManager::donorLogin(const QString& username, const QString& password) {
    QSqlQuery query;
    query.prepare("SELECT * FROM donors WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    if (!query.exec()) {
        qDebug() << "Donor login query failed:" << query.lastError().text();
        return false;
    }
    return query.next();
}

bool DatabaseManager::supervisorLogin(const QString& username, const QString& password) {
    qDebug() << "Attempting login for username:" << username << "password:" << password;

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM supervisors WHERE username = ? AND password = ?");
    query.addBindValue(username);
    query.addBindValue(password);

    if (!query.exec()) {
        qDebug() << "Database query failed:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        int count = query.value(0).toInt();
        qDebug() << "Query result count:" << count;
        return (count > 0);
    }

    qDebug() << "No results returned from query.";
    return false;
}


bool DatabaseManager::registerDonor(const Donor& donor, const QString& password) {
    QSqlQuery query;
    query.prepare("INSERT INTO donors (id, first_name, last_name, gender, phone, username, blood_type, region, woreda, kebele, city, password) "
                  "VALUES (:id, :firstName, :lastName, :gender, :phone, :username, :bloodType, :region, :woreda, :kebele, :city, :password)");
    query.bindValue(":id", donor.id);
    query.bindValue(":firstName", donor.firstName);
    query.bindValue(":lastName", donor.lastName);
    query.bindValue(":gender", donor.gender);
    query.bindValue(":phone", donor.phone);
    query.bindValue(":username", donor.username);
    query.bindValue(":bloodType", donor.bloodType);
    query.bindValue(":region", donor.region);
    query.bindValue(":woreda", donor.woreda);
    query.bindValue(":kebele", donor.kebele);
    query.bindValue(":city", donor.city);
    query.bindValue(":password", password);
    if (!query.exec()) {
        qDebug() << "Donor registration failed:" << query.lastError().text();
        return false;
    }
    return true;
}

Donor DatabaseManager::getDonorByUsername(const QString& username) {
    Donor donor;
    QSqlQuery query;
    query.prepare("SELECT * FROM donors WHERE username = :username");
    query.bindValue(":username", username);
    if (query.exec() && query.next()) {
        donor.id = query.value("id").toString();
        donor.firstName = query.value("first_name").toString();
        donor.lastName = query.value("last_name").toString();
        donor.gender = query.value("gender").toString();
        donor.phone = query.value("phone").toString();
        donor.username = query.value("username").toString();
        donor.bloodType = query.value("blood_type").toString();
        donor.region = query.value("region").toString();
        donor.woreda = query.value("woreda").toString();
        donor.kebele = query.value("kebele").toString();
        donor.city = query.value("city").toString();
    }
    return donor;
}

QVector<MedicalHistory> DatabaseManager::getMedicalHistory(const QString& donorId) {
    QVector<MedicalHistory> history;
    QSqlQuery query;
    query.prepare("SELECT * FROM medical_history WHERE donor_id = :donorId");
    query.bindValue(":donorId", donorId);
    if (query.exec()) {
        while (query.next()) {
            MedicalHistory medical;
            medical.donorId = query.value("donor_id").toString();
            medical.hivStatus = query.value("hiv_status").toBool();
            medical.syphilisStatus = query.value("syphilis_status").toBool();
            medical.hepatitisStatus = query.value("hepatitis_status").toBool();
            medical.sugarLevel = query.value("sugar_level").toFloat();
            medical.message = query.value("message").toString();
            history.append(medical);
        }
    } else {
        qDebug() << "Medical history query failed:" << query.lastError().text();
    }
    return history;
}

QVector<HealthHistory> DatabaseManager::getHealthHistory(const QString& donorId) {
    QVector<HealthHistory> history;
    QSqlQuery query;
    query.prepare("SELECT * FROM health_history WHERE donor_id = :donorId");
    query.bindValue(":donorId", donorId);
    if (query.exec()) {
        while (query.next()) {
            HealthHistory health;
            health.donorId = query.value("donor_id").toString();
            health.date = query.value("date").toString();
            health.weight = query.value("weight").toFloat();
            health.bloodPressure = query.value("blood_pressure").toString();
            health.sugarLevel = query.value("sugar_level").toFloat();
            health.startTime = query.value("start_time").toString();
            health.endTime = query.value("end_time").toString();
            history.append(health);
        }
    } else {
        qDebug() << "Health history query failed:" << query.lastError().text();
    }
    return history;
}

bool DatabaseManager::addMedicalHistory(const MedicalHistory& medical) {
    QSqlQuery query;
    query.prepare("INSERT INTO medical_history (donor_id, hiv_status, syphilis_status, hepatitis_status, sugar_level, message) "
                  "VALUES (:donorId, :hivStatus, :syphilisStatus, :hepatitisStatus, :sugarLevel, :message)");
    query.bindValue(":donorId", medical.donorId);
    query.bindValue(":hivStatus", medical.hivStatus);
    query.bindValue(":syphilisStatus", medical.syphilisStatus);
    query.bindValue(":hepatitisStatus", medical.hepatitisStatus);
    query.bindValue(":sugarLevel", medical.sugarLevel);
    query.bindValue(":message", medical.message);
    if (!query.exec()) {
        qDebug() << "Add medical history failed:" << query.lastError().text();
        return false;
    }
    return true;
}

bool DatabaseManager::addHealthHistory(const HealthHistory& health) {
    QSqlQuery query;
    query.prepare("INSERT INTO health_history (donor_id, date, weight, blood_pressure, sugar_level, start_time, end_time) "
                  "VALUES (:donorId, :date, :weight, :bloodPressure, :sugarLevel, :startTime, :endTime)");
    query.bindValue(":donorId", health.donorId);
    query.bindValue(":date", health.date);
    query.bindValue(":weight", health.weight);
    query.bindValue(":bloodPressure", health.bloodPressure);
    query.bindValue(":sugarLevel", health.sugarLevel);
    query.bindValue(":startTime", health.startTime);
    query.bindValue(":endTime", health.endTime);
    if (!query.exec()) {
        qDebug() << "Add health history failed:" << query.lastError().text();
        return false;
    }
    return true;
}
