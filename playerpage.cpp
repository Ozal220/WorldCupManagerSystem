#include "playerpage.h"
#include "ui_playerpage.h"

playerPage::playerPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playerPage)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this);       //表格只有一个

    // 设置互斥的button集代表每一支球队
    pButtonGroup = new QButtonGroup();

    // 从球队表里读球队数据，
    teamModel = new QSqlTableModel(this);
    teamModel->setTable("nationalTeam");
    teamModel->setEditStrategy(QSqlTableModel::OnManualSubmit);  //设置保存策略
    teamModel->setSort(8, Qt::AscendingOrder); //根据分组排序，即第8列，升序排列 ,Qt::DescendingOrder为降序排序
    teamModel->select(); //查询整张表
    int column = 0;
    int row = 0;
    // 有几支球队就添加多少个button, 根据teamGroup 来分到layout里
    for(int i = 0; i < teamModel->rowCount(); i++){
        column = i / 4;
        row = i % 4;
        QPushButton *newTeam = new QPushButton();        
        ui->buttonGridLayout->addWidget(newTeam, row, column, 1, 1);
        newTeam->setText(teamModel->record(i).value("TName").toString());
        pButtonGroup->addButton(newTeam, i);        // 从0开始分配id
        newTeam->setCursor(Qt::PointingHandCursor);  // 指向手势
    }
    pButtonGroup->setExclusive(true);       //互斥
//    teamModel->clear();
//    teamModel->deleteLater();
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
    qDebug() << pButtonGroup->button(buttonId)->text();

    model->setTable("player");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);  //设置保存策略
    model->setFilter(QObject::tr("Nteam = '%1'").arg(pButtonGroup->button(buttonId)->text())); //根据国家队名进行筛选
    model->setSort(1, Qt::AscendingOrder);          //根据球员号码升序排序
    model->select();

    ui->modifyTable->setModel(model);
    ui->modifyTable->verticalHeader()->hide();//隐藏第一列序号
    ui->modifyTable->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
    ui->modifyTable->horizontalHeader()->setHighlightSections(true);
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

void playerPage::on_updateBotton_clicked()
{
    disconnect(pButtonGroup, SIGNAL(buttonClicked(int)), this, SLOT(loadTable(int)));
    // 删除button 集
    delete pButtonGroup;
    pButtonGroup = new QButtonGroup(this);
    // 从球队表里读球队数据，
    teamModel = new QSqlTableModel(this);
    teamModel->setTable("nationalTeam");
    teamModel->setEditStrategy(QSqlTableModel::OnManualSubmit);  //设置保存策略
    teamModel->setSort(8, Qt::AscendingOrder); //根据分组排序，即第8列，升序排列 ,Qt::DescendingOrder为降序排序
    teamModel->select(); //查询整张表
    int column = 0;
    int row = 0;
    // 有几支球队就添加多少个button, 根据teamGroup 来分到layout里
    for(int i = 0; i < teamModel->rowCount(); i++){
        column = i / 4;
        row = i % 4;
        QPushButton *newTeam = new QPushButton();
        ui->buttonGridLayout->addWidget(newTeam, row, column, 1, 1);
        newTeam->setText(teamModel->record(i).value("TName").toString());
        pButtonGroup->addButton(newTeam, i);        // 从0开始分配id
        newTeam->setCursor(Qt::PointingHandCursor);  // 指向手势
    }
    pButtonGroup->setExclusive(true);       //互斥

    // 每个button被点击后Model的内容就改变
    connect(pButtonGroup, SIGNAL(buttonClicked(int)), this, SLOT(loadTable(int)));
}
