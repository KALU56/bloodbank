#include "DonorDashboardWindow.h"
#include "ui_DonorDashboardWindow.h"

DonorDashboardWindow::DonorDashboardWindow(const QString& username, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::DonorDashboardWindow),
    dbManager(new DatabaseManager()),
    username(username)
{
    ui->setupUi(this);
    loadMedicalHistory();
    loadHealthHistory();
}

DonorDashboardWindow::~DonorDashboardWindow()
{
    delete ui;
    delete dbManager;
}

void DonorDashboardWindow::loadMedicalHistory()
{
    Donor donor = dbManager->getDonorByUsername(username);
    QVector<MedicalHistory> history = dbManager->getMedicalHistory(donor.id);
    ui->medicalTable->setRowCount(history.size());
    ui->medicalTable->setColumnCount(5); // Ensure table has correct columns

    for (int i = 0; i < history.size(); ++i) {
        ui->medicalTable->setItem(i, 0, new QTableWidgetItem(history[i].hivStatus ? "Positive" : "Negative"));
        ui->medicalTable->setItem(i, 1, new QTableWidgetItem(history[i].syphilisStatus ? "Positive" : "Negative"));
        ui->medicalTable->setItem(i, 2, new QTableWidgetItem(history[i].hepatitisStatus ? "Positive" : "Negative"));
        ui->medicalTable->setItem(i, 3, new QTableWidgetItem(QString::number(history[i].sugarLevel)));
        ui->medicalTable->setItem(i, 4, new QTableWidgetItem(history[i].message));
    }
}

void DonorDashboardWindow::loadHealthHistory()
{
    Donor donor = dbManager->getDonorByUsername(username);
    QVector<HealthHistory> history = dbManager->getHealthHistory(donor.id);
    ui->healthTable->setRowCount(history.size());
    ui->healthTable->setColumnCount(6); // Ensure table has correct columns

    for (int i = 0; i < history.size(); ++i) {
        ui->healthTable->setItem(i, 0, new QTableWidgetItem(history[i].date));
        ui->healthTable->setItem(i, 1, new QTableWidgetItem(QString::number(history[i].weight)));
        ui->healthTable->setItem(i, 2, new QTableWidgetItem(history[i].bloodPressure));
        ui->healthTable->setItem(i, 3, new QTableWidgetItem(QString::number(history[i].sugarLevel)));
        ui->healthTable->setItem(i, 4, new QTableWidgetItem(history[i].startTime));
        ui->healthTable->setItem(i, 5, new QTableWidgetItem(history[i].endTime));
    }
}
