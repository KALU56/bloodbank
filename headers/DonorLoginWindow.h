#ifndef WELCOMEWINDOW_H #define WELCOMEWINDOW_H

#include #include "DonorLoginWindow.h" #include "SupervisorLoginWindow.h"

namespace Ui { class WelcomeWindow; }

class WelcomeWindow : public QMainWindow { Q_OBJECT

public: explicit WelcomeWindow(QWidget *parent = nullptr); ~WelcomeWindow();

private slots: void on_donorButton_clicked(); void on_supervisorButton_clicked();

private: Ui::WelcomeWindow *ui; DonorLoginWindow *donorLoginWindow; SupervisorLoginWindow *supervisorLoginWindow; };

#endif // WELCOMEWINDOW_H
