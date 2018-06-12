#include "matchviewform.h"
#include "ui_matchviewform.h"

MatchViewForm::MatchViewForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MatchViewForm)
{
    ui->setupUi(this);
    //将数据库中内容加载 tableView, 并设为当点击提交按钮时将tableView内容上传到数据库对应的表
    model = new QSqlTableModel(this);
    model->setTable("matches");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);  //设置保存策略
    model->select(); //查询整张表
    model->setHeaderData(0, Qt::Horizontal, tr("场次")); //更改列名 // 多表操作用 model->setQuery(sql 语句);
    model->setHeaderData(1, Qt::Horizontal, tr("主队"));
    model->setHeaderData(2, Qt::Horizontal, tr("客队"));
    model->setHeaderData(3, Qt::Horizontal, tr("场馆"));
    model->setHeaderData(4, Qt::Horizontal, tr("日期"));
    model->setHeaderData(5, Qt::Horizontal, tr("时间"));
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);//设置更改方式(实时更改还是条件触发更改)
    ui->matchTableView->setModel(model);
    ui->matchTableView->verticalHeader()->hide();//隐藏第一列序号
    ui->matchTableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
//    ui->matchTableView->
    // 用槽来实现当选中一行时才enable 删除行按钮
    ui->deleteButton->setEnabled(false);
    connect(ui->matchTableView, SIGNAL(clicked(QModelIndex)), this, SLOT(enableDeleteButton()));
    connect(this, SIGNAL(unenable()), this, SLOT(unenableDeleteButton()));
}

MatchViewForm::~MatchViewForm()
{
    delete ui;
}

void MatchViewForm::enableDeleteButton(){
    ui->deleteButton->setEnabled(true);
}

void MatchViewForm::unenableDeleteButton(){
    ui->deleteButton->setEnabled(false);
}

void MatchViewForm::on_ModifRadioButton_clicked(bool checked)
{
    if(checked)
        ui->matchTableView->setEditTriggers(QAbstractItemView::CurrentChanged);
    else
        ui->matchTableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
}

void MatchViewForm::on_submitButton_clicked()
{
    int ok = QMessageBox::warning(this,"提示","确定更新数据库？",QMessageBox::No,QMessageBox::Yes);
    if(QMessageBox::Yes == ok){
        model->submitAll();//将缓冲内容提交到数据库
    }
}

void MatchViewForm::on_deleteButton_clicked()
{
    // 删除操作
    int curRow = ui->matchTableView->currentIndex().row();
    // 获取选中的行
    model->removeRow(curRow);
    // 删除该行
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

// 插入操作
void MatchViewForm::on_addButton_clicked()
{
    int rowCount =  model->rowCount(); // 获得表的行数
    model->insertRow(rowCount); // 添加一行
//    model->submitAll();// 记得提交
}
