#ifndef SCOREPAGE_H
#define SCOREPAGE_H

#include <QWidget>

namespace Ui {
class scorePage;
}

class scorePage : public QWidget
{
    Q_OBJECT

public:
    explicit scorePage(QWidget *parent = 0);
    ~scorePage();

private:
    Ui::scorePage *ui;
};

#endif // SCOREPAGE_H
