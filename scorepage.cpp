#include "scorepage.h"
#include "ui_scorepage.h"

scorePage::scorePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::scorePage)
{
    ui->setupUi(this);
}

scorePage::~scorePage()
{
    delete ui;
}
