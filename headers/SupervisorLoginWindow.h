#ifndef SUPERVISORLOGINWINDOW_H
#define SUPERVISORLOGINWINDOW_H

#include <QWidget>
#include "DatabaseManager.h"
#include "SupervisorDashboardWindow.h"

namespace Ui {
class SupervisorLoginWindow;
}

class SupervisorLoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SupervisorLoginWindow(QWidget *parent = nullptr);
    ~SupervisorLoginWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_loginButton_clicked();

private:
    Ui::SupervisorLoginWindow *ui;
    DatabaseManager *dbManager;
    SupervisorDashboardWindow *dashboardWindow;
};

#endif // SUPERVISORLOGINWINDOW_H
