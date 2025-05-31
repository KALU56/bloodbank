#include "SupervisorFormsWindow.h"
#include "ui_SupervisorFormsWindow.h"
#include <QMessageBox>
#include <QDebug>

SupervisorFormsWindow::SupervisorFormsWindow(QWidget* parent)
    : QWidget(parent),
    ui(new Ui::SupervisorFormsWindow),
    dbManager(new DatabaseManager()),
    parentWindow(parent) {
    ui->setupUi(this);
    connect(ui->medicalSubmitButton, &QPushButton::clicked, this, &SupervisorFormsWindow::on_medicalSubmitButton_clicked);
    connect(ui->healthSubmitButton, &QPushButton::clicked, this, &SupervisorFormsWindow::on_healthSubmitButton_clicked);
    connect(ui->backButton, &QPushButton::clicked, this, &SupervisorFormsWindow::on_backButton_clicked);
}

SupervisorFormsWindow::~SupervisorFormsWindow() {
    delete ui;
    delete dbManager;
}

void SupervisorFormsWindow::on_medicalSubmitButton_clicked() {
    qDebug() << "Medical submit button clicked!";
    // Add your logic for submitting medical history here
    QMessageBox::information(this, "Submit", "Medical form submitted!");
}

void SupervisorFormsWindow::on_healthSubmitButton_clicked() {
    qDebug() << "Health submit button clicked!";
    // Add your logic for submitting health history here
    QMessageBox::information(this, "Submit", "Health form submitted!");
}

void SupervisorFormsWindow::on_backButton_clicked() {
    if (parentWindow) {
        parentWindow->show();
        parentWindow->raise();
        parentWindow->activateWindow();
    }
    this->hide();
}
