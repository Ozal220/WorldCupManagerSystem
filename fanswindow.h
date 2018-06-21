#ifndef FANSWINDOW_H
#define FANSWINDOW_H

#include <QWidget>

#include "scorepage.h"
#include "themvps.h"
#include "searchmessage.h"
#include "matchviewform.h"

namespace Ui {
class fansWindow;
}

class fansWindow : public QWidget
{
    Q_OBJECT

public:
    explicit fansWindow(QWidget *parent = 0);
    ~fansWindow();

private slots:
    void on_searchButton_clicked();

    void on_matchDays_clicked();

    void on_scoreButton_clicked();

    void on_playerScore_clicked();

private:
    Ui::fansWindow *ui;
};

#endif // FANSWINDOW_H
