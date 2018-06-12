#include "playerpage.h"
#include "ui_playerpage.h"

playerPage::playerPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playerPage)
{
    ui->setupUi(this);

    // 设置互斥的button集代表每一支球队
    pButtonGroup = new QButtonGroup();

    // 从球队表里读球队数据，
    model = new QSqlTableModel(this);
    model->setTable("nationalTeam");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);  //设置保存策略
    model->select(); //查询整张表

    // 有几支球队就添加多少个button, 根据teamGroup 来分到layout里
    for(int i = 0; i < model->rowCount(); i++){
        QPushButton *newTeam = new QPushButton();
        newTeam->setText(model->record(i).value("TName").toString());
        ui->buttonsLayout->addWidget(newTeam);
        pButtonGroup->addButton(newTeam, i);        // 从0开始分配id
    }
    pButtonGroup->setExclusive(true);       //互斥
    pButtonGroup->button(0);

    // 每个button被点击后Model的内容就改变
    connect(pButtonGroup, SIGNAL(buttonClicked(int)), this, SLOT(loadTable(int)));

    // 用槽来实现当选中一行时才enable 删除行按钮
    ui->deleteButton->setEnabled(false);
    connect(ui->modifyTable, SIGNAL(pressed(QModelIndex)), this, SLOT(enableDeleteButton()));
    connect(this, SIGNAL(unenable()), this, SLOT(unenableDeleteButton()));
}

playerPage::~playerPage()
{
    delete ui;
}

void playerPage::loadTable(int buttonId){
    model->setTable("player");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);  //设置保存策略
    model->setFilter(QObject::tr("Nteam = '%1'").arg(pButtonGroup->button(buttonId)->text())); //根据国家队名进行筛选
    model->select();

    ui->modifyTable->setModel(model);
    ui->modifyTable->verticalHeader()->hide();//隐藏第一列序号
    ui->modifyTable->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
}

void playerPage::enableDeleteButton(){
    ui->deleteButton->setEnabled(true);
}

void playerPage::unenableDeleteButton(){
    ui->deleteButton->setEnabled(false);
}

void playerPage::on_ModifRadioButton_clicked(bool checked)
{
    if(checked)
        ui->modifyTable->setEditTriggers(QAbstractItemView::CurrentChanged);
    else
        ui->modifyTable->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
}

void playerPage::on_submitButton_clicked()
{
    if(QMessageBox::Yes == QMessageBox::warning(this,"提示","确定更新数据库？",QMessageBox::No,QMessageBox::Yes)){
        model->submitAll();
    }
}

void playerPage::on_addButton_clicked()
{
    int rowCount =  model->rowCount(); // 获得表的行数
    model->insertRow(rowCount); // 添加一行
    model->setData(model->index(rowCount, 2), model->index(0, 2).data());
}

void playerPage::on_deleteButton_clicked()
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
