#ifndef MANAGERWINDOW_H
#define MANAGERWINDOW_H

#include <QMainWindow>

#include <QMessageBox>
#include <QStackedWidget>
#include <matchviewform.h>
#include <playerpage.h>
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
    void CloseSignal();//这个函数用户向主界面通知关闭的消息

private slots:

    void on_matchDays_clicked();

    void on_score_clicked();

    void on_playerButton_clicked();

private:
    Ui::ManagerWindow *ui;
    MatchViewForm *matchPage = 0;
    playerPage *m_playerPage = 0;
};

#endif // MANAGERWINDOW_H
