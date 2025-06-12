#include "DonorController.h"
#include <QDebug>

DonorController::DonorController(DonorDashboard* dashboard, QObject *parent)
    : QObject(parent), m_dashboard(dashboard)
{
    connect(m_dashboard, &DonorDashboard::registerClicked, this, &DonorController::onRegisterClicked);
    connect(m_dashboard, &DonorDashboard::loginClicked, this, &DonorController::onLoginClicked);
    connect(m_dashboard, &DonorDashboard::exitClicked, this, &DonorController::onExitClicked);
    connect(m_dashboard, &DonorDashboard::backClicked, this, &DonorController::onBackClicked);
}

void DonorController::onRegisterClicked() { qDebug() << "Register clicked"; }
void DonorController::onLoginClicked()    { qDebug() << "Login clicked"; }
void DonorController::onExitClicked()
{
    qDebug() << "Exit clicked";
    if (m_dashboard) m_dashboard->close();
}
void DonorController::onBackClicked()
{
    qDebug() << "Back clicked";
    emit backToMainMenu();
}
