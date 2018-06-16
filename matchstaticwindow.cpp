#include "matchstaticwindow.h"
#include "ui_matchstaticwindow.h"
#include <QDebug>
#include <QSqlQuery>
#include <QInputDialog>
#include <QMessageBox>

MatchStaticWindow::MatchStaticWindow(QString session, QString team_1, QString team_2, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MatchStaticWindow)
{
    ui->setupUi(this);
//    setFixedSize(760, this->height());                     // 禁止拖动窗口大小
    setSession(session);
    setTeam(team_1, team_2);
    resize(760, this->height());
    ui->tableView_2->setColumnWidth(1,5);

}

MatchStaticWindow::~MatchStaticWindow()
{
    delete ui;
}

void MatchStaticWindow::setTeam(QString team_1, QString team_2){
    ui->team_1->setText(team_1);
    ui->team_2->setText(team_2);
    model = new QSqlQueryModel(this);
    model->setQuery(QObject::tr("select pname, pnumber from player where NTeam = '%1'" ).arg(team_1));
    model_2 = new QSqlQueryModel(this);
    model_2->setQuery(QObject::tr("select pname, pnumber from player where NTeam = '%1'" ).arg(team_2));
}

void MatchStaticWindow::setSession(QString session){
    thisSession = session;
}

void MatchStaticWindow::on_goal_1_valueChanged(int arg1)
{
    if(arg1 >= 0 && arg1 > goallerCount_1){
        ui->players_1->setEnabled(true);
        ui->pushButton->setEnabled(true);
    }
}

void MatchStaticWindow::on_goal_2_valueChanged(int arg2)
{
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
    resize(1020, 515);
}

void MatchStaticWindow::on_players_2_clicked()
{
    ui->tableView_2->setModel(model_2);
    ui->pushButton_2->show();
    ui->pushButton->hide();
    resize(1020, 515);
}

void MatchStaticWindow::on_pushButton_clicked()
{
    bool isOk;
    int time = QInputDialog::getInt(NULL, tr("time"), tr(" 进球时间 "), 1, 1, 125, 1, &isOk);
    QString strTime = QString::number(time, 10) + "'";
    if(isOk){
        int row = ui->tableView_2->currentIndex().row();
        QString goalPlayerName = ui->tableView_2->model()->index(row, 0).data().toString();
        if(goalPlayerName != NULL){
            ui->textBrowser->append(goalPlayerName + " " + strTime);
            goallerCount_1++;
        }
        QSqlQuery Query;
        Query.exec(QObject::tr("insert into scorer(场次, 球员, 球队, 进球时间) values ('%1', '%2', '%3', '%4');")
                   .arg(thisSession).arg(goalPlayerName).arg(ui->team_1->text()).arg(time));
    }
    if(goallerCount_1 >= ui->goal_1->value())
        ui->pushButton->setEnabled(false);
}

void MatchStaticWindow::on_pushButton_2_clicked()
{
    bool isOk;
    int time = QInputDialog::getInt(NULL, tr("time"), tr(" 进球时间 "), 1, 1, 125, 1, &isOk);
    QString strTime = QString::number(time, 10) + "'";
    if(isOk){
        int row = ui->tableView_2->currentIndex().row();
        QString goalPlayerName = ui->tableView_2->model()->index(row, 0).data().toString();
        if(goalPlayerName != NULL){
            ui->textBrowser_2->append(goalPlayerName + " " + strTime);
            goallerCount_2++;
        }
        QSqlQuery Query;
        Query.exec(QObject::tr("insert into scorer(场次, 球员, 球队, 进球时间) values ('%1', '%2', '%3', '%4');")
                   .arg(thisSession).arg(goalPlayerName).arg(ui->team_2->text()).arg(time));
    }
    // 如果某一队进球人数 >= 比分，则将该队添加球员按钮设为无法点击，从而保证不出错
    if(goallerCount_2 >= ui->goal_2->value())
        ui->pushButton_2->setEnabled(false);
}

void MatchStaticWindow::on_pushButton_3_clicked()
{
    resize(760, 515);
}
