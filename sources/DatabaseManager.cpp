#include "DatabaseManager.h"
#include <QSqlError>        // Essential for retrieving detailed database error messages
#include <QCoreApplication> // Useful for getting application paths, though not directly used for DB connection here

DatabaseManager::DatabaseManager()
{
    // Add a PostgreSQL database connection. "QPSQL" is the driver name for PostgreSQL.
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");          // Your PostgreSQL server's host (e.g., "localhost", "192.168.1.100")
    db.setDatabaseName("Blood_bank");     // The name of the database you created in PostgreSQL
    db.setUserName("postgres");           // Your PostgreSQL username
    db.setPassword("kaluLILUYA#1");       // Your PostgreSQL password
}

DatabaseManager::~DatabaseManager()
{
    // If the database connection is open, close it gracefully on destruction
    if (db.isOpen()) {
        db.close();
    }
    // Note: If you used QSqlDatabase::addDatabase("QPSQL", "YourConnectionName"),
    // you might also call QSqlDatabase::removeDatabase("YourConnectionName"); here.
    // Since you're not explicitly naming the connection, it's the default one.
}

bool DatabaseManager::connect()
{
    // Attempt to open the database connection
    if (!db.open()) {
        // If opening fails, print a detailed error message to the console
        qDebug() << "Database connection failed:" << db.lastError().text();
        return false; // Indicate connection failure
    }
    qDebug() << "Database connected successfully!";
    return true; // Indicate successful connection
}
