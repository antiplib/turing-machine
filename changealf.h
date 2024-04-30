#ifndef CHANGEALF_H
#define CHANGEALF_H

#include <QWidget>

namespace Ui {
class changealf;
}

class changealf : public QWidget
{
    Q_OBJECT

public:
    explicit changealf(QWidget *parent = nullptr);
    ~changealf();

private:
    Ui::changealf *ui;
};

#endif // CHANGEALF_H
