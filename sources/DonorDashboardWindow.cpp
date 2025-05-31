#include "DonorDashboardWindow.h"
#include "ui_DonorDashboardWindow.h"
#include "DonorLoginWindow.h"

DonorDashboardWindow::DonorDashboardWindow(const QString& username, DonorLoginWindow* parent)
    : QWidget(parent),
    ui(new Ui::DonorDashboardWindow),
    dbManager(new DatabaseManager()),
    username(username),
    loginWindow(parent) {
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::clicked, this, &DonorDashboardWindow::on_backButton_clicked);
    loadMedicalHistory();
    loadHealthHistory();
}

DonorDashboardWindow::~DonorDashboardWindow() {
    delete ui;
    delete dbManager;
}

void DonorDashboardWindow::on_backButton_clicked() {
    if (loginWindow) {
        loginWindow->show();
        loginWindow->raise();
        loginWindow->activateWindow();
    }
    this->hide();
}

void DonorDashboardWindow::loadMedicalHistory() {
    Donor donor = dbManager->getDonorByUsername(username);
    QVector<MedicalHistory> history = dbManager->getMedicalHistory(donor.id);
    ui->medicalTable->setRowCount(history.size());
    ui->medicalTable->setColumnCount(5);
    ui->medicalTable->setHorizontalHeaderLabels({"HIV Status", "Syphilis Status", "Hepatitis Status", "Sugar Level", "Message"});

    for (int i = 0; i < history.size(); ++i) {
        ui->medicalTable->setItem(i, 0, new QTableWidgetItem(history[i].hivStatus ? "Positive" : "Negative"));
        ui->medicalTable->setItem(i, 1, new QTableWidgetItem(history[i].syphilisStatus ? "Positive" : "Negative"));
        ui->medicalTable->setItem(i, 2, new QTableWidgetItem(history[i].hepatitisStatus ? "Positive" : "Negative"));
        ui->medicalTable->setItem(i, 3, new QTableWidgetItem(QString::number(history[i].sugarLevel)));
        ui->medicalTable->setItem(i, 4, new QTableWidgetItem(history[i].message));
    }
}

void DonorDashboardWindow::loadHealthHistory() {
    Donor donor = dbManager->getDonorByUsername(username);
    QVector<HealthHistory> history = dbManager->getHealthHistory(donor.id);
    ui->healthTable->setRowCount(history.size());
    ui->healthTable->setColumnCount(6);
    ui->healthTable->setHorizontalHeaderLabels({"Date", "Weight", "Blood Pressure", "Sugar Level", "Start Time", "End Time"});

    for (int i = 0; i < history.size(); ++i) {
        ui->healthTable->setItem(i, 0, new QTableWidgetItem(history[i].date));
        ui->healthTable->setItem(i, 1, new QTableWidgetItem(QString::number(history[i].weight)));
        ui->healthTable->setItem(i, 2, new QTableWidgetItem(history[i].bloodPressure));
        ui->healthTable->setItem(i, 3, new QTableWidgetItem(QString::number(history[i].sugarLevel)));
        ui->healthTable->setItem(i, 4, new QTableWidgetItem(history[i].startTime));
        ui->healthTable->setItem(i, 5, new QTableWidgetItem(history[i].endTime));
    }
}
