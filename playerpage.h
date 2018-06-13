#ifndef PLAYERPAGE_H
#define PLAYERPAGE_H

#include <QWidget>
#include <QSqlTableModel>
#include <QMessagebox>
#include <QSqlRecord>
#include <QDebug>
#include <QButtonGroup>
#include <QList>
#include <QComboBox>

namespace Ui {
class playerPage;
}

class playerPage : public QWidget
{
    Q_OBJECT

public:
    explicit playerPage(QWidget *parent = 0);
    ~playerPage();

signals:
    void unenable();

public slots:

    void loadTable(int buttonId);

    void on_ModifRadioButton_clicked(bool checked);

    void on_submitButton_clicked();

    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void enableDeleteButton();

    void unenableDeleteButton();



private slots:
    void on_updateBotton_clicked();

private:
    QSqlTableModel *model = 0;
    QSqlTableModel *teamModel = 0;
    Ui::playerPage *ui;
    QButtonGroup *pButtonGroup = 0;
};

#endif // PLAYERPAGE_H
