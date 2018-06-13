#include "managerwindow.h"
#include "ui_managerwindow.h"
#include <QVBoxLayout>
#include "qss.h"
ManagerWindow::ManagerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManagerWindow)
{
    ui->setupUi(this);
    setFixedSize(this->width(),this->height());                     // 禁止拖动窗口大小

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
    p_matchPage = new MatchViewForm();
    p_playerPage = new playerPage();
    p_teamPage = new TeamPage();
    p_scorePage = new scorePage();
    p_stadiumPage = new stadiumPage();

    // 利用StackWidget来实现子界面切换：赛程，积分，...
    ui->pStackedWidget->addWidget(p_playerPage);     // 0
    ui->pStackedWidget->addWidget(p_teamPage);      // 1
    ui->pStackedWidget->addWidget(p_matchPage);    // 2
    ui->pStackedWidget->addWidget(p_scorePage);
    ui->pStackedWidget->addWidget(p_stadiumPage);

    ui->pStackedWidget->setCurrentWidget(p_matchPage); // 首页显示赛程

}

ManagerWindow::~ManagerWindow()
{
    delete ui;
}

void ManagerWindow::on_playerButton_clicked(){
    ui->pStackedWidget->setCurrentIndex(0);
}

void ManagerWindow::on_teamButton_clicked(){
    ui->pStackedWidget->setCurrentIndex(1);
}

void ManagerWindow::on_matchDays_clicked(){

    ui->pStackedWidget->setCurrentIndex(2);
}

void ManagerWindow::on_score_clicked(){
    ui->pStackedWidget->setCurrentIndex(3);
}

void ManagerWindow::on_stadiumButton_clicked(){
    ui->pStackedWidget->setCurrentIndex(4);
}
