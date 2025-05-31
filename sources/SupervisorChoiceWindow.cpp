#include "SupervisorChoiceWindow.h"
#include "ui_SupervisorChoiceWindow.h"
#include "SupervisorDashboardWindow.h"
#include "SupervisorFormsWindow.h"
#include "SupervisorLoginWindow.h"
#include <QDebug>
#include <QCloseEvent>              // Added include

SupervisorChoiceWindow::SupervisorChoiceWindow(const QString& username, DatabaseManager* db, SupervisorLoginWindow* parent)
    : QWidget(parent),
    ui(new Ui::SupervisorChoiceWindow),
    dbManager(db),
    loggedInUsername(username),
    dashboardWindow(nullptr),
    formsWindow(nullptr),
    loginWindow(parent) {
    qDebug() << "Initializing SupervisorChoiceWindow for user:" << username;
    ui->setupUi(this);

    if (!ui->dashboardButton || !ui->formsButton || !ui->backButton) {
        qDebug() << "Error: One or more UI components are null";
        return;
    }

    connect(ui->dashboardButton, &QPushButton::clicked, this, &SupervisorChoiceWindow::on_dashboardButton_clicked);
    connect(ui->formsButton, &QPushButton::clicked, this, &SupervisorChoiceWindow::on_formsButton_clicked);
    connect(ui->backButton, &QPushButton::clicked, this, &SupervisorChoiceWindow::on_backButton_clicked);
}

SupervisorChoiceWindow::~SupervisorChoiceWindow() {
    qDebug() << "Destroying SupervisorChoiceWindow";
    delete dashboardWindow;
    delete formsWindow;
    delete ui;
}

void SupervisorChoiceWindow::on_dashboardButton_clicked() {
    qDebug() << "Dashboard button clicked";
    if (!dashboardWindow) {
        dashboardWindow = new SupervisorDashboardWindow(loggedInUsername, this);
    }
    dashboardWindow->show();
    dashboardWindow->raise();
    dashboardWindow->activateWindow();
    this->hide();
}

void SupervisorChoiceWindow::on_formsButton_clicked() {
    qDebug() << "Forms button clicked";
    if (!formsWindow) {
        formsWindow = new SupervisorFormsWindow(this);
    }
    formsWindow->show();
    formsWindow->raise();
    formsWindow->activateWindow();
    this->hide();
}

void SupervisorChoiceWindow::on_backButton_clicked() {
    qDebug() << "Supervisor choice back button clicked";
    if (loginWindow) {
        loginWindow->show();
        loginWindow->raise();
        loginWindow->activateWindow();
    }
    this->hide();
}

void SupervisorChoiceWindow::closeEvent(QCloseEvent* event) {
    qDebug() << "SupervisorChoiceWindow close event";
    if (loginWindow) {
        loginWindow->show();
        loginWindow->raise();
        loginWindow->activateWindow();
    }
    event->accept();
}
