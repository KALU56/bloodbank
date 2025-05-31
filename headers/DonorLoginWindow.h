#ifndef DONORLOGINWINDOW_H
#define DONORLOGINWINDOW_H

#include <QWidget>
#include "DatabaseManager.h"

namespace Ui {
class DonorLoginWindow;
}

class DonorRegisterWindow;
class DonorDashboardWindow;
class WelcomeWindow; // Forward declaration

class DonorLoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DonorLoginWindow(DatabaseManager* db, WelcomeWindow* parent = nullptr);
    ~DonorLoginWindow();

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void onLoginButtonClicked();
    void onRegisterButtonClicked();
    void on_backButton_clicked();

private:
    Ui::DonorLoginWindow *ui;
    DatabaseManager* dbManager;
    DonorRegisterWindow* registerWindow;
    DonorDashboardWindow* dashboardWindow;
    WelcomeWindow* welcomeWindow; // Reference to the parent welcome window
};

#endif // DONORLOGINWINDOW_H
