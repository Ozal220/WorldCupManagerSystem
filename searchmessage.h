#ifndef SEARCHMESSAGE_H
#define SEARCHMESSAGE_H

#include <QWidget>
#include <QSqlQueryModel>

namespace Ui {
class SearchMessage;
}

class SearchMessage : public QWidget
{
    Q_OBJECT

public:
    explicit SearchMessage(QWidget *parent = 0);
    ~SearchMessage();

private slots:
    void on_searchTeam_clicked();

    void on_searchPlayer_clicked();

    void on_TeamLineEdit_textChanged(const QString &arg1);

    void on_playerLineEdit_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::SearchMessage *ui;
    QSqlQueryModel *model = 0;
};

#endif // SEARCHMESSAGE_H
