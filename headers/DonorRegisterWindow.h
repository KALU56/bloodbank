#ifndef DONORREGISTERWINDOW_H
#define DONORREGISTERWINDOW_H

#include <QWidget>
#include "DatabaseManager.h"
#include "DonorLoginWindow.h"

namespace Ui {
class DonorRegisterWindow;
}

class DonorRegisterWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DonorRegisterWindow(QWidget *parent = nullptr);
    ~DonorRegisterWindow();

private slots:
    void on_submitButton_clicked();

private:
    Ui::DonorRegisterWindow *ui;
    DatabaseManager *dbManager;
    DonorLoginWindow *loginWindow;
};

#endif // DONORREGISTERWINDOW_H
