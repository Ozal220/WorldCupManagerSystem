#include "mainWindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("World Cup!");
    setWindowIcon(QIcon("icon.ico"));
    ui->connectLable->setVisible(false);
    setWindowFlags(Qt::WindowStaysOnTopHint);
    QPixmap pixmap("icon-worldCup");
    ui->image->setPixmap(pixmap);
    ui->image->setFixedSize(50, 50);
    ui->image->setScaledContents(true);

    connectMySql();
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

void MainWindow::on_managerButton_clicked()
{
    this->setVisible(false);//主界面隐藏
    mLogin = new managerLogin(this);
    connect(mLogin, SIGNAL(ShowSignal()), this, SLOT(reShow()));
    connect(mLogin, SIGNAL(ManagerLoginSignal()), this, SLOT(closeManagerLogin()));
    mLogin->show();
}

void MainWindow::closeManagerLogin()
{
    mLogin->close();
    mWindow = new ManagerWindow(this);
    mWindow->show();
}

void MainWindow::reShow(){
    this->setVisible(true);
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
