// SupervisorDashboard.cpp
#include "SupervisorDashboard.h"
#include "ui_SupervisorDashboard.h"

SupervisorDashboard::SupervisorDashboard(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::SupervisorDashboard)
{
    ui->setupUi(this);

    connect(ui->loginButton, &QPushButton::clicked, this, &SupervisorDashboard::onLoginButtonClicked);
    connect(ui->viewDonorsButton, &QPushButton::clicked, this, &SupervisorDashboard::onViewDonorsButtonClicked);
    connect(ui->sendMedicalHistoryButton, &QPushButton::clicked, this, &SupervisorDashboard::onSendMedicalHistoryButtonClicked);
    connect(ui->sendHealthStatusButton, &QPushButton::clicked, this, &SupervisorDashboard::onSendHealthStatusButtonClicked);
    connect(ui->logoutButton, &QPushButton::clicked, this, &SupervisorDashboard::onLogoutButtonClicked);
    connect(ui->exitButton, &QPushButton::clicked, this, &SupervisorDashboard::onExitButtonClicked);
}

SupervisorDashboard::~SupervisorDashboard()
{
    delete ui;
}

void SupervisorDashboard::onLoginButtonClicked()
{
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();
    emit loginClicked(username, password);
}

void SupervisorDashboard::onViewDonorsButtonClicked() { emit viewDonorsClicked(); }
void SupervisorDashboard::onSendMedicalHistoryButtonClicked() { emit sendMedicalHistoryClicked(); }
void SupervisorDashboard::onSendHealthStatusButtonClicked() { emit sendHealthStatusClicked(); }
void SupervisorDashboard::onLogoutButtonClicked() { emit logoutClicked(); }
void SupervisorDashboard::onExitButtonClicked() { emit exitClicked(); }
