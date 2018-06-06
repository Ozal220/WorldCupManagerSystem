#include "loginWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // 在这里调用界面，隐藏界面
    return a.exec();
}
