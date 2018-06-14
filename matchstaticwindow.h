#ifndef MATCHSTATICWINDOW_H
#define MATCHSTATICWINDOW_H

#include <QWidget>
#include <QSqlTableModel>
namespace Ui {
class MatchStaticWindow;
}

class MatchStaticWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MatchStaticWindow(QWidget *parent = 0);
    void setTeam(QString team_1, QString team_2);
    ~MatchStaticWindow();

private slots:
    void on_goal_1_valueChanged(int arg1);

    void on_goal_2_valueChanged(int arg1);

    void on_players_1_clicked();

private:
    Ui::MatchStaticWindow *ui;
    QSqlTableModel *model = 0;
};

#endif // MATCHSTATICWINDOW_H
