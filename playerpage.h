#ifndef PLAYERPAGE_H
#define PLAYERPAGE_H

#include <QWidget>

namespace Ui {
class playerPage;
}

class playerPage : public QWidget
{
    Q_OBJECT

public:
    explicit playerPage(QWidget *parent = 0);
    ~playerPage();

private:
    Ui::playerPage *ui;
};

#endif // PLAYERPAGE_H
