#ifndef THEMVPS_H
#define THEMVPS_H

#include <QWidget>
#include <QSqlQueryModel>

namespace Ui {
class theMVPs;
}

class theMVPs : public QWidget
{
    Q_OBJECT

public:
    explicit theMVPs(QWidget *parent = 0);
    ~theMVPs();

private:
    Ui::theMVPs *ui;
    QSqlQueryModel *model = 0;
};

#endif // THEMVPS_H
