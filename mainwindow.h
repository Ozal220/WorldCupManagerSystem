#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtGui>
#include <QDebug>
#include "managerlogin.h"
#include "managerwindow.h"
#include "fanswindow.h"
#include "qss.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool connectMySql();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    managerLogin *mLogin = 0;
    ManagerWindow *mWindow = 0;
    fansWindow *fansWin = 0;

private slots:
    void on_managerButton_clicked();
    void on_fansButton_clicked();
    void closeManagerLogin();
    void reShow();

signals:
    void ShowSignal();//这个函数用户向主界面通知重新显示的消息
    void CloseSignal();//这个函数用户向主界面通知关闭的消息
    void hideSignal();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
};
#endif // LOGINWINDOW_H
