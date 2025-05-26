#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase> // Core Qt SQL class for database connections
#include <QDebug>       // For printing debug messages

class DatabaseManager
{
public:
    // Constructor: Initializes the database connection object
    DatabaseManager();
    // Destructor: Closes the database connection if it's open
    ~DatabaseManager();

    // Method to establish the database connection
    bool connect();

private:
    QSqlDatabase db; // The Qt SQL database object
};

#endif // DATABASEMANAGER_H
