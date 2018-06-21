#include "themvps.h"
#include "ui_themvps.h"

theMVPs::theMVPs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::theMVPs)
{
    ui->setupUi(this);
    model = new QSqlQueryModel(this);
    model->setQuery(QObject::tr("select 球员, 球队, COUNT(*) as 进球数 "
                                "from scorer "
                                "group by 球员 "
                                "order by 进球数 DESC ;" ));
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0, 300);
    ui->tableView->setColumnWidth(1, 300);
    ui->tableView->setColumnWidth(2, 300);
}

theMVPs::~theMVPs()
{
    delete ui;
}
