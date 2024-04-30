#pragma once

#include <string>
#include <vector>
#include <QWidget>
#include "back.h"
#include <QLabel.h>
#include <qmovie.h>
#include <QPropertyAnimation>
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);

    void checktable();

    void checkq();

    void run_up();

    void run_down();

    void colour(int row, bool a);

    void right();

    void left();

    void changer();

    void changel();

    void showw();

    void make(int q, bool a);

    void colour2(int, int, bool);

    void run_right(int s);

    void run_left(int s);

    bool check();

    QPropertyAnimation *a = nullptr;

    ~Form();
    

private slots:
    void on_tableWidget_2_cellActivated();

    void on_addstate_clicked();

    void on_start_clicked();

    void jump(int s);

    void on_stop_clicked();

    void on_plus_clicked();

    void on_minus_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pause_clicked();

private:
    Ui::Form *ui;
};

