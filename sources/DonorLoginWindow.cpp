#include "DonorLoginWindow.h" #include "ui_DonorLoginWindow.h" #include

DonorLoginWindow::DonorLoginWindow(QWidget *parent) : QWidget(parent), ui(new Ui::DonorLoginWindow), dbManager(new DatabaseManager()), registerWindow(nullptr), dashboardWindow(nullptr) { ui->setupUi(this); }

DonorLoginWindow::~DonorLoginWindow() { delete ui; delete dbManager; delete registerWindow; delete dashboardWindow; }

void DonorLoginWindow::on_loginButton_clicked() { QString username = ui->usernameEdit->text(); QString password = ui->passwordEdit->text();

    if (dbManager->donorLogin(username, password)) {
        if (!dashboardWindow) {
            dashboardWindow = new DonorDashboardWindow(username, this);
        }
        dashboardWindow->show();
        this->hide();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }

}

void DonorLoginWindow::on_registerButton_clicked() { if (!registerWindow) { registerWindow = new DonorRegisterWindow(this); } registerWindow->show(); this->hide(); }
