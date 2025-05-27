#include "SupervisorFormsWindow.h"
#include "ui_SupervisorFormsWindow.h"
#include <QMessageBox>

SupervisorFormsWindow::SupervisorFormsWindow(QWidget* parent)
    : QWidget(parent),
    ui(new Ui::SupervisorFormsWindow),
    dbManager(new DatabaseManager()) {
    ui->setupUi(this);
    connect(ui->medicalSubmitButton, &QPushButton::clicked, this, &SupervisorFormsWindow::on_medicalSubmitButton_clicked);
    connect(ui->healthSubmitButton, &QPushButton::clicked, this, &SupervisorFormsWindow::on_healthSubmitButton_clicked);
}

SupervisorFormsWindow::~SupervisorFormsWindow() {
    delete ui;
    delete dbManager;
}

void SupervisorFormsWindow::on_medicalSubmitButton_clicked() {
    QString username = ui->medicalUsernameEdit->text();
    Donor donor = dbManager->getDonorByUsername(username);

    if (donor.username.isEmpty()) {
        QMessageBox::warning(this, "Submission Failed", "Donor not found.");
        return;
    }

    MedicalHistory medical;
    medical.donorId = donor.id;
    medical.hivStatus = ui->hivCheckBox->isChecked();
    medical.syphilisStatus = ui->syphilisCheckBox->isChecked();
    medical.hepatitisStatus = ui->hepatitisCheckBox->isChecked();
    medical.sugarLevel = ui->sugarLevelEdit->text().toFloat();
    medical.message = ui->messageEdit->toPlainText();

    if (dbManager->addMedicalHistory(medical)) {
        QMessageBox::information(this, "Success", "Medical history submitted.");
        ui->medicalUsernameEdit->clear();
        ui->hivCheckBox->setChecked(false);
        ui->syphilisCheckBox->setChecked(false);
        ui->hepatitisCheckBox->setChecked(false);
        ui->sugarLevelEdit->clear();
        ui->messageEdit->clear();
    } else {
        QMessageBox::warning(this, "Submission Failed", "Database error.");
    }
}

void SupervisorFormsWindow::on_healthSubmitButton_clicked() {
    QString username = ui->healthUsernameEdit->text();
    Donor donor = dbManager->getDonorByUsername(username);

    if (donor.username.isEmpty()) {
        QMessageBox::warning(this, "Submission Failed", "Donor not found.");
        return;
    }

    HealthHistory health;
    health.donorId = donor.id;
    health.date = ui->dateEdit->text();
    health.weight = ui->weightEdit->text().toFloat();
    health.bloodPressure = ui->bloodPressureEdit->text();
    health.sugarLevel = ui->healthSugarLevelEdit->text().toFloat();
    health.startTime = ui->startTimeEdit->text();
    health.endTime = ui->endTimeEdit->text();

    if (dbManager->addHealthHistory(health)) {
        QMessageBox::information(this, "Success", "Health history submitted.");
        ui->healthUsernameEdit->clear();
        ui->dateEdit->clear();
        ui->weightEdit->clear();
        ui->bloodPressureEdit->clear();
        ui->healthSugarLevelEdit->clear();
        ui->startTimeEdit->clear();
        ui->endTimeEdit->clear();
    } else {
        QMessageBox::warning(this, "Submission Failed", "Database error.");
    }
}
