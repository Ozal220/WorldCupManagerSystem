#ifndef SCOREPAGE_H
#define SCOREPAGE_H

#include <QWidget>
#include <QSqlTableModel>
#include <QMessagebox>
#include <QDebug>
#include "mymodel.h"
#include <QAbstractItemView>

namespace Ui {
class scorePage;
}

class scorePage : public QWidget
{
    Q_OBJECT

public:
    explicit scorePage(QWidget *parent = 0);
    void setButtonsHide();
    void setAllEditStrategy(QSqlTableModel::EditStrategy strategy);  //设置保存策略
    void setAllselectionBehavior(QAbstractItemView::SelectionBehavior Behavior);
    void setAllEditTriggers(QAbstractItemView::EditTrigger triggers);
    ~scorePage();

private slots:
    void on_submitA_clicked();

    void on_revertA_clicked();

    void on_revertB_clicked();

    void on_submitB_clicked();

    void on_revertC_clicked();

    void on_submitC_clicked();

    void on_revertD_clicked();

    void on_submitD_clicked();

    void on_submitF_clicked();

    void on_submitH_clicked();

    void on_revertE_clicked();

    void on_submitE_clicked();

    void on_revertF_clicked();

    void on_revertG_clicked();

    void on_submitG_clicked();

    void on_revertH_clicked();

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
