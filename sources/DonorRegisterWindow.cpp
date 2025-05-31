#include "DonorRegisterWindow.h"
#include "ui_DonorRegisterWindow.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QUuid>
#include "DonorLoginWindow.h"

DonorRegisterWindow::DonorRegisterWindow(DatabaseManager* db, DonorLoginWindow* parent)
    : QWidget(parent),
    ui(new Ui::DonorRegisterWindow),
    dbManager(db),
    loginWindow(parent)
{
    ui->setupUi(this);
    connect(ui->submitButton, &QPushButton::clicked, this, &DonorRegisterWindow::on_submitButton_clicked);
    connect(ui->backButton, &QPushButton::clicked, this, &DonorRegisterWindow::on_backButton_clicked);
}

DonorRegisterWindow::~DonorRegisterWindow() {
    delete ui;
}

void DonorRegisterWindow::on_submitButton_clicked() {
    Donor donor;
    donor.id = QUuid::createUuid().toString(QUuid::WithoutBraces);
    donor.firstName = ui->firstNameEdit->text();
    donor.lastName = ui->lastNameEdit->text();
    donor.gender = ui->genderCombo->currentText();
    donor.phone = ui->phoneEdit->text();
    donor.username = ui->usernameEdit->text();
    donor.bloodType = ui->bloodTypeCombo->currentText();
    donor.region = ui->regionEdit->text();
    donor.woreda = ui->woredaEdit->text();
    donor.kebele = ui->kebeleEdit->text();
    donor.city = ui->cityEdit->text();
    QString password = ui->passwordEdit->text();

    if (donor.firstName.isEmpty() || donor.lastName.isEmpty() || donor.username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Registration Failed", "Please fill in all required fields.");
        return;
    }

    if (dbManager->registerDonor(donor, password)) {
        QMessageBox::information(this, "Success", "Registration successful! Please log in.");
        if (loginWindow) {
            loginWindow->show();
            loginWindow->raise();
            loginWindow->activateWindow();
        }
        this->hide();
    } else {
        QMessageBox::warning(this, "Registration Failed", "Username already exists or database error.");
    }
}

void DonorRegisterWindow::on_backButton_clicked() {
    if (loginWindow) {
        loginWindow->show();
        loginWindow->raise();
        loginWindow->activateWindow();
    }
    this->hide();
}

void DonorRegisterWindow::closeEvent(QCloseEvent* event) {
    if (loginWindow) {
        loginWindow->show();
    }
    event->accept();
}
