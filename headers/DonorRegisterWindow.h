#ifndef DONORREGISTERWINDOW_H
#define DONORREGISTERWINDOW_H

#include <QWidget>
#include "DatabaseManager.h"
#include "Donor.h"

namespace Ui {
class DonorRegisterWindow;
}

class DonorLoginWindow; // Forward declaration

class DonorRegisterWindow : public QWidget {
    Q_OBJECT

public:
    explicit DonorRegisterWindow(DatabaseManager* db, DonorLoginWindow* parent = nullptr);
    ~DonorRegisterWindow();

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void on_submitButton_clicked();
    void on_backButton_clicked();

private:
    Ui::DonorRegisterWindow* ui;
    DatabaseManager* dbManager;
    DonorLoginWindow* loginWindow; // Reference to the parent login window
};

#endif // DONORREGISTERWINDOW_H
