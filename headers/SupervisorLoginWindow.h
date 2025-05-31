#ifndef SUPERVISORLOGINWINDOW_H
#define SUPERVISORLOGINWINDOW_H

#include <QWidget>
#include <QCloseEvent>          // Added include
#include "DatabaseManager.h"

namespace Ui {
class SupervisorLoginWindow;
}

class SupervisorChoiceWindow;
class WelcomeWindow;            // Forward declaration

class SupervisorLoginWindow : public QWidget {
    Q_OBJECT

public:
    explicit SupervisorLoginWindow(DatabaseManager* db, WelcomeWindow* parent = nullptr);
    ~SupervisorLoginWindow();

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void on_loginButton_clicked();
    void on_backButton_clicked();

private:
    Ui::SupervisorLoginWindow* ui;
    DatabaseManager* dbManager;
    SupervisorChoiceWindow* choiceWindow;
    WelcomeWindow* welcomeWindow;
};

#endif // SUPERVISORLOGINWINDOW_H
