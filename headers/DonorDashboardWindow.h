#ifndef DONORDASHBOARDWINDOW_H
#define DONORDASHBOARDWINDOW_H

#include <QWidget>
#include "DatabaseManager.h"
#include "Donor.h"
#include "MedicalHistory.h"
#include "HealthHistory.h"

namespace Ui {
class DonorDashboardWindow;
}

class DonorLoginWindow; // Forward declaration

class DonorDashboardWindow : public QWidget {
    Q_OBJECT

public:
    explicit DonorDashboardWindow(const QString& username, DonorLoginWindow* parent = nullptr);
    ~DonorDashboardWindow();

private slots:
    void on_backButton_clicked();

private:
    void loadMedicalHistory();
    void loadHealthHistory();

    Ui::DonorDashboardWindow* ui;
    DatabaseManager* dbManager;
    QString username;
    DonorLoginWindow* loginWindow; // Reference to the parent login window
};

#endif // DONORDASHBOARDWINDOW_H
