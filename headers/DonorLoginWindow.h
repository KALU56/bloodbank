#ifndef DONORLOGINWINDOW_H
#define DONORLOGINWINDOW_H

#include <QWidget>
#include "DatabaseManager.h"

namespace Ui {
class DonorLoginWindow;
}

class DonorRegisterWindow;
class DonorDashboardWindow;

class DonorLoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DonorLoginWindow(DatabaseManager* db, QWidget* parent = nullptr);
    ~DonorLoginWindow();

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void onLoginButtonClicked();       // ⬅ Add this
    void onRegisterButtonClicked();    // ⬅ And this

private:
    Ui::DonorLoginWindow *ui;
    DatabaseManager* dbManager;
    DonorRegisterWindow* registerWindow;
    DonorDashboardWindow* dashboardWindow;
};

#endif // DONORLOGINWINDOW_H
