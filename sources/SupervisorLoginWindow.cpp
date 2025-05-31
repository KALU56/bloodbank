#include "SupervisorLoginWindow.h"
#include "ui_SupervisorLoginWindow.h"
#include "SupervisorChoiceWindow.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QDebug>
#include "WelcomeWindow.h"

SupervisorLoginWindow::SupervisorLoginWindow(DatabaseManager* db, WelcomeWindow* parent)
    : QWidget(parent),
    ui(new Ui::SupervisorLoginWindow),
    dbManager(db),
    choiceWindow(nullptr),
    welcomeWindow(parent) {
    qDebug() << "Starting SupervisorLoginWindow constructor";
    try {
        ui->setupUi(this);
        qDebug() << "UI setup completed successfully";
    } catch (const std::exception& e) {
        qDebug() << "UI setup failed:" << e.what();
        QMessageBox::critical(this, "UI Error", "Failed to initialize UI: " + QString(e.what()));
        throw;
    }

    connect(ui->loginButton, &QPushButton::clicked, this, &SupervisorLoginWindow::on_loginButton_clicked);
    connect(ui->backButton, &QPushButton::clicked, this, &SupervisorLoginWindow::on_backButton_clicked);
    qDebug() << "SupervisorLoginWindow constructor completed";
}

SupervisorLoginWindow::~SupervisorLoginWindow() {
    qDebug() << "Destroying SupervisorLoginWindow";
    delete ui;
    delete choiceWindow;
}

void SupervisorLoginWindow::on_loginButton_clicked() {
    QString username = ui->usernameEdit->text().trimmed();
    QString password = ui->passwordEdit->text().trimmed();

    if (dbManager->supervisorLogin(username, password)) {
        qDebug() << "Login successful for" << username;
        if (!choiceWindow) {
            choiceWindow = new SupervisorChoiceWindow(username, dbManager, this);
        }
        choiceWindow->show();
        choiceWindow->raise();
        choiceWindow->activateWindow();
        this->hide();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}

void SupervisorLoginWindow::on_backButton_clicked() {
    if (welcomeWindow) {
        welcomeWindow->show();
        welcomeWindow->raise();
        welcomeWindow->activateWindow();
    }
    this->hide();
}

void SupervisorLoginWindow::closeEvent(QCloseEvent* event) {
    if (welcomeWindow) {
        welcomeWindow->show();
    }
    event->accept();
}
