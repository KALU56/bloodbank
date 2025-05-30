#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QVector>
#include "Donor.h"
#include "MedicalHistory.h"
#include "HealthHistory.h"

class DatabaseManager {
public:
    // Singleton accessor (add this line)
    static DatabaseManager& instance();

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

    // Make the constructor/destructor private or protected for proper singleton
    // In your case, since the constructor is public, you might want to change it
    // But if you leave it public, be aware users can still create other instances.
};

#endif // DATABASEMANAGER_H
