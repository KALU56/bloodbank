#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QMainWindow>
#include "DatabaseManager.h"

namespace Ui {
class WelcomeWindow;
}

class DonorLoginWindow;
class SupervisorLoginWindow;

class WelcomeWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit WelcomeWindow(QWidget* parent = nullptr);
    ~WelcomeWindow();

private slots:
    void onDonorButtonClicked();
    void onSupervisorButtonClicked();

private:
    Ui::WelcomeWindow* ui;
    DatabaseManager dbManager;
    DonorLoginWindow* donorLoginWindow;
    SupervisorLoginWindow* supervisorLoginWindow;
};

#endif // WELCOMEWINDOW_H
