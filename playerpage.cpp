#include "playerpage.h"
#include "ui_playerpage.h"

playerPage::playerPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playerPage)
{
    ui->setupUi(this);
}

playerPage::~playerPage()
{
    delete ui;
}
