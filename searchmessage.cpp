#include "searchmessage.h"
#include "ui_searchmessage.h"
#include <QSqlQuery>
#include <QDebug>
SearchMessage::SearchMessage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchMessage)
{
    ui->setupUi(this);
    model = new QSqlQueryModel(this);
    ui->searchPlayer->setEnabled(false);
    ui->searchTeam->setEnabled(false);
}

SearchMessage::~SearchMessage()
{
    delete ui;
}

void SearchMessage::on_searchTeam_clicked()
{
    QSqlQuery query;
    query.prepare("select 主队, 客队, 日期, 时间, 比赛状态 from matches where (主队 = ? or 客队 = ?);");
    query.addBindValue(ui->TeamLineEdit->text());
    query.addBindValue(ui->TeamLineEdit->text());
    query.exec();
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void SearchMessage::on_searchPlayer_clicked()
{

}

void SearchMessage::on_TeamLineEdit_textChanged(const QString &arg1)
{
    ui->searchTeam->setEnabled(true);
}

void SearchMessage::on_playerLineEdit_cursorPositionChanged(int arg1, int arg2)
{

}
