#include "managerwindow.h"
#include "ui_managerwindow.h"
#include "qss.h"
ManagerWindow::ManagerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManagerWindow)
{
    ui->setupUi(this);

    // 加载QSS样式
    CommonHelper::setStyle("style.qss");
    QButtonGroup *pButtonGroup = new QButtonGroup();
    pButtonGroup->addButton(ui->matchDays);
    pButtonGroup->addButton(ui->score);
    pButtonGroup->addButton(ui->pushButton_4);
    // 设置互斥
    pButtonGroup->setExclusive(true);
    ui->matchDays->setFlat(true);
    ui->pushButton_4->setFlat(true);
    ui->score->setFlat(true);
}

ManagerWindow::~ManagerWindow()
{
    delete ui;
}
