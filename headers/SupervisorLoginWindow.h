#ifndef SUPERVISORLOGINWINDOW_H #define SUPERVISORLOGINWINDOW_H

#include #include "DatabaseManager.h" #include "SupervisorDashboardWindow.h"

namespace Ui { class SupervisorLoginWindow; }

class SupervisorLoginWindow : public QWidget { Q_OBJECT

public: explicit SupervisorLoginWindow(QWidget *parent = nullptr); ~SupervisorLoginWindow();

private slots: void on_loginButton_clicked();

private: Ui::SupervisorLoginWindow *ui; DatabaseManager *dbManager; SupervisorDashboardWindow *dashboardWindow; };

#endif // SUPERVISORLOGINWINDOW_H
