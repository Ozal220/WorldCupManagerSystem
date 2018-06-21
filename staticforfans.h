#ifndef STATICFORFANS_H
#define STATICFORFANS_H

#include <QWidget>
#include <QMap>
#include <QSqlQuery>


namespace Ui {
class staticForFans;
}

class staticForFans : public QWidget
{
    Q_OBJECT

public:
    explicit staticForFans(QString session, QString team_1, QString team_2, QWidget *parent = 0);
    void setTeam(QString team_1, QString team_2);
    ~staticForFans();

private:
    Ui::staticForFans *ui;
    QMap<QString, QString> *map = 0;
};

#endif // STATICFORFANS_H
