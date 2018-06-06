#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool connectMySql();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_managerButton_clicked();
    void reShow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
