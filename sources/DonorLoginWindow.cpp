#include "DonorLoginWindow.h"
#include "ui_DonorLoginWindow.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QDebug>
#include "DonorRegisterWindow.h"
#include "DonorDashboardWindow.h"

DonorLoginWindow::DonorLoginWindow(DatabaseManager* db, QWidget* parent)
    : QWidget(parent),
    ui(new Ui::DonorLoginWindow),
    dbManager(db),
    registerWindow(nullptr),
    dashboardWindow(nullptr) {
    qDebug() << "Starting DonorLoginWindow constructor";
    try {
        ui->setupUi(this);
        qDebug() << "UI setup completed successfully";
    } catch (const std::exception& e) {
        qDebug() << "UI setup failed:" << e.what();
        QMessageBox::critical(this, "UI Error", "Failed to initialize UI: " + QString(e.what()));
        throw;
    }

    qDebug() << "Setting up signal-slot connections";
    connect(ui->loginButton, &QPushButton::clicked, this, &DonorLoginWindow::on_loginButton_clicked);
    connect(ui->registerButton, &QPushButton::clicked, this, &DonorLoginWindow::on_registerButton_clicked);
    qDebug() << "DonorLoginWindow constructor completed";
}

DonorLoginWindow::~DonorLoginWindow() {
    qDebug() << "Destroying DonorLoginWindow";
    delete ui;
    // Do not delete dbManager; it is shared
}

void DonorLoginWindow::on_loginButton_clicked() {
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();

    if (dbManager->donorLogin(username, password)) {
        if (!dashboardWindow) {
            dashboardWindow = new DonorDashboardWindow(username, this);
        }
        dashboardWindow->show();
        this->hide();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}

void DonorLoginWindow::on_registerButton_clicked() {
    if (!registerWindow) {
        registerWindow = new DonorRegisterWindow(this);
    }
    registerWindow->show();
    this->hide();
}

void DonorLoginWindow::closeEvent(QCloseEvent* event) {
    if (parentWidget()) {
        parentWidget()->show();
    }
    event->accept();
}
