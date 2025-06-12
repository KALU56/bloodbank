#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "DonorDashboard.h"
#include "DonorController.h"
#include "SupervisorDashboard.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    donorDashboard(new DonorDashboard(this)),
    donorController(new DonorController(donorDashboard, this)),
    supervisorDashboard(new SupervisorDashboard(this))
{
    ui->setupUi(this);

    // Add dashboards to the stacked widget
    ui->stackedWidget->addWidget(donorDashboard);         // index 0
    ui->stackedWidget->addWidget(supervisorDashboard);    // index 1

    // Connect donorController's back signal
    connect(donorController, &DonorController::backToMainMenu, this, [this]() {
        ui->stackedWidget->setCurrentIndex(0); // Back to donor dashboard or main menu
    });

    // Connect buttons in main window to switch views
    connect(ui->donorButton, &QPushButton::clicked, this, &MainWindow::showDonorDashboard);
    connect(ui->supervisorButton, &QPushButton::clicked, this, &MainWindow::showSupervisorDashboard);

    // Start with donor dashboard (or change index if you have a main menu)
    ui->stackedWidget->setCurrentWidget(donorDashboard);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showDonorDashboard()
{
    ui->stackedWidget->setCurrentWidget(donorDashboard);
}

void MainWindow::showSupervisorDashboard()
{
    ui->stackedWidget->setCurrentWidget(supervisorDashboard);
}
