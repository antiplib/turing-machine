#include "formtwo.h"
#include "ui_formtwo.h"
#include <QLabel>

Formtwo::Formtwo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Formtwo)
{
    ui->setupUi(this);
}

std::string lf1, lf2;

Formtwo::~Formtwo()
{
    delete ui;
}



std::string getalf1(){
    return lf1;
}
std::string getalf2(){
    return lf2;
}

void Formtwo::on_pushButton_clicked()
{
    std::string newalf1 = ui->lineEdit->text().toStdString();
    std::string newalf2 = ui->lineEdit_2->text().toStdString();
    lf1 = newalf1;
    lf2 = newalf2;
    this->destroy();
}

