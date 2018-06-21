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
    explicit MatchStaticWindow(QString session, QString team_1, QString team_2, QWidget *parent = 0);
    void setTeam(QString team_1, QString team_2);
    void setSession(QString session);
    void setVisitorMode();
    ~MatchStaticWindow();

private slots:
    void on_goal_1_valueChanged(int arg1);

    void on_goal_2_valueChanged(int arg1);

    void on_players_1_clicked();

    void on_players_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MatchStaticWindow *ui;
    QSqlQueryModel *model = 0;
    QSqlQueryModel *model_2 = 0;
    int goallerCount_1 = 0;
    int goallerCount_2 = 0;
    QMap<QString, QString> *map = 0;
    QString thisSession;
    QString thisTeam_1;
    QString thisTeam_2;
};

#endif // MATCHSTATICWINDOW_H
