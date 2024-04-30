#include "form.h"
#include "ui_form.h"
#include <QMessageBox>
#include <unistd.h>
#include <thread>
#include <Qpainter>
#include <QLabel>
#include <QMovie>
#include <QPropertyAnimation.h>
#include <QApplication>
#include <iostream>

std::mutex g_lock;


bool nexact = false;
int curr = 0;
int speed = 1000;
QMovie *m;
int qqq = 0;
bool firstalf = false;
bool work = false;
bool pz = false;
int hhhh = 0;

Form::Form(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
   Form::on_tableWidget_2_cellActivated();
}

Form::~Form()
{
   //delete lbl;
    delete ui;
    delete m;
    delete a;

}

void Form::on_pause_clicked()
{
    pz = true;
}

bool Form::check(){
    int q = 0;
    int turing = 0;
    std::vector <char> array;
    std::string ddd = ui->lineEdit->text().toStdString();
    for(int i = 0; i < ddd.size(); ++i){
        array.push_back(ddd[i]);
    }
    int counter = 0;
    while(true){
        ++counter;
        if(counter >=10000){
            QMessageBox::about(this, "машина бесконечная", "неверная таблица");
            return 0;
        }
        qqq = q;
        std::string a = "";
        a += array[turing];
        int c = 0;
        for(int i = 0; i < alf.size(); ++i){
            if(alf[i] == a[0]){
                c = i;
            }
        }
        std::string doo = ui->tableWidget_2->item(1 + q, c)->text().toStdString();
        for(int i = 0; i < doo.size(); ++i){
            int cnt = -1;
            for(int j = 0; j < alf.size(); ++j){
                if(alf[j] == doo[i]){
                    cnt = j;
                }
            }
            if(cnt == -1){
                if(doo[i] == '!'){
                    for(int j = 0; j < array.size(); ++j){
                        bool thisans = false;
                        for(int k = 0; k < alf1.size(); ++k){
                            if(array[j] == alf1[k] || array[j] =='/'){
                                thisans = true;
                            }
                        }
                        if(!thisans){
                            QMessageBox::about(this, "Машина неверна", "на ленте останутся символы головки");
                            return 0;
                        }
                    }
                    return 1;
                }
                else if(doo[i] == '>'){
                    turing += 1;
                    if(array.size() <= turing){
                        array.push_back('/');
                    }
                }
                else if(doo[i] - '0' >= 0  && doo[i] - '0' <= 9){
                    int aaa = doo[i]-'0';
                    ++i;
                    while(i < doo.size() && doo[i] - '0' >= 0  && doo[i] - '0' <= 9){
                        aaa*=10;
                        aaa+=doo[i];
                        ++i;
                    }
                    q = aaa;
                    if(i < doo.size()){
                        if(doo[i] == '>'){
                            turing +=1;
                            if(array.size() <= turing){
                                array.push_back('/');
                            }
                        }
                        else if(doo[i] == '<'){
                            if(turing != 0){
                                turing -=1;
                            }
                            else{
                                array.insert(array.begin(), '/');
                            }
                        }
                    }
                }
                else if(doo[i] == '<'){
                    if(turing != 0){
                        turing -=1;
                    }
                    else{
                        array.insert(array.begin(), '/');
                    }
                }
                else if(doo[i] == ' '){
                    QMessageBox::about(this, "втретился nn", "измените таблицу");
                    return 0;
                }
                else{
                    q = doo[i];
                }
            }
            else{
                array[turing] = doo[i];
                //if(!nexact)
            }
        }
    }
}

bool checkonznak(){
    for(int i :indexs){
        for(int j = 0; j < mainmap[i].size(); ++j){
            for(int k = 0; k < mainmap[i][j].size(); ++k){
                if(mainmap[i][j][k] == '!'){
                    return true;
                }
            }
        }
    }
    return false;
}

void Form::colour2(int n, int m, bool a){
    if(a){
        ui->tableWidget_2->item(n, m)->setBackground(Qt::blue);
    }
    else{
        ui->tableWidget_2->item(n, m)->setBackground(Qt::white);

    }
}

void Form::showw(){
    for(int i = 0; i < 10; ++i){
        std::string help;
        help += str[l+i];
        QString a = QString::fromStdString(help);
        QTableWidgetItem* k = new QTableWidgetItem(a);
        ui->tableWidget->setItem(0, i, k);
    }
}

void Form::changer(){
    l+=10;
    r+=10;
    if(r >= str.size()){
        for(int i = 0; i < 10; ++i){
            str.push_back('/');
        }
        showw();
    }
    else{
        showw();
    }
}

void Form::changel(){
    if(l > 0){
        l-=10;
        r-=10;
        showw();
    }
    else{
        for(int i = 0; i < 10; ++i){
            str.insert(str.begin(), '/');
            showw();

        }
        turing = 10;

    }
}

void Form::on_tableWidget_2_cellActivated()
{
    int column = 1;
    int row = alf1.size() + alf2.size() + 1;
    ui->tableWidget_2->setRowCount(column);
    ui->tableWidget_2->setColumnCount(row);
    alf = alf1 + "/" + alf2;
    for(int i = 0; i < row; ++i){
        std::string n = "";
        n += alf[i];
        QString a = QString::fromStdString(n);
        QTableWidgetItem* k = new QTableWidgetItem(a);
        ui->tableWidget_2->setItem(0, i, k);
        ui->tableWidget_2->item(0, i)->setFlags(Qt::NoItemFlags);
    }
    ui->tableWidget_2->setVerticalHeaderItem(0, new QTableWidgetItem(QString::fromStdString("")));

}

void Form::on_addstate_clicked()//add state
{

    int c = ui->tableWidget_2->rowCount() + 1;
    ui->tableWidget_2->setRowCount(c);
    for (int row = 1; row < ui->tableWidget_2->rowCount(); ++row)
    {
        ui->tableWidget_2->setVerticalHeaderItem(row, new
                                                 QTableWidgetItem(QString::fromStdString(std::to_string(row - 1))));
    }
}

void Form::on_stop_clicked()
{
    hhhh = 0;
    QPixmap *pix = new QPixmap("C:\\chan.jpg");
    ui->label->setPixmap(*pix);
    delete pix;

        work = false;
        ui->addstate->setEnabled(true);
        ui->lineEdit->setReadOnly(false);
        ui->tableWidget_2->setEnabled(true);
        ui->tableWidget->clear();
        ui->pushButton->setEnabled(1);
        str.clear();
        l = 0;
        r = 10;
        turing = 0;
        ui->label->setGeometry(60, 0, 35, 35);
        ui->pushButton_2->setEnabled(1);

}

void Form::colour(int column, bool a){

    if(a){
        ui->tableWidget->item(0, column)->setBackground(Qt::red);
    }
    else{
        ui->tableWidget->item(0, column)->setBackground(Qt::white);
    }
}

void Form::run_right(int s = speed){
    QMovie *m = new QMovie("C:\\running.gif");
    ui->label->setMovie(m);
    m->start();
    a = new QPropertyAnimation(ui->label, "pos");
    a->setDuration(s);
    a->setStartValue(ui->label->pos());
    a->setEndValue(QPoint(ui->label->x() + 35, 0));
    a->start();
    QEventLoop loop;
    if(pz){
        QEventLoop loop2;
        QObject::connect(ui->pushButton_4, &QPushButton::clicked, &loop2, &QEventLoop::quit);
        QObject::connect(ui->start, &QPushButton::clicked, &loop2, &QEventLoop::quit);
        loop2.exec();
        pz = false;
    }
    QObject::connect(ui->pushButton_3, &QPushButton::clicked, a, &QPropertyAnimation::stop);
    QObject::connect(ui->pushButton_3, &QPushButton::clicked, a, &QPropertyAnimation::stop);
    QObject::connect(ui->stop, &QPushButton::clicked, m, &QMovie::stop);
    QObject::connect(ui->stop, &QPushButton::clicked, a, &QPropertyAnimation::stop);

    QObject::connect(a, &QPropertyAnimation::finished, &loop, &QEventLoop::quit);
    if(nexact){
        a->setDuration(a->totalDuration());
    }

        loop.exec();
    QPixmap *pix = new QPixmap("C:\\chan.jpg");
    ui->label->setPixmap(*pix);
    delete a;
    delete m;
    delete pix;

    nexact = false;
}

void Form::run_left(int s = speed){
    QMovie *m = new QMovie("C:\\running.gif");
    ui->label->setMovie(m);
    m->start();
    a = new QPropertyAnimation(ui->label, "pos");
    a->setDuration(s);
    a->setStartValue(ui->label->pos());
    a->setEndValue(QPoint(ui->label->x() - 35, 0));
    a->start();
    QEventLoop loop;
    if(pz){
        QEventLoop loop2;
        QObject::connect(ui->pushButton_4, &QPushButton::clicked, &loop2, &QEventLoop::quit);
        QObject::connect(ui->start, &QPushButton::clicked, &loop2, &QEventLoop::quit);

        loop2.exec();
        pz = false;
    }
    QObject::connect(ui->stop, &QPushButton::clicked, m, &QMovie::stop);
    QObject::connect(ui->stop, &QPushButton::clicked, a, &QPropertyAnimation::stop);
    QObject::connect(ui->pushButton_3, &QPushButton::clicked, a, &QPropertyAnimation::stop);
    QObject::connect(ui->pushButton_3, &QPushButton::clicked, a, &QPropertyAnimation::stop);

    QObject::connect(a, &QPropertyAnimation::finished, &loop, &QEventLoop::quit);
    if(nexact){
        a->setDuration(a->totalDuration());
    }
    loop.exec();
    ui->label->setGeometry(QRect(60 + (turing - l)*35, 0, 35, 35));

    QPixmap *pix = new QPixmap("C:\\chan.jpg");
    ui->label->setPixmap(*pix);
    delete a;
    delete pix;
    delete m;
    nexact = false;
    showw();
}

void Form::jump(int s = speed){
    QPixmap *pix = new QPixmap("C://chan.jpg");
    ui->label->setPixmap(*pix);
    a = new QPropertyAnimation(ui->label, "pos");
    a->setDuration(s/2);
    a->setStartValue(ui->label->pos());
    a->setEndValue(QPoint(ui->label->x(), 10));
    a->start();
    QEventLoop loop;

    QObject::connect(ui->stop, &QPushButton::clicked, a, &QPropertyAnimation::stop);
    QObject::connect(ui->pushButton_3, &QPushButton::clicked, a, &QPropertyAnimation::stop);

    QObject::connect(a, &QPropertyAnimation::finished, &loop, &QEventLoop::quit);
    if(nexact){
        a->setDuration(a->totalDuration());
    }
    else{
        loop.exec();}
    delete a;
    a = new QPropertyAnimation(ui->label, "pos");
    a->setDuration(s/2);
    a->setStartValue(ui->label->pos());
    a->setEndValue(QPoint(ui->label->x(), 0));
    a->start();
    if(pz){
        QEventLoop loop2;
        QObject::connect(ui->pushButton_4, &QPushButton::clicked, &loop2, &QEventLoop::quit);
        QObject::connect(ui->start, &QPushButton::clicked, &loop2, &QEventLoop::quit);
        QObject::connect(ui->pushButton_3, &QPushButton::clicked, &loop2, &QEventLoop::quit);

        loop2.exec();
        pz = false;

    }
    QObject::connect(ui->stop, &QPushButton::clicked, a, &QPropertyAnimation::stop);
    QObject::connect(ui->pushButton_3, &QPushButton::clicked, a, &QPropertyAnimation::stop);
    QObject::connect(a, &QPropertyAnimation::finished, &loop, &QEventLoop::quit);
    if(nexact){
        a->setDuration(a->totalDuration());
    }
    else{
        loop.exec();
    }
    delete a;
    if(!work){
        ui->label->setGeometry(60, 0, 35, 35);
    }
    nexact = false;
    delete pix;
}

void Form::right(){
    if(turing == l + 9){
        ui->label->setGeometry(QRect(60, 0, 35, 35));
        turing +=1;
        Form::changer();
    }
    else{
        turing += 1;
        if(!nexact){
            run_right();
        }
        else{
            nexact = false;
            ui->label->setGeometry(QRect(ui->label->x() + 35 , 0, 35, 35));
        }
    }
}

void Form::left(){

    if(turing - l <= 0){
        Form::changel();
        turing -=1;
        ui->label->setGeometry(QRect(60+35*8, 0, 35, 35));
    }
    else{
        if(turing > 1){
            turing -= 1;
        }
        else{
            changel();
            turing -=1;
            ui->label->setGeometry(QRect(60+35*8, 0, 35, 35));
        }
        if(!nexact){
            run_left();
        }
        else{
            nexact = false;
            ui->label->setGeometry(QRect(ui->label->x() - 35 , 0, 35, 35));
            //run_left();

        }
    }
    ui->label->setGeometry(QRect(60 + turing* 35 - l*35, 0, 35, 35));

}

void Form::on_start_clicked()
{
    l = 0;
    r = 10;
    turing = 0;
    pz = false;
    nexact = false;
    if(!work){
        std::string s = ui->lineEdit->text().toStdString();
        str.clear();
        for(int i = 0; i < s.size(); ++i){
            str.push_back(s[i]);
            bool flag = false;
            for(int h = 0; h < alf1.size(); ++h){
                if(alf1[h]==s[i]){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                    QMessageBox::information(this, "неправильно заполнена лента", "измените ленту тьюринга");
                    return;
                }
        }
        while(str.size() < 15){
            str.push_back('/');
        }

        showw();

        bool ans = true;
        ui->addstate->setEnabled(false);
        ui->lineEdit->setReadOnly(true);
        ui->tableWidget->setEnabled(false);
        ui->tableWidget_2->setEnabled(false);
        ui->pushButton->setEnabled(0);
        ui->pushButton_2->setEnabled(false);
        mainmap.clear();
        for(int i = 1; i < ui->tableWidget_2->rowCount(); ++i){
            std::vector <std::string> aa;
            for(int j = 0; j < alf.size(); ++j){
                    if(ui->tableWidget_2->item(i, j) != nullptr){
                        QTableWidgetItem *nnn = ui->tableWidget_2->item(i, j);
                        QTableWidgetItem n;
                        std::string a;
                        n = *nnn;
                        a = n.text().toStdString();
                        aa.push_back(a);
                    }
                else{
                    aa.push_back(" ");
                }
            }
            if(!addvector(i, aa)){
                ans = false;
            }
        }
        if(!ans){
            ui->addstate->setEnabled(true);
            ui->lineEdit->setReadOnly(false);
            ui->tableWidget->setEnabled(true);
            ui->tableWidget_2->setEnabled(true);
            ui->pushButton_2->setEnabled(true);
            QMessageBox::information(this, "неправильно построенная таблица", "измените");
            return;
        }
        else{
            work = true;
            if(ui->tableWidget_2->rowCount() != 1){
                if(checkonznak()){
                    if(check()){
                        turing = 0;
                        Form::make(0, 0);
                    }
                }
                else{
                    QMessageBox::about(this, "нет !", "добавьте !");
                }
            }
        }
    }
}

void Form::make(int q, bool nex = false){
    srand((unsigned int) time(0));
    bool stop = true;

    while(stop && work){
        qqq = q;
        std::string a = "";
        a += str[turing];
        int c = 0;
        for(int i = 0; i < alf.size(); ++i){
            if(alf[i] == a[0]){
                c = i;
            }
        }
        std::string doo = ui->tableWidget_2->item(1 + q, c)->text().toStdString();
        for(int i = 0; i < doo.size(); i +=1){
            int cnt = -1;
            for(int j = 0; j < alf.size(); ++j){
                if(alf[j] == doo[i]){
                    cnt = j;
                }
            }
            if(cnt == -1){
                if(doo[i] == '!'){
                    stop = false;
                    ui->label->setGeometry(QRect(60 + (turing - l) * 35, 0, 35, 35));
                }
                else if(doo[i] == '>'){
                    right();
                }
                else if(doo[i] - '0' >= 0  && doo[i] - '0' <= 9){
                    int aaa = doo[i]-'0';
                    ++i;
                    while(i < doo.size() && doo[i] - '0' >= 0  && doo[i] - '0' <= 9){
                        aaa*=10;
                        aaa+=doo[i];
                        ++i;
                    }
                    q = aaa;
                    qqq = q;
                        if(doo[i] == '>'){
                            right();

                        }else if(doo[i] == '<'){
                            left();
                        }
                }
                else if(doo[i] == '<'){
                    left();
                    if(i + 1 < doo.size() && doo[i + 1] - '0' >= 0  && doo[i + 1] - '0' <= 9){
                            int aaa = doo[i]-'0';
                            ++i;
                            while(i + 1 < doo.size() && doo[i + 1] - '0' >= 0  && doo[i + 1] - '0' <= 9){
                            aaa*=10;
                            aaa+=doo[i];
                            ++i;
                            }
                            q = aaa;
                            qqq = q;
                    }
                }
                else if(doo[i] == ' '){
                    //QMessageBox::about(this, "втретился nn", "измените таблицу");
                    continue;
                }
                else{
                    q = doo[i];
                    qqq = q;
                }
            }
            else{
                str[turing] = doo[i];
                showw();
                if(work){
                    if(!nex){
                        jump();
                    }
                }//
            }
        }


        if(nex) {
            nex = false;
        }

    }

}

void Form::on_plus_clicked()
{
    speed+=200;
}

void Form::on_minus_clicked()
{
    if(speed >200){
        speed-=200;
    }
}

void Form::on_pushButton_clicked() // delete state
{
    if(ui->tableWidget_2->rowCount() >1){
    indexs.clear();
    mainmap.clear();
    for(int i = 0 ; i < ui->tableWidget_2->rowCount() - 1; ++i){
        for(int j = 0; j < ui->tableWidget_2->columnCount(); ++j){
            QTableWidgetItem *item = new QTableWidgetItem();
            item = ui->tableWidget_2->item(i, j);
            std::string obj = "";
            if(item != nullptr){
                obj += item->text().toStdString();
            }
            mainmap[i].push_back(obj);
        }
        indexs.push_back(i);
    }
    int row, column;
    row = ui->tableWidget_2->rowCount() - 1;
    column = ui->tableWidget_2->columnCount();
    ui->tableWidget_2->clear();
    ui->tableWidget_2->setRowCount(0);
    ui->tableWidget_2->setRowCount(row);
    ui->tableWidget_2->setColumnCount(column);

    //заполнение таблицы
    for(int i = 0 ; i < ui->tableWidget_2->rowCount(); ++i){
        for(int j = 0; j < ui->tableWidget_2->columnCount(); ++j){
            std::string s = mainmap[i][j];
            QString ss = QString::fromStdString(s);
            QTableWidgetItem *item = new QTableWidgetItem(ss);
            ui->tableWidget_2->setItem(i, j, item);

        }
        indexs.push_back(i);
    }
    for(int i =0; i < alf.size(); ++i){
        ui->tableWidget_2->item(0, i)->setFlags(Qt::NoItemFlags);

    }
    for (int row = 1; row < ui->tableWidget_2->rowCount(); ++row)
    {
        ui->tableWidget_2->setVerticalHeaderItem(row, new QTableWidgetItem(QString::fromStdString(std::to_string(row - 1))));
    }
    ui->tableWidget_2->setVerticalHeaderItem(0, new QTableWidgetItem(QString::fromStdString("")));
    }
}

void Form::on_pushButton_2_clicked() // change alf
{
    //getmainmap
    for(int i = 0; i < ui->tableWidget_2->columnCount(); ++i){
        indexs.push_back(i - 1);
        for(int j = 1; j < ui->tableWidget_2->rowCount(); ++j){
            std::string ll;
            QTableWidgetItem *l = ui->tableWidget_2->item(j, i);
            if(l == nullptr){
                ll = "";
            }
            else{
                ll = l->text().toStdString();
            }
            mainmap[i].push_back(ll);
        }

    }
    std::string newalf1, newalf2;
    newalf1 = ui->lineEdit_2->text().toStdString();
    newalf2 = ui->lineEdit_3->text().toStdString();
    std::string newalf = newalf1+ '/' + newalf2;
    bool is_correct = true;
    for(int i = 0; i < alf.size(); ++i){
        bool one_valid = false;
        for(int j = 0; j < newalf.size(); ++j){
            if(newalf[j] == alf[i]){
                one_valid = true;
            }
        }
        if(!one_valid){
            is_correct = false;
        }
    }
    newmainmap.clear();
    if(is_correct){
        for(int i = 0; i < newalf.size(); ++i){
            for(int j = 0; j < alf.size(); ++j){
                if(newalf[i] == alf[j]){
                    newmainmap[i] = mainmap[j];
                }
            }
        }
        ui->tableWidget_2->clear();
        ui->tableWidget_2->setColumnCount(newalf.size());

        for(int i = 0; i < newalf.size(); ++i){
            std::string aaa = "";
            aaa+=newalf[i];
            QTableWidgetItem *it = new QTableWidgetItem(QString::fromStdString(aaa));
            ui->tableWidget_2->setItem(0, i, it);
        }
        for(int i = 0; i < newalf.size(); ++i){
            for(int j = 0; j < newmainmap[i].size(); ++j){
                std::string aaa = "";
                aaa += newmainmap[i][j];
                QTableWidgetItem *it = new QTableWidgetItem(QString::fromStdString(aaa));
                ui->tableWidget_2->setItem(j+1, i, it);
            }
        }
        mainmap.clear();
        mainmap = newmainmap;
        alf = newalf;
        for(int i =0; i < alf.size(); ++i){
            ui->tableWidget_2->item(0, i)->setFlags(Qt::NoItemFlags);
        }
        for (int row = 1; row < ui->tableWidget_2->rowCount(); ++row)
        {
            ui->tableWidget_2->setVerticalHeaderItem(row, new QTableWidgetItem(QString::fromStdString(std::to_string(row - 1))));
        }

    }
    else{
        ui->tableWidget_2->clear();
        ui->tableWidget_2->setColumnCount(newalf.size());
        ui->tableWidget_2->setRowCount(1);

        for(int i = 0; i < newalf.size(); ++i){
            std::string aaa = "";
            aaa+=newalf[i];
            QTableWidgetItem *it = new QTableWidgetItem(QString::fromStdString(aaa));
            ui->tableWidget_2->setItem(0, i, it);
        }
        alf = newalf;
        mainmap.clear();
        indexs.clear();
        for(int i =0; i < alf.size(); ++i){
            ui->tableWidget_2->item(0, i)->setFlags(Qt::NoItemFlags);
        }
    }
    mainmap.clear();
    indexs.clear();
    ui->tableWidget_2->setVerticalHeaderItem(0, new QTableWidgetItem(QString::fromStdString("")));
    alf1 = newalf1;
    alf2= newalf2;
}

void Form::on_pushButton_3_clicked()
{
    ui->label->setGeometry(QRect(60 + (turing-l)* 35, 0, 35, 35));
    if(!nexact){
        make(qqq, 1);
        nexact = true;
    }
    pz = false;

}

void Form::on_pushButton_4_clicked()
{
    if(!pz){
        pz = true;
    }
}

