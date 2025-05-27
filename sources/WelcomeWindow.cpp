#include "WelcomeWindow.h"
#include "ui_WelcomeWindow.h"
#include <QMessageBox>
#include <QDebug>

WelcomeWindow::WelcomeWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::WelcomeWindow),
    donorLoginWindow(nullptr),
    supervisorLoginWindow(nullptr)
{
    ui->setupUi(this);

    // Attempt database connection
    if (dbManager.connect()) {
        qDebug() << "Database connected successfully!";
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to connect to the database.");
    }

    // Connect buttons to slots
    connect(ui->donorButton, &QPushButton::clicked, this, &WelcomeWindow::onDonorButtonClicked);
    connect(ui->supervisorButton, &QPushButton::clicked, this, &WelcomeWindow::onSupervisorButtonClicked);
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::onDonorButtonClicked()
{
    if (!donorLoginWindow) {
        donorLoginWindow = new DonorLoginWindow(this);  // Set parent
    }
    donorLoginWindow->show();
    this->hide();
}

void WelcomeWindow::onSupervisorButtonClicked()
{
    if (!supervisorLoginWindow) {
        supervisorLoginWindow = new SupervisorLoginWindow(this);  // Set parent
    }
    supervisorLoginWindow->show();
    this->hide();
}
