#ifndef FORMTWO_H
#define FORMTWO_H

#include <QWidget>
#include <qlabel.h>

namespace Ui {
class Formtwo;
}

class Formtwo : public QWidget
{
    Q_OBJECT

public:
    explicit Formtwo(QWidget *parent = nullptr);
    ~Formtwo();
    void getalf(std::string a1, std::string a2);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Formtwo *ui;
};

std::string getalf1();
std::string getalf2();

#endif // FORMTWO_H
