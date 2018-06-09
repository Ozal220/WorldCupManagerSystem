#include "managerwindow.h"
#include "ui_managerwindow.h"
#include <QVBoxLayout>
#include "qss.h"
ManagerWindow::ManagerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManagerWindow)
{
    ui->setupUi(this);

    // 设置互斥的button集
    QButtonGroup *pButtonGroup = new QButtonGroup();
    pButtonGroup->addButton(ui->matchDays);
    pButtonGroup->addButton(ui->score);
    pButtonGroup->addButton(ui->teamButton);
    pButtonGroup->addButton(ui->playerButton);
    pButtonGroup->addButton(ui->stadiumButton);
    pButtonGroup->setExclusive(true);       //互斥

    // 加载QSS样式
    CommonHelper::setStyle("style.qss");
    ui->matchDays->setFlat(true);
    ui->teamButton->setFlat(true);
    ui->score->setFlat(true);
    ui->playerButton->setFlat(true);
    ui->stadiumButton->setFlat(true);

    // 加载子页面，加入到StackWidget中
    matchPage = new MatchViewForm();
    m_playerPage = new playerPage();

    // 利用StackWidget来实现子界面切换：赛程，积分，...
    ui->pStackedWidget->addWidget(matchPage);    // 0
    ui->pStackedWidget->addWidget(m_playerPage);     // 1

}

ManagerWindow::~ManagerWindow()
{
    delete ui;
}

void ManagerWindow::on_score_clicked()
{

}

void ManagerWindow::on_matchDays_clicked()
{

    ui->pStackedWidget->setCurrentIndex(0);
}

void ManagerWindow::on_playerButton_clicked()
{
    ui->pStackedWidget->setCurrentIndex(1);
}
