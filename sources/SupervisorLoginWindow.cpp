```cpp
#include "SupervisorLoginWindow.h"
#include "ui_SupervisorLoginWindow.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QDebug>
#include "SupervisorChoiceWindow.h"

SupervisorLoginWindow::SupervisorLoginWindow(DatabaseManager* db, QWidget* parent)
    : QWidget(parent),
    ui(new Ui::SupervisorLoginWindow),
    dbManager(db),
    choiceWindow(nullptr) {
    qDebug() << "Starting SupervisorLoginWindow constructor";
    try {
        ui->setupUi(this);
        qDebug() << "UI setup completed successfully";
    } catch (const std::exception& e) {
        qDebug() << "UI setup failed:" << e.what();
        QMessageBox::critical(this, "UI Error", "Failed to initialize UI: " + QString(e.what()));
        throw;
    }

    qDebug() << "Setting up signal-slot connections";
    connect(ui->loginButton, &QPushButton::clicked, this, &SupervisorLoginWindow::on_loginButton_clicked);
    qDebug() << "SupervisorLoginWindow constructor completed";
}

SupervisorLoginWindow::~SupervisorLoginWindow() {
    qDebug() << "Destroying SupervisorLoginWindow";
    delete ui;
    // Do not delete dbManager; it is shared
    delete choiceWindow;
}

void SupervisorLoginWindow::on_loginButton_clicked() {
    QString username = ui->usernameEdit->text().trimmed();
    QString password = ui->passwordEdit->text().trimmed();

    if (dbManager->supervisorLogin(username, password)) {
        qDebug() << "Login successful for" << username;
        if (!choiceWindow) {
            choiceWindow = new SupervisorChoiceWindow(username, dbManager, nullptr);
        }
        choiceWindow->show();
        choiceWindow->raise();
        choiceWindow->activateWindow();
        this->hide();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}

void SupervisorLoginWindow::closeEvent(QCloseEvent* event) {
    if (parentWidget()) {
        parentWidget()->show();
    }
    event->accept();
}
```
