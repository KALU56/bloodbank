#ifndef DONORLOGINWINDOW_H
#define DONORLOGINWINDOW_H

#include <QWidget>
#include "DatabaseManager.h"
#include "DonorRegisterWindow.h"
#include "DonorDashboardWindow.h"

namespace Ui {
class DonorLoginWindow;
}

class DonorLoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DonorLoginWindow(QWidget *parent = nullptr);
    ~DonorLoginWindow();

private slots:
    void on_loginButton_clicked();
    void on_registerButton_clicked();

private:
    Ui::DonorLoginWindow *ui;
    DatabaseManager *dbManager;
    DonorRegisterWindow *registerWindow;
    DonorDashboardWindow *dashboardWindow;
};

#endif // DONORLOGINWINDOW_H
