#include "WelcomeWindow.h"
#include "ui_WelcomeWindow.h"
#include <QMessageBox>
#include <QDebug>

WelcomeWindow::WelcomeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WelcomeWindow),
    donorLoginWindow(nullptr),
    supervisorLoginWindow(nullptr)
{
    ui->setupUi(this);

    // Connect the database
    if (dbManager.connect()) {
        qDebug() << "Database connected successfully from WelcomeWindow!";
    } else {
        QMessageBox::critical(this, "Database Error",
                              "Failed to connect to the database. Please check the PostgreSQL server and credentials.");
    }

    // Connect buttons to their slots (if not using Qt Designer's automatic connections)
    connect(ui->donorButton, &QPushButton::clicked, this, &WelcomeWindow::on_donorButton_clicked);
    connect(ui->supervisorButton, &QPushButton::clicked, this, &WelcomeWindow::on_supervisorButton_clicked);
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
    delete donorLoginWindow;
    delete supervisorLoginWindow;
}

void WelcomeWindow::on_donorButton_clicked()
{
    if (!donorLoginWindow) {
        donorLoginWindow = new DonorLoginWindow(this);
    }
    donorLoginWindow->show();
    this->hide();
}

void WelcomeWindow::on_supervisorButton_clicked()
{
    if (!supervisorLoginWindow) {
        supervisorLoginWindow = new SupervisorLoginWindow(this);
    }
    supervisorLoginWindow->show();
    this->hide();
}
