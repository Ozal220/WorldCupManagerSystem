#ifndef MANAGERWINDOW_H
#define MANAGERWINDOW_H

#include <QMainWindow>

namespace Ui {
class ManagerWindow;
}

class ManagerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManagerWindow(QWidget *parent = 0);
    ~ManagerWindow();

signals:
    void sendCloseSignal();//这个函数用户向主界面通知关闭的消息

private:
    Ui::ManagerWindow *ui;
};

#endif // MANAGERWINDOW_H
