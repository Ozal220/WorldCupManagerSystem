#ifndef TEAMPAGE_H
#define TEAMPAGE_H

#include <QWidget>
#include <QSqlTableModel>
#include <QMessageBox>
namespace Ui {
class TeamPage;
}

class TeamPage : public QWidget
{
    Q_OBJECT

public:
    explicit TeamPage(QWidget *parent = 0);
    ~TeamPage();

public slots:
    void on_ModifRadioButton_clicked(bool checked);

    void on_submitButton_clicked();

//    void on_pushButton_clicked();


private slots:
    void on_addButton_clicked();

//    void on_deleteButton_clicked();

private:
    Ui::TeamPage *ui;
    QSqlTableModel *model = 0;
};

#endif // TEAMPAGE_H
