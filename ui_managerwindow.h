/********************************************************************************
** Form generated from reading UI file 'managerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERWINDOW_H
#define UI_MANAGERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManagerWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *score;
    QPushButton *matchDays;
    QPushButton *stadiumButton;
    QPushButton *playerButton;
    QPushButton *teamButton;
    QStackedWidget *pStackedWidget;

    void setupUi(QMainWindow *ManagerWindow)
    {
        if (ManagerWindow->objectName().isEmpty())
            ManagerWindow->setObjectName(QStringLiteral("ManagerWindow"));
        ManagerWindow->resize(1000, 800);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ManagerWindow->setWindowIcon(icon);
        ManagerWindow->setStyleSheet(QStringLiteral(""));
        ManagerWindow->setIconSize(QSize(100, 100));
        centralwidget = new QWidget(ManagerWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1011, 111));
        label->setStyleSheet(QStringLiteral("background-color: rgb(65, 110, 162);"));
        score = new QPushButton(centralwidget);
        score->setObjectName(QStringLiteral("score"));
        score->setGeometry(QRect(640, 70, 120, 41));
        score->setCursor(QCursor(Qt::PointingHandCursor));
        score->setStyleSheet(QStringLiteral(""));
        score->setCheckable(true);
        score->setFlat(true);
        matchDays = new QPushButton(centralwidget);
        matchDays->setObjectName(QStringLiteral("matchDays"));
        matchDays->setGeometry(QRect(430, 70, 120, 41));
        matchDays->setCursor(QCursor(Qt::PointingHandCursor));
        matchDays->setFocusPolicy(Qt::TabFocus);
        matchDays->setAutoFillBackground(false);
        matchDays->setStyleSheet(QStringLiteral(""));
        matchDays->setIcon(icon);
        matchDays->setCheckable(true);
        matchDays->setChecked(true);
        matchDays->setFlat(true);
        stadiumButton = new QPushButton(centralwidget);
        stadiumButton->setObjectName(QStringLiteral("stadiumButton"));
        stadiumButton->setGeometry(QRect(850, 70, 120, 41));
        stadiumButton->setCursor(QCursor(Qt::PointingHandCursor));
        stadiumButton->setCheckable(true);
        stadiumButton->setFlat(true);
        playerButton = new QPushButton(centralwidget);
        playerButton->setObjectName(QStringLiteral("playerButton"));
        playerButton->setGeometry(QRect(30, 70, 120, 41));
        playerButton->setCursor(QCursor(Qt::PointingHandCursor));
        playerButton->setCheckable(true);
        playerButton->setFlat(true);
        teamButton = new QPushButton(centralwidget);
        teamButton->setObjectName(QStringLiteral("teamButton"));
        teamButton->setGeometry(QRect(220, 70, 120, 41));
        teamButton->setCursor(QCursor(Qt::PointingHandCursor));
        teamButton->setCheckable(true);
        teamButton->setFlat(true);
        pStackedWidget = new QStackedWidget(centralwidget);
        pStackedWidget->setObjectName(QStringLiteral("pStackedWidget"));
        pStackedWidget->setGeometry(QRect(9, 119, 981, 671));
        ManagerWindow->setCentralWidget(centralwidget);

        retranslateUi(ManagerWindow);

        matchDays->setDefault(false);


        QMetaObject::connectSlotsByName(ManagerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ManagerWindow)
    {
        ManagerWindow->setWindowTitle(QApplication::translate("ManagerWindow", "\344\270\226\347\225\214\346\235\257\346\225\260\346\215\256\347\256\241\347\220\206", Q_NULLPTR));
        label->setText(QString());
        score->setText(QApplication::translate("ManagerWindow", "\347\274\226\350\276\221\347\247\257\345\210\206\346\246\234", Q_NULLPTR));
        matchDays->setText(QApplication::translate("ManagerWindow", "\347\274\226\350\276\221\350\265\233\347\250\213", Q_NULLPTR));
        stadiumButton->setText(QApplication::translate("ManagerWindow", "\347\274\226\350\276\221\345\234\272\351\246\206", Q_NULLPTR));
        playerButton->setText(QApplication::translate("ManagerWindow", "\347\274\226\350\276\221\347\220\203\345\221\230", Q_NULLPTR));
        teamButton->setText(QApplication::translate("ManagerWindow", "\347\274\226\350\276\221\347\220\203\351\230\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ManagerWindow: public Ui_ManagerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERWINDOW_H
