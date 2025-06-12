#ifndef DONORCONTROLLER_H
#define DONORCONTROLLER_H

#include <QObject>
#include "DonorDashboard.h"

class DonorController : public QObject
{
    Q_OBJECT

public:
    explicit DonorController(DonorDashboard* dashboard, QObject *parent = nullptr);

signals:
    void backToMainMenu();

private slots:
    void onRegisterClicked();
    void onLoginClicked();
    void onExitClicked();
    void onBackClicked();

private:
    DonorDashboard* m_dashboard;
};

#endif // DONORCONTROLLER_H
