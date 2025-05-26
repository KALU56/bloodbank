#include "SupervisorDashboardWindow.h"
#include "ui_SupervisorDashboardWindow.h"
#include <QMessageBox>

SupervisorDashboardWindow::SupervisorDashboardWindow(const QString &username, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::SupervisorDashboardWindow),
    dbManager(new DatabaseManager()),
    formsWindow(nullptr),
    loggedInUsername(username)  // Store the username
{
    ui->setupUi(this);

    // Initialize donor table
    ui->donorTable->setColumnCount(5);
    ui->donorTable->setHorizontalHeaderLabels({"Username", "Blood Type", "Region", "Woreda", "Kebele"});
    ui->donorTable->horizontalHeader()->setStretchLastSection(true);
}

SupervisorDashboardWindow::~SupervisorDashboardWindow()
{
    delete ui;
    delete dbManager;
    if (formsWindow) delete formsWindow;
}

void SupervisorDashboardWindow::on_searchButton_clicked()
{
    QString username = ui->searchEdit->text();
    Donor donor = dbManager->getDonorByUsername(username);

    if (donor.username.isEmpty()) {
        QMessageBox::warning(this, "Search Failed", "Donor not found.");
        ui->donorTable->setRowCount(0);
    } else {
        displayDonor(donor);
    }
}

void SupervisorDashboardWindow::on_formsButton_clicked()
{
    if (!formsWindow) {
        formsWindow = new SupervisorFormsWindow(this);
    }
    formsWindow->show();
    this->hide();
}

void SupervisorDashboardWindow::displayDonor(const Donor& donor)
{
    ui->donorTable->setRowCount(1);
    ui->donorTable->setItem(0, 0, new QTableWidgetItem(donor.username));
    ui->donorTable->setItem(0, 1, new QTableWidgetItem(donor.bloodType));
    ui->donorTable->setItem(0, 2, new QTableWidgetItem(donor.region));
    ui->donorTable->setItem(0, 3, new QTableWidgetItem(donor.woreda));
    ui->donorTable->setItem(0, 4, new QTableWidgetItem(donor.kebele));
}
