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
    qDebug() << "Initializing WelcomeWindow";
    ui->setupUi(this);

    // Verify button existence
    if (!ui->donorButton || !ui->supervisorButton) {
        qDebug() << "Error: donorButton or supervisorButton is null";
        QMessageBox::critical(this, "UI Error", "Failed to initialize UI components.");
        return;
    }

    // Connect buttons
    connect(ui->donorButton, &QPushButton::clicked, this, &WelcomeWindow::onDonorButtonClicked);
    connect(ui->supervisorButton, &QPushButton::clicked, this, &WelcomeWindow::onSupervisorButtonClicked);

    // Connect to database
    if (!dbManager.connect()) {
        qDebug() << "Database connection failed";
        QMessageBox::critical(this, "Database Error", "Failed to connect to the database.");
    } else {
        qDebug() << "Database connected successfully";
    }
}

WelcomeWindow::~WelcomeWindow() {
    qDebug() << "Destroying WelcomeWindow";
    delete donorLoginWindow;
    delete supervisorLoginWindow;
    delete ui;
}

void WelcomeWindow::onDonorButtonClicked() {
    qDebug() << "Donor button clicked";
    if (!donorLoginWindow) {
        qDebug() << "Creating new DonorLoginWindow";
        donorLoginWindow = new DonorLoginWindow(&dbManager, this);
    }
    donorLoginWindow->show();
    donorLoginWindow->raise();
    donorLoginWindow->activateWindow();
    qDebug() << "DonorLoginWindow visible:" << donorLoginWindow->isVisible();
    this->hide();
}

void WelcomeWindow::onSupervisorButtonClicked() {
    qDebug() << "Supervisor button clicked";
    if (!supervisorLoginWindow) {
        qDebug() << "Creating new SupervisorLoginWindow";
        supervisorLoginWindow = new SupervisorLoginWindow(&dbManager, this);
    }
    supervisorLoginWindow->show();
    supervisorLoginWindow->raise();
    supervisorLoginWindow->activateWindow();
    qDebug() << "SupervisorLoginWindow visible:" << supervisorLoginWindow->isVisible();
    this->hide();
}
