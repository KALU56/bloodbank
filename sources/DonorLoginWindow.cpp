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
    dashboardWindow(nullptr)
{
    qDebug() << "Starting DonorLoginWindow constructor";
    ui->setupUi(this);
    connect(ui->loginButton, &QPushButton::clicked, this, &DonorLoginWindow::onLoginButtonClicked);
    connect(ui->registerButton, &QPushButton::clicked, this, &DonorLoginWindow::onRegisterButtonClicked);
    qDebug() << "DonorLoginWindow constructor completed";
}

DonorLoginWindow::~DonorLoginWindow() {
    delete ui;
}

void DonorLoginWindow::onLoginButtonClicked() {
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();

    if (dbManager->donorLogin(username, password)) {
        qDebug() << "Login successful for" << username;
        if (!dashboardWindow) {
            dashboardWindow = new DonorDashboardWindow(username, this);
        }
        dashboardWindow->show();
        this->hide();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}

void DonorLoginWindow::onRegisterButtonClicked() {
    qDebug() << "Register button clicked";
    if (!registerWindow) {
        qDebug() << "Creating new DonorRegisterWindow";
        registerWindow = new DonorRegisterWindow(this);
    }
    qDebug() << "Showing DonorRegisterWindow";
    registerWindow->show();
    this->hide();
}

void DonorLoginWindow::closeEvent(QCloseEvent* event) {
    if (parentWidget()) {
        parentWidget()->show();  // Re-show WelcomeWindow when this closes
    }
    event->accept();
}
