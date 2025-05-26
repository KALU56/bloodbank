#ifndef DONORDASHBOARDWINDOW_H
#define DONORDASHBOARDWINDOW_H

#include <QWidget>
#include "DatabaseManager.h"

namespace Ui {
class DonorDashboardWindow;
}

class DonorDashboardWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DonorDashboardWindow(const QString& username, QWidget *parent = nullptr);
    ~DonorDashboardWindow();

private:
    void loadMedicalHistory();
    void loadHealthHistory();

    Ui::DonorDashboardWindow *ui;
    DatabaseManager *dbManager;
    QString username;
};

#endif // DONORDASHBOARDWINDOW_H
