#ifndef SUPERVISORDASHBOARDWINDOW_H
#define SUPERVISORDASHBOARDWINDOW_H

#include <QWidget>
#include "DatabaseManager.h"
#include "Donor.h"

namespace Ui {
class SupervisorDashboardWindow;
}

class SupervisorFormsWindow;
class SupervisorChoiceWindow; // Forward declaration

class SupervisorDashboardWindow : public QWidget {
    Q_OBJECT

public:
    explicit SupervisorDashboardWindow(const QString& username, SupervisorChoiceWindow* parent = nullptr);
    ~SupervisorDashboardWindow();

private slots:
    void on_searchButton_clicked();
    void on_formsButton_clicked();
    void on_backButton_clicked();

private:
    void displayDonor(const Donor& donor);

    Ui::SupervisorDashboardWindow* ui;
    DatabaseManager* dbManager;
    SupervisorFormsWindow* formsWindow;
    QString loggedInUsername;
    SupervisorChoiceWindow* choiceWindow; // Reference to the parent choice window
};

#endif // SUPERVISORDASHBOARDWINDOW_H
