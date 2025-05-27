#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QVector>
#include "Donor.h"
#include "MedicalHistory.h"
#include "HealthHistory.h"

class DatabaseManager {
public:
    DatabaseManager();
    ~DatabaseManager();

    bool connect();
    bool donorLogin(const QString& username, const QString& password);
    bool supervisorLogin(const QString& username, const QString& password);
    bool registerDonor(const Donor& donor, const QString& password);
    Donor getDonorByUsername(const QString& username);
    QVector<MedicalHistory> getMedicalHistory(const QString& donorId);
    QVector<HealthHistory> getHealthHistory(const QString& donorId);
    bool addMedicalHistory(const MedicalHistory& medical);
    bool addHealthHistory(const HealthHistory& health);

private:
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
