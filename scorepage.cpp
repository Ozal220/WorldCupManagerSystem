#include "scorepage.h"
#include "ui_scorepage.h"

scorePage::scorePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::scorePage)
{
    ui->setupUi(this);
    for(int groupName = 'A'; groupName <= 'H'; groupName++){
            setTable((QChar)groupName);
    }

}

void scorePage::setTable(const QChar groupName){
    // 从球队表里读球队数据，
//    QSqlTableModel *groupModel = new QSqlTableModel(this);

    groupModel = new QSqlTableModel(this);
    groupModel->setTable("nationalTeam");
    groupModel->setEditStrategy(QSqlTableModel::OnManualSubmit);  //设置保存策略
    groupModel->setSort(8, Qt::AscendingOrder); //根据分组排序，即第8列，升序排列 ,Qt::DescendingOrder为降序排序
    groupModel->setFilter(QObject::tr("teamGroup = '%1'").arg(groupName)); //根据国家队名进行筛选
    groupModel->select(); //查询整张表
    if(groupName == 'A'){
        model_A = groupModel;
        ui->AtableView->setModel(model_A);
        ui->AtableView->verticalHeader()->setDefaultSectionSize(45);
        ui->AtableView->setEditTriggers(QAbstractItemView::CurrentChanged);
//        qDebug() << "is A";
    }
    else if(groupName == 'B'){
        model_B = groupModel;
        ui->BtableView->setModel(model_B);
        ui->BtableView->verticalHeader()->setDefaultSectionSize(45);
        ui->BtableView->setEditTriggers(QAbstractItemView::CurrentChanged);
//        qDebug() << "is B";
    }
    else if(groupName == 'C'){
        model_C = groupModel;
        ui->CtableView->setModel(model_C);
        ui->CtableView->verticalHeader()->setDefaultSectionSize(45);
        ui->CtableView->setEditTriggers(QAbstractItemView::CurrentChanged);
    }
    else if(groupName == 'D'){
        model_D = groupModel;
        ui->DtableView->setModel(model_D);
        ui->DtableView->verticalHeader()->setDefaultSectionSize(45);
        ui->DtableView->setEditTriggers(QAbstractItemView::CurrentChanged);
    }
    else if(groupName == 'E'){
        model_E = groupModel;
        ui->EtableView_4->setModel(model_E);
        ui->EtableView_4->verticalHeader()->setDefaultSectionSize(45);
        ui->EtableView_4->setEditTriggers(QAbstractItemView::CurrentChanged);
    }
    else if(groupName == 'F'){
        model_F = groupModel;
        ui->FtableView_4->setModel(model_F);
        ui->FtableView_4->verticalHeader()->setDefaultSectionSize(45);
        ui->FtableView_4->setEditTriggers(QAbstractItemView::CurrentChanged);
    }
    else if(groupName == 'G'){
        model_G = groupModel;
        ui->GtableView_5->setModel(model_G);
        ui->GtableView_5->verticalHeader()->setDefaultSectionSize(45);
        ui->GtableView_5->setEditTriggers(QAbstractItemView::CurrentChanged);
    }
    else if(groupName == 'H'){
        model_H = groupModel;
        ui->HtableView_5->setModel(model_H);
        ui->HtableView_5->verticalHeader()->setDefaultSectionSize(45);
        ui->HtableView_5->setEditTriggers(QAbstractItemView::CurrentChanged);
    }
}

scorePage::~scorePage()
{
    delete ui;
}

void scorePage::on_submitA_clicked()
{
    if(QMessageBox::Yes == QMessageBox::warning(this,"提示","确定更新数据库？",QMessageBox::No,QMessageBox::Yes)){
        model_A->submitAll();
    }
}

void scorePage::on_revertA_clicked()
{
    model_A->revertAll();
}
