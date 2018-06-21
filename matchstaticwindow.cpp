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
    map = new QMap<QString, QString>;
    map->insert("澳大利亚","australia");
    map->insert("比利时","belgium");
    map->insert("巴西", "brazil");
    map->insert("哥伦比亚", "colombia");
    map->insert("哥斯达黎加", "costa-rica");
    map->insert("丹麦","denmark");
    map->insert("埃及", "egypt");
    map->insert("英格兰", "england");
    map->insert("法国", "france");
    map->insert("德国", "germany");
    map->insert("冰岛", "iceland");
    map->insert("伊朗", "iran");
    map->insert("日本", "japan");
    map->insert("摩洛哥", "monaco");
    map->insert("巴拿马", "panama");
    map->insert("秘鲁", "peru");
    map->insert("波兰", "poland");
    map->insert("葡萄牙", "portugal");
    map->insert("俄罗斯", "russian");
    map->insert("韩国", "south-korea");
    map->insert("西班牙", "spain");
    map->insert("瑞典", "sweden");
    map->insert("乌拉圭","uruguay");

    setSession(session);
    setTeam(team_1, team_2);
    resize(760, this->height());
}

MatchStaticWindow::~MatchStaticWindow()
{
    delete ui;
}

void MatchStaticWindow::setTeam(QString team_1, QString team_2){
    thisTeam_1 = team_1;
    thisTeam_2 = team_2;

    QString pix_1 = (*map)[team_1];
    if(NULL != pix_1){
        QPixmap pixmap1(pix_1);
        ui->team_1->setPixmap(pixmap1);

    }
    else
        ui->team_1->setText(team_1);

    QString pix_2 = (*map)[team_2];
    if(NULL != pix_2){
        QPixmap pixmap2(pix_2);
        ui->team_2->setPixmap(pixmap2);
    }
    else
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
                   .arg(thisSession).arg(goalPlayerName).arg(thisTeam_1).arg(time));
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
                   .arg(thisSession).arg(goalPlayerName).arg(thisTeam_2).arg(time));
    }
    // 如果某一队进球人数 >= 比分，则将该队添加球员按钮设为无法点击，从而保证不出错
    if(goallerCount_2 >= ui->goal_2->value())
        ui->pushButton_2->setEnabled(false);
}

void MatchStaticWindow::on_pushButton_3_clicked()
{
    resize(760, 515);
}

void MatchStaticWindow::on_pushButton_4_clicked()
{
    int ok = QMessageBox::warning(this,"提示","确定将比分上传到数据库？",QMessageBox::No,QMessageBox::Yes);
    if(QMessageBox::Yes == ok){
        QSqlQuery Query;
        Query.exec(QObject::tr("insert into match_score(场次, 主队进球, 客队进球) values ('%1', '%2', '%3');")
                   .arg(thisSession).arg(ui->goal_1->text().toInt()).arg(ui->goal_2->text().toInt()));
    }
}
