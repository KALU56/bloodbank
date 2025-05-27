#ifndef DONORLOGINWINDOW_H
#define DONORLOGINWINDOW_H

#include <QWidget>
#include "DatabaseManager.h"

namespace Ui {
class DonorLoginWindow;
}

class DonorRegisterWindow;
class DonorDashboardWindow;

class DonorLoginWindow : public QWidget {
    Q_OBJECT

public:
    explicit DonorLoginWindow(DatabaseManager* db, QWidget* parent = nullptr);
    ~DonorLoginWindow();

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void on_loginButton_clicked();
    void on_registerButton_clicked();

private:
    Ui::DonorLoginWindow* ui;
    DatabaseManager* dbManager;
    DonorRegisterWindow* registerWindow;
    DonorDashboardWindow* dashboardWindow;
};

#endif // DONORLOGINWINDOW_H
