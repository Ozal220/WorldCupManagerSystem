#ifndef SQLCONTROLLER_H
#define SQLCONTROLLER_H

#include<QSqlDatabase>
#include<QString>
//#include<QMessageBox>
#include<QSqlQuery>
#include<qDebug>
class sqlController{

public:
    bool checkUser(const QString &, const QString &);
};

bool sqlController::checkUser(const QString &name, const QString &psw){
    QString selectStr = "select NAME, PSW from recorders;";
    QSqlQuery query;

    if(!query.exec(selectStr)){
//        QMessageBox::warning(NULL,"错误", "查询user失败!");

        return false;
    }
    else
    {
        query.seek(-1);
        while(query.next()){
            qDebug() << query.value(0) << query.value(1);
            if(query.value(0) == name && query.value(1) == psw)
            {
                qDebug() << "found user!\n";
                return true;
            }
        }
        qDebug() << "输入错误，请重新输入\n";
    }
    return false;
}

#endif
