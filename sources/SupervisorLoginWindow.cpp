#include "SupervisorLoginWindow.h"
#include "ui_SupervisorLoginWindow.h"
#include "SupervisorChoiceWindow.h"
#include "WelcomeWindow.h"          // Added include
#include <QMessageBox>
#include <QCloseEvent>              // Added include
#include <QDebug>

SupervisorLoginWindow::SupervisorLoginWindow(DatabaseManager* db, WelcomeWindow* parent)
    : QWidget(parent),
    ui(new Ui::SupervisorLoginWindow),
    dbManager(db),
    choiceWindow(nullptr),
    welcomeWindow(parent) {
    qDebug() << "Initializing SupervisorLoginWindow";
    ui->setupUi(this);

    // Verify UI components
    if (!ui->loginButton || !ui->backButton || !ui->usernameEdit || !ui->passwordEdit) {
        qDebug() << "Error: One or more UI components are null";
        QMessageBox::critical(this, "UI Error", "Failed to initialize UI components.");
        return;
    }

    connect(ui->loginButton, &QPushButton::clicked, this, &SupervisorLoginWindow::on_loginButton_clicked);
    connect(ui->backButton, &QPushButton::clicked, this, &SupervisorLoginWindow::on_backButton_clicked);
    qDebug() << "SupervisorLoginWindow initialized successfully";
}

SupervisorLoginWindow::~SupervisorLoginWindow() {
    qDebug() << "Destroying SupervisorLoginWindow";
    delete choiceWindow;
    delete ui;
}

void SupervisorLoginWindow::on_loginButton_clicked() {
    qDebug() << "Supervisor login button clicked";
    QString username = ui->usernameEdit->text().trimmed();
    QString password = ui->passwordEdit->text().trimmed();

    if (username.isEmpty() || password.isEmpty()) {
        qDebug() << "Login failed: Username or password is empty";
        QMessageBox::warning(this, "Login Failed", "Please enter both username and password.");
        return;
    }

    if (dbManager->supervisorLogin(username, password)) {
        qDebug() << "Login successful for supervisor:" << username;
        if (!choiceWindow) {
            choiceWindow = new SupervisorChoiceWindow(username, dbManager, this);
        }
        choiceWindow->show();
        choiceWindow->raise();
        choiceWindow->activateWindow();
        this->hide();
    } else {
        qDebug() << "Login failed: Invalid credentials for" << username;
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}

void SupervisorLoginWindow::on_backButton_clicked() {
    qDebug() << "Supervisor login back button clicked";
    if (welcomeWindow) {
        welcomeWindow->show();
        welcomeWindow->raise();
        welcomeWindow->activateWindow();
    }
    this->hide();
}

void SupervisorLoginWindow::closeEvent(QCloseEvent* event) {
    qDebug() << "SupervisorLoginWindow close event";
    if (welcomeWindow) {
        welcomeWindow->show();
        welcomeWindow->raise();
        welcomeWindow->activateWindow();
    }
    event->accept();
}
