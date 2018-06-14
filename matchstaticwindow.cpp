#include "matchstaticwindow.h"
#include "ui_matchstaticwindow.h"
#include <QDebug>
#include <QSqlQuery>
MatchStaticWindow::MatchStaticWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MatchStaticWindow)
{
    ui->setupUi(this);
    resize(677,477);
}

MatchStaticWindow::~MatchStaticWindow()
{
    delete ui;
}

void MatchStaticWindow::setTeam(QString team_1, QString team_2){
    ui->team_1->setText(team_1);
    ui->team_2->setText(team_2);
}


void MatchStaticWindow::on_goal_1_valueChanged(int arg1)
{
    qDebug() << "arg1 = " << arg1;
    if(arg1 >= 0)
        ui->players_1->setEnabled(true);
}

void MatchStaticWindow::on_goal_2_valueChanged(int arg2)
{
    qDebug() << "arg2 = " << arg2;
    if(arg2 >= 0)
        ui->players_2->setEnabled(true);
}

void MatchStaticWindow::on_players_1_clicked()
{
    model = new QSqlTableModel(this);
    model->setTable("player");
    model->setFilter(QObject::tr("NTeam = '%1'").arg(ui->team_1->text()));
    model->select();
    ui->tableView->setModel(model);
    QSqlQuery query ;
    query.exec( QObject :: tr( "select pname from player where NTeam = %1" ).arg(ui->team_1->text()));
    if(query.next()){
        qDebug() << query.value(0) << query.value(1).toString();
    }
    resize(1177,477);
}

