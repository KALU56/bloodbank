#ifndef SUPERVISORLOGINWINDOW_H
#define SUPERVISORLOGINWINDOW_H

#include <QWidget>
#include "DatabaseManager.h"

namespace Ui {
class SupervisorLoginWindow;
}

class SupervisorChoiceWindow;

class SupervisorLoginWindow : public QWidget {
    Q_OBJECT

public:
    explicit SupervisorLoginWindow(DatabaseManager* db, QWidget* parent = nullptr);
    ~SupervisorLoginWindow();

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void on_loginButton_clicked();

private:
    Ui::SupervisorLoginWindow* ui;
    DatabaseManager* dbManager;
    SupervisorChoiceWindow* choiceWindow;
};

#endif // SUPERVISORLOGINWINDOW_H
