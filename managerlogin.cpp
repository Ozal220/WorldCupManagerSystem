#include "managerlogin.h"
#include "ui_managerlogin.h"
#include "sqlController.h"
#include "managerwindow.h"
#include <QDebug>
managerLogin::managerLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::managerLogin)
{
    ui->setupUi(this);
    setWindowTitle("World Cup!");
    setWindowIcon(QIcon("icon.ico"));
    this->setAttribute(Qt::WA_DeleteOnClose,1);
    ui->warningLabel->setVisible(false);
    ui->nameLineEdit->setPlaceholderText(QString::fromStdString("请输入账号"));
    ui->pswLineEdit->setPlaceholderText(QString::fromStdString("请输入密码"));
    //当用户在密码输入框输入后才使“登陆”按钮enabled true
    ui->loginButton->setEnabled(false);
    connect(ui->pswLineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(enableLoginButton(const QString&)));
}

managerLogin::~managerLogin()
{
    delete ui;
}


void managerLogin::on_returnButton_clicked()
{
    emit sendShowSignal();
    this->close();
}

void managerLogin::enableLoginButton(const QString& psw){
    ui->loginButton->setEnabled(!psw.isEmpty());
}


void managerLogin::on_loginButton_clicked()
{
    sqlController *sqlCheck = new sqlController;
    bool success = sqlCheck->checkUser(ui->nameLineEdit->text(), ui->pswLineEdit->text());
    if(success){
//        qDebug() << "success1\n";
        this->hide();
        ManagerWindow *mWindow = new ManagerWindow(this);
        mWindow->show();
        //emit sendCloseSignal();
    }
    else
        ui->warningLabel->setVisible(true);
}
