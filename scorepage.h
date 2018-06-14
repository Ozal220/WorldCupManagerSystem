#ifndef SCOREPAGE_H
#define SCOREPAGE_H

#include <QWidget>
#include <QSqlTableModel>
#include <QMessagebox>
#include <QDebug>
#include "mymodel.h"

namespace Ui {
class scorePage;
}

class scorePage : public QWidget
{
    Q_OBJECT

public:
    explicit scorePage(QWidget *parent = 0);
    ~scorePage();

private slots:
    void on_submitA_clicked();

    void on_revertA_clicked();

private:
    Ui::scorePage *ui;
    QSqlTableModel *groupModel = 0;
    QSqlTableModel *model_A = 0;
    QSqlTableModel *model_B = 0;
    QSqlTableModel *model_C = 0;
    QSqlTableModel *model_D = 0;
    QSqlTableModel *model_E = 0;
    QSqlTableModel *model_F = 0;
    QSqlTableModel *model_G = 0;
    QSqlTableModel *model_H = 0;
    void setTable(const QChar groupName);
};

#endif // SCOREPAGE_H
