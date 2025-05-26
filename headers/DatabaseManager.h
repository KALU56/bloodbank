#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QDebug>

class DatabaseManager
{
public:
    DatabaseManager();
    ~DatabaseManager();

    bool connect();

private:
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
