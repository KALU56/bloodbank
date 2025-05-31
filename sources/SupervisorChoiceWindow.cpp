#include "SupervisorChoiceWindow.h"
#include "ui_SupervisorChoiceWindow.h"
#include "SupervisorDashboardWindow.h"
#include "SupervisorFormsWindow.h"
#include "SupervisorLoginWindow.h"
#include <QDebug>

SupervisorChoiceWindow::SupervisorChoiceWindow(const QString& username, DatabaseManager* db, SupervisorLoginWindow* parent)
    : QWidget(parent),
    ui(new Ui::SupervisorChoiceWindow),
    dbManager(db),
    loggedInUsername(username),
    dashboardWindow(nullptr),
    formsWindow(nullptr),
    loginWindow(parent) {
    ui->setupUi(this);
    connect(ui->dashboardButton, &QPushButton::clicked, this, &SupervisorChoiceWindow::on_dashboardButton_clicked);
    connect(ui->formsButton, &QPushButton::clicked, this, &SupervisorChoiceWindow::on_formsButton_clicked);
    connect(ui->backButton, &QPushButton::clicked, this, &SupervisorChoiceWindow::on_backButton_clicked);
}

SupervisorChoiceWindow::~SupervisorChoiceWindow() {
    delete ui;
}

void SupervisorChoiceWindow::on_dashboardButton_clicked() {
    if (!dashboardWindow) {
        dashboardWindow = new SupervisorDashboardWindow(loggedInUsername, this); // ✅ Fix here
    }
    dashboardWindow->show();
    this->hide();
}



void SupervisorChoiceWindow::on_formsButton_clicked() {
    if (!formsWindow) {
        formsWindow = new SupervisorFormsWindow(this);
    }
    formsWindow->show();
    this->hide();
}

void SupervisorChoiceWindow::on_backButton_clicked() {
    if (loginWindow) {
        loginWindow->show();
        loginWindow->raise();
        loginWindow->activateWindow();
    }
    this->hide();
}

void SupervisorChoiceWindow::closeEvent(QCloseEvent* event) {
    if (loginWindow) {
        loginWindow->show();
    }
    QWidget::closeEvent(event);
}
