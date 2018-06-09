#include "mainWindow.h"
#include "managerwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 在这里调用界面，隐藏界面
    QMainWindow *w = new MainWindow();
//    w->show();
    ManagerWindow *mWindow = new ManagerWindow();
    mWindow->show();
    return a.exec();
}
