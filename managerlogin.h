#ifndef MANAGERLOGIN_H
#define MANAGERLOGIN_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QGraphicsView>

namespace Ui {
class managerLogin;
}

class managerLogin : public QDialog
{
    Q_OBJECT

public:
    explicit managerLogin(QWidget *parent = 0);
    ~managerLogin();

private slots:
    void on_returnButton_clicked();
    void enableLoginButton(const QString&);
    void on_loginButton_clicked();

signals:
    void ShowSignal();//这个函数用户向主界面通知重新显示的消息
    void CloseSignal();//这个函数用户向主界面通知关闭的消息
    void ManagerLoginSignal();

private:
    Ui::managerLogin *ui;

};

#endif // MANAGERLOGIN_H
