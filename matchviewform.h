#ifndef MATCHVIEWFORM_H
#define MATCHVIEWFORM_H

#include <QWidget>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QDate>
#include <QTime>
#include <matchstaticwindow.h>
#include <staticforfans.h>
#include <QMap>
namespace Ui {
class MatchViewForm;
}

class MatchViewForm : public QWidget
{
    Q_OBJECT

public:
    explicit MatchViewForm(QWidget *parent = 0);
    void setVisitorMode();
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

    void on_staticButton_clicked();

    void on_visitorButton_clicked();

signals:
    void unenable();
    void autoAddDateTime();
    void staticWindowClose();

private:
    Ui::MatchViewForm *ui;
    QSqlTableModel *model = 0;
    MatchStaticWindow *staticWindow = 0;
    staticForFans *fansStatic = 0;
    QTime Time;
    QDate Date;
};

#endif // MATCHVIEWFORM_H
