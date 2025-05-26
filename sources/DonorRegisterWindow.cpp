#include "DonorRegisterWindow.h"
#include "ui_DonorRegisterWindow.h"
#include <QMessageBox>

DonorRegisterWindow::DonorRegisterWindow(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::DonorRegisterWindow),
    dbManager(new DatabaseManager()),
    loginWindow(nullptr)
{
    ui->setupUi(this);
}

DonorRegisterWindow::~DonorRegisterWindow()
{
    delete ui;
    delete dbManager;
    delete loginWindow;
}

void DonorRegisterWindow::on_submitButton_clicked()
{
    Donor donor;
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
        QMessageBox::information(this, "Success", "Registration successful!");
        if (!loginWindow) {
            loginWindow = new DonorLoginWindow(this);
        }
        loginWindow->show();
        this->hide();
    } else {
        QMessageBox::warning(this, "Registration Failed", "Username already exists or database error.");
    }
}
