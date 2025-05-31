#include "SupervisorDashboardWindow.h"
#include "ui_SupervisorDashboardWindow.h"
#include <QMessageBox>
#include "SupervisorFormsWindow.h"
#include "SupervisorChoiceWindow.h"

SupervisorDashboardWindow::SupervisorDashboardWindow(const QString& username, SupervisorChoiceWindow* parent)
    : QWidget(parent),
    ui(new Ui::SupervisorDashboardWindow),
    dbManager(new DatabaseManager()),
    formsWindow(nullptr),
    loggedInUsername(username),
    choiceWindow(parent) {
    ui->setupUi(this);

    ui->donorTable->setColumnCount(5);
    ui->donorTable->setHorizontalHeaderLabels({"Username", "Blood Type", "Region", "Woreda", "Kebele"});
    ui->donorTable->horizontalHeader()->setStretchLastSection(true);

    // Connect buttons to their slots
    connect(ui->searchButton, &QPushButton::clicked, this, &SupervisorDashboardWindow::on_searchButton_clicked);
    connect(ui->formsButton, &QPushButton::clicked, this, &SupervisorDashboardWindow::on_formsButton_clicked);
    connect(ui->backButton, &QPushButton::clicked, this, &SupervisorDashboardWindow::on_backButton_clicked);
}

SupervisorDashboardWindow::~SupervisorDashboardWindow() {
    delete ui;
    delete dbManager;
    if (formsWindow) delete formsWindow;
}

void SupervisorDashboardWindow::on_searchButton_clicked() {
    QString username = ui->searchEdit->text();
    Donor donor = dbManager->getDonorByUsername(username);

    if (donor.username.isEmpty()) {
        QMessageBox::warning(this, "Search Failed", "Donor not found.");
        ui->donorTable->setRowCount(0);
    } else {
        displayDonor(donor);
    }
}

void SupervisorDashboardWindow::on_formsButton_clicked() {
    if (!formsWindow) {
        // Pass 'this' as parent so the form window can return directly to the dashboard if needed
        formsWindow = new SupervisorFormsWindow(this);
    }
    formsWindow->show();
    formsWindow->raise();
    formsWindow->activateWindow();
    this->hide();  // Hide dashboard window
}

void SupervisorDashboardWindow::on_backButton_clicked() {
    if (choiceWindow) {
        choiceWindow->show();
        choiceWindow->raise();
        choiceWindow->activateWindow();
    }
    this->hide();  // Hide dashboard window
}

void SupervisorDashboardWindow::displayDonor(const Donor& donor) {
    ui->donorTable->setRowCount(1);
    ui->donorTable->setItem(0, 0, new QTableWidgetItem(donor.username));
    ui->donorTable->setItem(0, 1, new QTableWidgetItem(donor.bloodType));
    ui->donorTable->setItem(0, 2, new QTableWidgetItem(donor.region));
    ui->donorTable->setItem(0, 3, new QTableWidgetItem(donor.woreda));
    ui->donorTable->setItem(0, 4, new QTableWidgetItem(donor.kebele));
}
