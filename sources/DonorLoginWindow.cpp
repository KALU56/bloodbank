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
            dashboardWindow = new DonorDashboardWindow(username, nullptr);  // No parent to make it independent
        }
        dashboardWindow->show();
        dashboardWindow->raise();
        dashboardWindow->activateWindow();
        this->hide();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}

void DonorLoginWindow::onRegisterButtonClicked() {
    qDebug() << "Register button clicked";
    if (!registerWindow) {
        qDebug() << "Creating new DonorRegisterWindow";
        registerWindow = new DonorRegisterWindow(dbManager, nullptr);  // Use nullptr to make it a top-level window
    }
    qDebug() << "Showing DonorRegisterWindow";
    registerWindow->show();
    registerWindow->raise();
    registerWindow->activateWindow();
    qDebug() << "DonorRegisterWindow visible:" << registerWindow->isVisible();
    this->hide();
}

void DonorLoginWindow::closeEvent(QCloseEvent* event) {
    if (parentWidget()) {
        parentWidget()->show();
    }
    event->accept();
}
