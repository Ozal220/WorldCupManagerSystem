#ifndef MATCHINFO_H
#define MATCHINFO_H

#include <QTabWidget>

namespace Ui {
class matchInfo;
}

class matchInfo : public QTabWidget
{
    Q_OBJECT

public:
    explicit matchInfo(QWidget *parent = 0);
    ~matchInfo();

private:
    Ui::matchInfo *ui;
};

#endif // MATCHINFO_H
