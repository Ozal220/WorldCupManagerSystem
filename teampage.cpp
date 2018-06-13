#include "teampage.h"
#include "ui_teampage.h"
#include <QTime>
#include <QDate>

TeamPage::TeamPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeamPage)
{
    ui->setupUi(this);
    //将数据库中内容加载 tableView, 并设为当点击提交按钮时将tableView内容上传到数据库对应的表
    model = new QSqlTableModel(this);
    model->setTable("nationalTeam");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);  //设置保存策略
    model->select(); //查询整张表
    model->setHeaderData(0, Qt::Horizontal, tr("球队号")); //更改列名 // 多表操作用 model->setQuery(sql 语句);
    model->setHeaderData(1, Qt::Horizontal, tr("球队名"));
    model->setHeaderData(2, Qt::Horizontal, tr("已赛场次"));
    model->setHeaderData(3, Qt::Horizontal, tr("赢"));
    model->setHeaderData(4, Qt::Horizontal, tr("平"));
    model->setHeaderData(5, Qt::Horizontal, tr("输"));
    model->setHeaderData(6, Qt::Horizontal, tr("净胜球"));
    model->setHeaderData(7, Qt::Horizontal, tr("进球"));
    model->setHeaderData(8, Qt::Horizontal, tr("积分"));
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);//设置更改方式(实时更改还是条件触发更改)
    ui->modifyTable->setModel(model);
    ui->modifyTable->verticalHeader()->hide();//隐藏第一列序号
    ui->modifyTable->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑

    // 用槽来实现当选中一行时才enable 删除行按钮
    ui->deleteButton->setEnabled(false);
    connect(ui->modifyTable, SIGNAL(clicked(QModelIndex)), this, SLOT(enableDeleteButton()));
    connect(this, SIGNAL(unenable()), this, SLOT(unenableDeleteButton()));
}

TeamPage::~TeamPage()
{
    delete ui;
}

void TeamPage::enableDeleteButton(){
    ui->deleteButton->setEnabled(true);
}

void TeamPage::unenableDeleteButton(){
    ui->deleteButton->setEnabled(false);
}

void TeamPage::on_ModifRadioButton_clicked(bool checked)
{
    if(checked)
        ui->modifyTable->setEditTriggers(QAbstractItemView::CurrentChanged);
    else
        ui->modifyTable->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
}

void TeamPage::on_submitButton_clicked()
{
    if(QMessageBox::Yes == QMessageBox::warning(this,"提示","确定更新数据库？",QMessageBox::No,QMessageBox::Yes)){
        model->submitAll();
    }
}

void TeamPage::on_addButton_clicked()
{
    int rowCount =  model->rowCount(); // 获得表的行数
    model->insertRow(rowCount); // 添加一行
//    model->

}

void TeamPage::on_deleteButton_clicked()
{
    // 删除操作
    int curRow = ui->modifyTable->currentIndex().row();
    model->removeRow(curRow);
    int ok = QMessageBox::warning(this, tr( "删除当前行!"), tr( "你确定删除当前行吗?"),
                                  QMessageBox::Yes, QMessageBox::No);
    if(ok == QMessageBox::No)
    {
        model->revertAll(); // 如果不删除，则撤销
    }
    else{
        model->submitAll(); // 否则提交，在数据库中删除该行
    }
    emit unenable();
}

