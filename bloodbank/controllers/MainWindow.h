#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class DonorDashboard;
class DonorController;
class SupervisorDashboard;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showDonorDashboard();
    void showSupervisorDashboard();

private:
    Ui::MainWindow *ui;
    DonorDashboard *donorDashboard;
    DonorController *donorController;
    SupervisorDashboard *supervisorDashboard;
};

#endif // MAINWINDOW_H
