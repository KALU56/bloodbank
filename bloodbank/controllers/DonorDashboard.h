// DonorDashboard.h
#ifndef DONORDASHBOARD_H
#define DONORDASHBOARD_H

#include <QWidget>

namespace Ui {
class DonorDashboard;
}

class DonorDashboard : public QWidget
{
    Q_OBJECT

public:
    explicit DonorDashboard(QWidget *parent = nullptr);
    ~DonorDashboard();

signals:
    void registerClicked();
    void loginClicked();
    void exitClicked();
    void backClicked();

private slots:
    void onRegisterButtonClicked();
    void onLoginButtonClicked();
    void onExitButtonClicked();
    void onBackButtonClicked();

private:
    Ui::DonorDashboard *ui;
};

#endif // DONORDASHBOARD_H
