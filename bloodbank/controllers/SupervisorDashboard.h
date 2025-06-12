#ifndef SUPERVISORDASHBOARD_H
#define SUPERVISORDASHBOARD_H

#include <QWidget>

namespace Ui {
class SupervisorDashboard;
}

class SupervisorDashboard : public QWidget
{
    Q_OBJECT
public:
    explicit SupervisorDashboard(QWidget *parent = nullptr);
    ~SupervisorDashboard();

signals:
    void loginClicked(const QString &username, const QString &password);
    void viewDonorsClicked();
    void sendMedicalHistoryClicked();
    void sendHealthStatusClicked();
    void logoutClicked();
    void exitClicked();

private slots:
    void onLoginButtonClicked();
    void onViewDonorsButtonClicked();
    void onSendMedicalHistoryButtonClicked();
    void onSendHealthStatusButtonClicked();
    void onLogoutButtonClicked();
    void onExitButtonClicked();

private:
    Ui::SupervisorDashboard *ui;
};

#endif // SUPERVISORDASHBOARD_H
