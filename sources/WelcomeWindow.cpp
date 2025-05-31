#include "WelcomeWindow.h"
#include "ui_WelcomeWindow.h"
#include <QMessageBox>
#include <QDebug>
#include "DonorLoginWindow.h"
#include "SupervisorLoginWindow.h"

WelcomeWindow::WelcomeWindow(QWidget* parent)
    : QMainWindow(parent),
    ui(new Ui::WelcomeWindow),
    donorLoginWindow(nullptr),
    supervisorLoginWindow(nullptr) {
    ui->setupUi(this);
    if (dbManager.connect()) {
        qDebug() << "Database connected successfully!";
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to connect to the database.");
    }
    connect(ui->donorButton, &QPushButton::clicked, this, &WelcomeWindow::onDonorButtonClicked);
    connect(ui->supervisorButton, &QPushButton::clicked, this, &WelcomeWindow::onSupervisorButtonClicked);
}

WelcomeWindow::~WelcomeWindow() {
    delete ui;
}

void WelcomeWindow::onDonorButtonClicked() {
    qDebug() << "Donor button clicked";
    if (!donorLoginWindow || !donorLoginWindow->isVisible()) {
        qDebug() << "Creating new DonorLoginWindow";
        if (donorLoginWindow) delete donorLoginWindow; // 🔥 Clean up old instance
        donorLoginWindow = new DonorLoginWindow(&dbManager, this);
    }
    donorLoginWindow->show();
    donorLoginWindow->raise();
    donorLoginWindow->activateWindow();
    this->hide();
}

void WelcomeWindow::onSupervisorButtonClicked() {
    qDebug() << "Supervisor button clicked";
    if (!supervisorLoginWindow || !supervisorLoginWindow->isVisible()) {
        qDebug() << "Creating new SupervisorLoginWindow";
        if (supervisorLoginWindow) delete supervisorLoginWindow; // 🔥 Clean up old instance
        supervisorLoginWindow = new SupervisorLoginWindow(&dbManager, this);
    }
    supervisorLoginWindow->show();
    supervisorLoginWindow->raise();
    supervisorLoginWindow->activateWindow();
    this->hide();
}

