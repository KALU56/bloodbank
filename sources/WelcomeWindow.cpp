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
    // No need to delete donorLoginWindow or supervisorLoginWindow; managed by parent
}

void WelcomeWindow::onDonorButtonClicked() {
    qDebug() << "Donor button clicked";
    if (!donorLoginWindow) {
        qDebug() << "Creating new DonorLoginWindow";
        donorLoginWindow = new DonorLoginWindow(&dbManager, this);
    }
    qDebug() << "Showing DonorLoginWindow";
    donorLoginWindow->show();
    qDebug() << "Hiding WelcomeWindow";
    this->hide();
}

void WelcomeWindow::onSupervisorButtonClicked() {
    qDebug() << "Supervisor button clicked";
    if (!supervisorLoginWindow) {
        qDebug() << "Creating new SupervisorLoginWindow";
        supervisorLoginWindow = new SupervisorLoginWindow(&dbManager, this);
    }
    qDebug() << "Showing SupervisorLoginWindow";
    supervisorLoginWindow->show();
    qDebug() << "Hiding WelcomeWindow";
    this->hide();
}
