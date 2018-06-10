#ifndef STADIUMPAGE_H
#define STADIUMPAGE_H

#include <QWidget>

namespace Ui {
class stadiumPage;
}

class stadiumPage : public QWidget
{
    Q_OBJECT

public:
    explicit stadiumPage(QWidget *parent = 0);
    ~stadiumPage();

private:
    Ui::stadiumPage *ui;
};

#endif // STADIUMPAGE_H
