#include "matchinfo.h"
#include "ui_matchinfo.h"

matchInfo::matchInfo(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::matchInfo)
{
    ui->setupUi(this);
}

matchInfo::~matchInfo()
{
    delete ui;
}
