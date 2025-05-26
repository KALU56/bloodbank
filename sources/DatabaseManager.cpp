#include "DatabaseManager.h"

DatabaseManager::DatabaseManager()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("Blood_bank");  // Replace with your actual DB name
    db.setUserName("postgres");        // Replace with your DB username
    db.setPassword("kaluLILUYA#1");    // Replace with your DB password
}

DatabaseManager::~DatabaseManager()
{
    if (db.isOpen()) {
        db.close();
    }
}

bool DatabaseManager::connect()
{
    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return false;
    }
    qDebug() << "Database connected successfully!";
    return true;
}
