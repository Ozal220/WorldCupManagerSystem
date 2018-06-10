#ifndef MATCHVIEWFORM_H
#define MATCHVIEWFORM_H

#include <QWidget>
#include <QSqlTableModel>
#include <QMessageBox>
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

signals:
    void unenable();

private:
    Ui::MatchViewForm *ui;
    QSqlTableModel *model = 0;
};

#endif // MATCHVIEWFORM_H
