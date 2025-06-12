 
#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QString>
#include <QDebug>

class DatabaseManager
{
public:
    static DatabaseManager& instance();  // Singleton pattern
    bool connect(const QString& host, int port,
                 const QString& dbname, const QString& user,
                 const QString& password);
    void disconnect();
    QSqlDatabase database() const;

private:
    DatabaseManager();  // Private constructor
    ~DatabaseManager();
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;

    QSqlDatabase m_db;
};

#endif // DATABASEMANAGER_H
