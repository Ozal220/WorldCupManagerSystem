#ifndef MYMODEL_H
#define MYMODEL_H

#include <QSqlTableModel>

class myModel : public QSqlTableModel
{
public:
    myModel(QObject * parent = 0, QSqlDatabase db = QSqlDatabase());
    ~myModel();
    QVariant data(const QModelIndex &idx, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
};

#endif // MYMODEL_H
