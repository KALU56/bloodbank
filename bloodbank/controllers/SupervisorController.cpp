 
#include "SupervisorController.h"
#include <QDebug>
#include <QMessageBox>

SupervisorController::SupervisorController(SupervisorDashboard *dashboard, QObject *parent)
    : QObject(parent), m_dashboard(dashboard)
{
    connect(m_dashboard, &SupervisorDashboard::loginClicked, this, &SupervisorController::handleLogin);
    connect(m_dashboard, &SupervisorDashboard::viewDonorsClicked, this, &SupervisorController::handleViewDonors);
    connect(m_dashboard, &SupervisorDashboard::sendMedicalHistoryClicked, this, &SupervisorController::handleSendMedicalHistory);
    connect(m_dashboard, &SupervisorDashboard::sendHealthStatusClicked, this, &SupervisorController::handleSendHealthStatus);
    connect(m_dashboard, &SupervisorDashboard::logoutClicked, this, &SupervisorController::handleLogout);
    connect(m_dashboard, &SupervisorDashboard::exitClicked, this, &SupervisorController::handleExit);
}

void SupervisorController::handleLogin(const QString &username, const QString &password)
{
    if (username == "sup1" && password == "sup123456") {
        QMessageBox::information(nullptr, "Login", "✅ Supervisor login successful!");
        // You might want to enable other buttons after successful login
    } else {
        QMessageBox::warning(nullptr, "Login Failed", "❌ Invalid username or password.");
    }
}

void SupervisorController::handleViewDonors() {
    qDebug() << "Viewing donors...";
    QMessageBox::information(nullptr, "View Donors", "Donor list displayed here.");
}

void SupervisorController::handleSendMedicalHistory() {
    qDebug() << "Sending medical history...";
    QMessageBox::information(nullptr, "Medical History", "Medical history sent successfully.");
}

void SupervisorController::handleSendHealthStatus() {
    qDebug() << "Sending health status...";
    QMessageBox::information(nullptr, "Health Status", "Health status sent successfully.");
}

void SupervisorController::handleLogout() {
    qDebug() << "Supervisor logged out.";
    emit backToMainMenu();
}

void SupervisorController::handleExit() {
    qDebug() << "Supervisor exiting app.";
    if (m_dashboard) m_dashboard->close();
}
