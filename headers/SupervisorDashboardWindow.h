#ifndef SUPERVISORDASHBOARDWINDOW_H #define SUPERVISORDASHBOARDWINDOW_H

#include #include "DatabaseManager.h" #include "SupervisorFormsWindow.h"

namespace Ui { class SupervisorDashboardWindow; }

class SupervisorDashboardWindow : public QWidget { Q_OBJECT

public: explicit SupervisorDashboardWindow(QWidget *parent = nullptr); ~SupervisorDashboardWindow();

private slots: void on_searchButton_clicked(); void on_formsButton_clicked();

private: void displayDonor(const Donor& donor);

    Ui::SupervisorDashboardWindow *ui;
    DatabaseManager *dbManager;
    SupervisorFormsWindow *formsWindow;

};

#endif // SUPERVISORDASHBOARDWINDOW_H
