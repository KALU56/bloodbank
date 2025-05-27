#ifndef SUPERVISORFORMSWINDOW_H
#define SUPERVISORFORMSWINDOW_H

#include <QWidget>
#include "DatabaseManager.h"
#include "Donor.h"
#include "MedicalHistory.h"
#include "HealthHistory.h"

namespace Ui {
class SupervisorFormsWindow;
}

class SupervisorFormsWindow : public QWidget {
    Q_OBJECT

public:
    explicit SupervisorFormsWindow(QWidget* parent = nullptr);
    ~SupervisorFormsWindow();

private slots:
    void on_medicalSubmitButton_clicked();
    void on_healthSubmitButton_clicked();

private:
    Ui::SupervisorFormsWindow* ui;
    DatabaseManager* dbManager;
};

#endif // SUPERVISORFORMSWINDOW_H
