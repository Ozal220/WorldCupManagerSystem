#include "mymodel.h"
#include <QDebug>
myModel::myModel(QObject * parent, QSqlDatabase db) : QSqlTableModel(parent,db)
{

}

myModel::~myModel()
{

}

QVariant myModel::data(const QModelIndex &item, int role) const

{
    QVariant value = QSqlQueryModel::data(item, role);
    if(role ==  Qt::TextAlignmentRole )
    {
        value   =   int(Qt::AlignCenter | Qt::AlignHCenter);
        return value;
    }
    return value;
}

bool myModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    QVariant _value = data(index, Qt::TextAlignmentRole);
    if(role ==  Qt::TextAlignmentRole){
            qDebug() << "role";
            return QSqlTableModel::setData(index,_value, (int)Qt::AlignCenter | Qt::AlignHCenter);
        }
        else{
            qDebug() << "else\n" << role << value << _value;
            return QSqlTableModel::setData(index,_value, Qt::UserRole);
        }

}
