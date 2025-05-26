#include "WelcomeWindow.h"     // ✅ This matches your CMake setup
#include "ui_WelcomeWindow.h"
#include <QMessageBox>

WelcomeWindow::WelcomeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);

    // Attempt to connect to the database
    if (dbManager.connect()) {
        qDebug() << "Database connected successfully!";
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to connect to the database.");
    }
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}
