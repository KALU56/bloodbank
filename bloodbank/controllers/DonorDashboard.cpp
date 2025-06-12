#include "DonorDashboard.h"
#include "ui_DonorDashboard.h"

DonorDashboard::DonorDashboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DonorDashboard)
{
    ui->setupUi(this);

    connect(ui->registerButton, &QPushButton::clicked, this, &DonorDashboard::onRegisterButtonClicked);
    connect(ui->loginButton, &QPushButton::clicked, this, &DonorDashboard::onLoginButtonClicked);
    connect(ui->exitButton, &QPushButton::clicked, this, &DonorDashboard::onExitButtonClicked);
    connect(ui->backButton, &QPushButton::clicked, this, &DonorDashboard::onBackButtonClicked);
}

DonorDashboard::~DonorDashboard()
{
    delete ui;
}

void DonorDashboard::onRegisterButtonClicked() { emit registerClicked(); }
void DonorDashboard::onLoginButtonClicked()    { emit loginClicked(); }
void DonorDashboard::onExitButtonClicked()     { emit exitClicked(); }
void DonorDashboard::onBackButtonClicked()     { emit backClicked(); }
