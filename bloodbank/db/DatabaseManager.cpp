 
#include "DatabaseManager.h"

DatabaseManager::DatabaseManager()
{
    m_db = QSqlDatabase::addDatabase("QPSQL");  // PostgreSQL driver
}

DatabaseManager::~DatabaseManager()
{
    disconnect();
}

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager instance;
    return instance;
}

bool DatabaseManager::connect(const QString& host, int port,
                              const QString& dbname, const QString& user,
                              const QString& password)
{
    if (m_db.isOpen()) {
        return true;  // Already connected
    }

    m_db.setHostName(host);
    m_db.setPort(port);
    m_db.setDatabaseName(dbname);
    m_db.setUserName(user);
    m_db.setPassword(password);

    if (!m_db.open()) {
        qDebug() << "Failed to connect to database:" << m_db.lastError().text();
        return false;
    }

    qDebug() << "Database connection established!";
    return true;
}

void DatabaseManager::disconnect()
{
    if (m_db.isOpen()) {
        m_db.close();
        qDebug() << "Database connection closed.";
    }
}

QSqlDatabase DatabaseManager::database() const
{
    return m_db;
}
