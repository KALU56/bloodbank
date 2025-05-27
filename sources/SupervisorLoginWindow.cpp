#include "SupervisorLoginWindow.h"
#include "ui_SupervisorLoginWindow.h"
#include <QMessageBox>
#include <QCloseEvent>

SupervisorLoginWindow::SupervisorLoginWindow(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::SupervisorLoginWindow),
    dbManager(new DatabaseManager()),
    dashboardWindow(nullptr)
{
    ui->setupUi(this);
}

SupervisorLoginWindow::~SupervisorLoginWindow()
{
    delete ui;
    delete dbManager;
    delete dashboardWindow;
}

void SupervisorLoginWindow::on_loginButton_clicked()
{
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();

    if (dbManager->supervisorLogin(username, password)) {
        if (!dashboardWindow) {
            dashboardWindow = new SupervisorDashboardWindow(username, this);
        }
        dashboardWindow->show();
        this->hide();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}

void SupervisorLoginWindow::closeEvent(QCloseEvent *event)
{
    if (parentWidget()) {
        parentWidget()->show();  // Re-show WelcomeWindow
    }
    event->accept();
}
