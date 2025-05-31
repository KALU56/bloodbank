#ifndef SUPERVISORCHOICEWINDOW_H
#define SUPERVISORCHOICEWINDOW_H

#include <QWidget>
#include <QCloseEvent>
#include "DatabaseManager.h"

namespace Ui {
class SupervisorChoiceWindow;
}

class SupervisorDashboardWindow;
class SupervisorFormsWindow;
class SupervisorLoginWindow;

class SupervisorChoiceWindow : public QWidget {
    Q_OBJECT

public:
    explicit SupervisorChoiceWindow(const QString& username, DatabaseManager* db, SupervisorLoginWindow* parent = nullptr);
    ~SupervisorChoiceWindow();

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void on_dashboardButton_clicked();
    void on_formsButton_clicked();
    void on_backButton_clicked();

private:
    Ui::SupervisorChoiceWindow* ui;
    DatabaseManager* dbManager;
    QString loggedInUsername;
    SupervisorDashboardWindow* dashboardWindow;
    SupervisorFormsWindow* formsWindow;
    SupervisorLoginWindow* loginWindow;
};

#endif // SUPERVISORCHOICEWINDOW_H
