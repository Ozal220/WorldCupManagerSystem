#ifndef MATCHVIEWFORM_H
#define MATCHVIEWFORM_H

#include <QWidget>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QDate>
#include <QTime>
namespace Ui {
class MatchViewForm;
}

class MatchViewForm : public QWidget
{
    Q_OBJECT

public:
    explicit MatchViewForm(QWidget *parent = 0);
    ~MatchViewForm();

private slots:
    void on_ModifRadioButton_clicked(bool checked);

    void on_submitButton_clicked();

    void on_deleteButton_clicked();

    void enableDeleteButton();

    void unenableDeleteButton();

    void on_addButton_clicked();

    void on_revertButton_clicked();

    void autoAdd();

    void checkModify();

signals:
    void unenable();
    void autoAddDateTime();

private:
    Ui::MatchViewForm *ui;
    QSqlTableModel *model = 0;
    QTime Time;
    QDate Date;
};

#endif // MATCHVIEWFORM_H
