#ifndef SUPERVISORCONTROLLER_H
#define SUPERVISORCONTROLLER_H

#include <QObject>
#include "SupervisorDashboard.h"

class SupervisorController : public QObject
{
    Q_OBJECT

public:
    explicit SupervisorController(SupervisorDashboard *dashboard, QObject *parent = nullptr);

signals:
    void backToMainMenu();

private slots:
    void handleLogin(const QString &username, const QString &password);
    void handleViewDonors();
    void handleSendMedicalHistory();
    void handleSendHealthStatus();
    void handleLogout();
    void handleExit();

private:
    SupervisorDashboard *m_dashboard;
};

#endif // SUPERVISORCONTROLLER_H
