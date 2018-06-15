#include "matchstaticwindow.h"
#include "ui_matchstaticwindow.h"
#include <QDebug>
#include <QSqlQuery>
MatchStaticWindow::MatchStaticWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MatchStaticWindow)
{
    ui->setupUi(this);
//    setFixedSize(this->width(), this->height());                     // 禁止拖动窗口大小
    setBaseSize(this->width(), this->height());
    resize(760, this->height());
}

MatchStaticWindow::~MatchStaticWindow()
{
    delete ui;
}

void MatchStaticWindow::setTeam(QString team_1, QString team_2){
    ui->team_1->setText(team_1);
    ui->team_2->setText(team_2);

    model = new QSqlQueryModel(this);
    model->setQuery(QObject::tr("select pname from player where NTeam = '%1'" ).arg(team_1));

    model_2 = new QSqlQueryModel(this);
    model_2->setQuery(QObject::tr("select pname from player where NTeam = '%1'" ).arg(team_2));
}


void MatchStaticWindow::on_goal_1_valueChanged(int arg1)
{
    qDebug() << "arg1 = " << arg1;
    if(arg1 >= 0 && arg1 > goallerCount_1){
        ui->players_1->setEnabled(true);
        ui->pushButton->setEnabled(true);
    }
}

void MatchStaticWindow::on_goal_2_valueChanged(int arg2)
{
    qDebug() << "arg2 = " << arg2;
    if(arg2 >= 0 && arg2 > goallerCount_2){
        ui->players_2->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
    }
}

void MatchStaticWindow::on_players_1_clicked()
{
    ui->tableView_2->setModel(model);
    ui->pushButton->show();
    ui->pushButton_2->hide();
    resize(1010, 515);
}

void MatchStaticWindow::on_players_2_clicked()
{
    ui->tableView_2->setModel(model_2);
    ui->pushButton_2->show();
    ui->pushButton->hide();
    resize(1010, 515);
}

void MatchStaticWindow::on_pushButton_clicked()
{

    int row = ui->tableView_2->currentIndex().row();
    QString goalPlayerName = ui->tableView_2->model()->index(row, 0).data().toString();
    if(goalPlayerName != NULL){
        ui->textBrowser->append(goalPlayerName);
        goallerCount_1++;
    }
    if(goallerCount_1 >= ui->goal_1->value())
        ui->pushButton->setEnabled(false);
}

void MatchStaticWindow::on_pushButton_2_clicked()
{
    int row = ui->tableView_2->currentIndex().row();
    QString goalPlayerName = ui->tableView_2->model()->index(row, 0).data().toString();
    if(goalPlayerName != NULL){
        ui->textBrowser_2->append(goalPlayerName);
        goallerCount_2++;
    }
    if(goallerCount_2 >= ui->goal_2->value())
        ui->pushButton_2->setEnabled(false);
}

void MatchStaticWindow::on_pushButton_3_clicked()
{
    resize(760, 515);
}
