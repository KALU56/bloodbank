#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QMainWindow>
#include "DatabaseManager.h"  // Database connection handling

namespace Ui {
class WelcomeWindow;          // This comes from "ui_WelcomeWindow.h", auto-generated
}

class WelcomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WelcomeWindow(QWidget *parent = nullptr);
    ~WelcomeWindow();

private:
    Ui::WelcomeWindow *ui;    // Pointer to the generated UI class
    DatabaseManager dbManager; // Handles database connection
};

#endif // WELCOMEWINDOW_H
