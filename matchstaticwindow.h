#ifndef MATCHSTATICWINDOW_H
#define MATCHSTATICWINDOW_H

#include <QWidget>
#include <QSqlQueryModel>
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

    void on_players_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MatchStaticWindow *ui;
    QSqlQueryModel *model = 0;
    QSqlQueryModel *model_2 = 0;
    int goallerCount_1 = 0;
    int goallerCount_2 = 0;
};

#endif // MATCHSTATICWINDOW_H
