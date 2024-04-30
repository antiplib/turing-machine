#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QLineEdit>
#include <qpropertyanimation.h>
#include <QMessageBox>

extern std::string alf1;
extern std::string alf2;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    QString a1, a2;
    a1 = ui->lineEdit->text();
    a2 = ui->lineEdit_2->text();
    alf1 = a1.toStdString();
    alf2 = a2.toStdString();
    Form *two = new Form();
    two->show();
    this->hide();
}
