#include "SupervisorChoiceWindow.h"
#include "ui_SupervisorChoiceWindow.h"
#include "SupervisorDashboardWindow.h"
#include "SupervisorFormsWindow.h"
#include <QCloseEvent>
#include <QDebug>
#include <cstddef>
SupervisorChoiceWindow::SupervisorChoiceWindow(const QString& username, DatabaseManager* db, QWidget* parent)
    : QWidget(parent),
    ui(new Ui::SupervisorChoiceWindow),
    dbManager(db),
    loggedInUsername(username),
    dashboardWindow(nullptr),
    formsWindow(nullptr) {
    qDebug() << "Starting SupervisorChoiceWindow constructor";
    ui->setupUi(this);
    connect(ui->dashboardButton, &QPushButton::clicked, this, &SupervisorChoiceWindow::on_dashboardButton_clicked);
    connect(ui->formsButton, &QPushButton::clicked, this, &SupervisorChoiceWindow::on_formsButton_clicked);
    qDebug() << "SupervisorChoiceWindow constructor completed";
}

SupervisorChoiceWindow::~SupervisorChoiceWindow() {
    delete ui;
    // Do not delete dbManager; it is shared
    delete dashboardWindow;
    delete formsWindow;
}

void SupervisorChoiceWindow::on_dashboardButton_clicked() {
    qDebug() << "Dashboard button clicked";
    if (!dashboardWindow) {
        dashboardWindow = new SupervisorDashboardWindow(loggedInUsername, nullptr);
    }
    dashboardWindow->show();
    dashboardWindow->raise();
    dashboardWindow->activateWindow();
    this->hide();
}

void SupervisorChoiceWindow::on_formsButton_clicked() {
    qDebug() << "Forms button clicked";
    if (!formsWindow) {
        formsWindow = new SupervisorFormsWindow(nullptr);
    }
    formsWindow->show();
    formsWindow->raise();
    formsWindow->activateWindow();
    this->hide();
}

void SupervisorChoiceWindow::closeEvent(QCloseEvent* event) {
    if (parentWidget()) {
        parentWidget()->show();
    }
    event->accept();
}
