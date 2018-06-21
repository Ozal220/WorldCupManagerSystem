#include "mainWindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(this->width(),this->height());                     // 禁止拖动窗口大小
    this->setWindowFlags(Qt::FramelessWindowHint);
    setWindowTitle("World Cup!");
    setWindowIcon(QIcon("icon.ico"));
    ui->connectLable->setVisible(false);
    setWindowFlags(Qt::WindowStaysOnTopHint);
    // 加载QSS样式
    CommonHelper::setStyle("style.qss");
    connectMySql();
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

void MainWindow::on_fansButton_clicked(){
    this->hide();//主界面隐藏
    fansWin = new fansWindow();
    fansWin->show();
}

void MainWindow::on_managerButton_clicked()
{
    this->setVisible(false);//主界面隐藏
    mLogin = new managerLogin();
    connect(mLogin, SIGNAL(ShowSignal()), this, SLOT(reShow()));
    connect(mLogin, SIGNAL(ManagerLoginSignal()), this, SLOT(closeManagerLogin()));
    mLogin->show();
}

void MainWindow::closeManagerLogin()
{
//    mLogin->close();
    mWindow = new ManagerWindow();
    mWindow->show();
}

void MainWindow::reShow(){
    this->show();
}

bool MainWindow::connectMySql(){

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("worldcup");
    bool ok = db.open("root","root");
    if(ok){
          qDebug()<<"mySql is connected";
          ui->connectLable->setText("数据库连接成功");
          return true;
    }else{
          //QMessageBox::warning(NULL,"警告","无法连接数据库");
          return false;
    }
}
