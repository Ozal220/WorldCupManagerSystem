#include "fanswindow.h"
#include "ui_fanswindow.h"

fansWindow::fansWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fansWindow)
{
    ui->setupUi(this);

    // 设置互斥的button集
    QButtonGroup *pButtonGroup = new QButtonGroup();
    pButtonGroup->addButton(ui->matchDays);
    pButtonGroup->addButton(ui->searchButton);
    pButtonGroup->addButton(ui->playerScore);
    pButtonGroup->addButton(ui->scoreButton);
    pButtonGroup->setExclusive(true);       //互斥

    // 加载QSS样式
//    CommonHelper::setStyle("style.qss");
    ui->matchDays->setFlat(true);
    ui->searchButton->setFlat(true);
    ui->playerScore->setFlat(true);
    ui->scoreButton->setFlat(true);

    // -[积分榜] 屏蔽管理员模块特有的修改功能。
    scorePage *p_scorePage = new scorePage();
    p_scorePage->setButtonsHide();
    p_scorePage->setAllEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
    p_scorePage->setAllselectionBehavior(QAbstractItemView::SelectRows);

    // -[赛程信息] 屏蔽管理员特有修改功能
    MatchViewForm *p_matchPage = new MatchViewForm();
    p_matchPage->setVisitorMode();

    // 射手榜
    theMVPs *p_mvpPage = new theMVPs();

    // 搜索页面
    SearchMessage *p_searchPage = new SearchMessage();

    ui->stackedWidget->addWidget(p_searchPage);
    ui->stackedWidget->addWidget(p_matchPage);
    ui->stackedWidget->addWidget(p_scorePage);
    ui->stackedWidget->addWidget(p_mvpPage);
    ui->stackedWidget->setCurrentWidget(p_matchPage);
}

fansWindow::~fansWindow()
{
    delete ui;
}

void fansWindow::on_searchButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void fansWindow::on_matchDays_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void fansWindow::on_scoreButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void fansWindow::on_playerScore_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
