#ifndef SUPERVISORDASHBOARDWINDOW_H
#define SUPERVISORDASHBOARDWINDOW_H

#include <QWidget>
#include "DatabaseManager.h"
#include "Donor.h"

namespace Ui {
class SupervisorDashboardWindow;
}

class SupervisorFormsWindow; // Forward declaration

class SupervisorDashboardWindow : public QWidget {
    Q_OBJECT

public:
    explicit SupervisorDashboardWindow(const QString& username, QWidget* parent = nullptr);
    ~SupervisorDashboardWindow();

private slots:
    void on_searchButton_clicked();
    void on_formsButton_clicked();

private:
    void displayDonor(const Donor& donor);

    Ui::SupervisorDashboardWindow* ui;
    DatabaseManager* dbManager;
    SupervisorFormsWindow* formsWindow;
    QString loggedInUsername;
};

#endif // SUPERVISORDASHBOARDWINDOW_H
