#ifndef DONORREGISTERWINDOW_H
#define DONORREGISTERWINDOW_H

#include <QWidget>
#include "DatabaseManager.h"
#include "Donor.h"

namespace Ui {
class DonorRegisterWindow;
}

class DonorRegisterWindow : public QWidget {
    Q_OBJECT

public:
    explicit DonorRegisterWindow(DatabaseManager* db, QWidget* parent = nullptr);
    ~DonorRegisterWindow();

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void on_submitButton_clicked();

private:
    Ui::DonorRegisterWindow* ui;
    DatabaseManager* dbManager;
};

#endif // DONORREGISTERWINDOW_H
