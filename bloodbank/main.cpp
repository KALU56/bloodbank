#include <QApplication>
#include "db/DatabaseManager.h"
#include "controllers/MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Connect to PostgreSQL
    if (!DatabaseManager::instance().connect("localhost", 5432, "Blood_bank", "postgres", "kaluLILUYA#1")) {
        qDebug() << "Cannot start application: Database connection failed.";
        return -1;
    }


    MainWindow w;
    w.show();

    return app.exec();
}
