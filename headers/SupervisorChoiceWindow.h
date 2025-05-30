#ifndef SUPERVISORCHOICEWINDOW_H
#define SUPERVISORCHOICEWINDOW_H

#include <QWidget>
#include "DatabaseManager.h"

namespace Ui {
class SupervisorChoiceWindow;
}

class SupervisorDashboardWindow;
class SupervisorFormsWindow;

class SupervisorChoiceWindow : public QWidget {
    Q_OBJECT

public:
    explicit SupervisorChoiceWindow(const QString& username, DatabaseManager* db, QWidget* parent = nullptr);
    ~SupervisorChoiceWindow();

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void on_dashboardButton_clicked();
    void on_formsButton_clicked();

private:
    Ui::SupervisorChoiceWindow* ui;
    DatabaseManager* dbManager;
    QString loggedInUsername;
    SupervisorDashboardWindow* dashboardWindow;
    SupervisorFormsWindow* formsWindow;
};

#endif // SUPERVISORCHOICEWINDOW_H
