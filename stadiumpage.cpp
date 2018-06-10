#include "stadiumpage.h"
#include "ui_stadiumpage.h"

stadiumPage::stadiumPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stadiumPage)
{
    ui->setupUi(this);
}

stadiumPage::~stadiumPage()
{
    delete ui;
}
