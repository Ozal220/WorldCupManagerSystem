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
    QStackedWidget *pStackedWidget;
    QPushButton *playerButton;
    QPushButton *teamButton;
    QPushButton *matchDays;
    QPushButton *stadiumButton;
    QPushButton *score;

    void setupUi(QMainWindow *ManagerWindow)
    {
        if (ManagerWindow->objectName().isEmpty())
            ManagerWindow->setObjectName(QStringLiteral("ManagerWindow"));
        ManagerWindow->resize(1200, 900);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ManagerWindow->setWindowIcon(icon);
        ManagerWindow->setStyleSheet(QStringLiteral(""));
        ManagerWindow->setIconSize(QSize(100, 100));
        centralwidget = new QWidget(ManagerWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1200, 80));
        label->setStyleSheet(QStringLiteral("background-color: rgb(65, 110, 162);"));
        pStackedWidget = new QStackedWidget(centralwidget);
        pStackedWidget->setObjectName(QStringLiteral("pStackedWidget"));
        pStackedWidget->setGeometry(QRect(9, 88, 1180, 801));
        playerButton = new QPushButton(centralwidget);
        playerButton->setObjectName(QStringLiteral("playerButton"));
        playerButton->setGeometry(QRect(0, 30, 240, 49));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(playerButton->sizePolicy().hasHeightForWidth());
        playerButton->setSizePolicy(sizePolicy);
        playerButton->setBaseSize(QSize(121, 49));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(12);
        playerButton->setFont(font);
        playerButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/icons8-messi-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        playerButton->setIcon(icon1);
        playerButton->setIconSize(QSize(40, 40));
        playerButton->setCheckable(true);
        playerButton->setFlat(true);
        teamButton = new QPushButton(centralwidget);
        teamButton->setObjectName(QStringLiteral("teamButton"));
        teamButton->setGeometry(QRect(240, 30, 240, 49));
        sizePolicy.setHeightForWidth(teamButton->sizePolicy().hasHeightForWidth());
        teamButton->setSizePolicy(sizePolicy);
        teamButton->setBaseSize(QSize(1, 0));
        teamButton->setFont(font);
        teamButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/icons8-strategy-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        teamButton->setIcon(icon2);
        teamButton->setIconSize(QSize(40, 40));
        teamButton->setCheckable(true);
        teamButton->setFlat(true);
        matchDays = new QPushButton(centralwidget);
        matchDays->setObjectName(QStringLiteral("matchDays"));
        matchDays->setGeometry(QRect(480, 30, 240, 49));
        sizePolicy.setHeightForWidth(matchDays->sizePolicy().hasHeightForWidth());
        matchDays->setSizePolicy(sizePolicy);
        matchDays->setFont(font);
        matchDays->setCursor(QCursor(Qt::PointingHandCursor));
        matchDays->setFocusPolicy(Qt::TabFocus);
        matchDays->setAutoFillBackground(false);
        matchDays->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/icons8-stadium-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        matchDays->setIcon(icon3);
        matchDays->setIconSize(QSize(40, 40));
        matchDays->setCheckable(true);
        matchDays->setChecked(true);
        matchDays->setFlat(true);
        stadiumButton = new QPushButton(centralwidget);
        stadiumButton->setObjectName(QStringLiteral("stadiumButton"));
        stadiumButton->setGeometry(QRect(960, 30, 240, 49));
        sizePolicy.setHeightForWidth(stadiumButton->sizePolicy().hasHeightForWidth());
        stadiumButton->setSizePolicy(sizePolicy);
        stadiumButton->setFont(font);
        stadiumButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/icons8-performance-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        stadiumButton->setIcon(icon4);
        stadiumButton->setIconSize(QSize(40, 40));
        stadiumButton->setCheckable(true);
        stadiumButton->setFlat(true);
        score = new QPushButton(centralwidget);
        score->setObjectName(QStringLiteral("score"));
        score->setGeometry(QRect(720, 30, 240, 49));
        sizePolicy.setHeightForWidth(score->sizePolicy().hasHeightForWidth());
        score->setSizePolicy(sizePolicy);
        score->setFont(font);
        score->setCursor(QCursor(Qt::PointingHandCursor));
        score->setStyleSheet(QStringLiteral(""));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/prefix1/icons8-scoreboard-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        score->setIcon(icon5);
        score->setIconSize(QSize(40, 40));
        score->setCheckable(true);
        score->setFlat(true);
        ManagerWindow->setCentralWidget(centralwidget);

        retranslateUi(ManagerWindow);

        matchDays->setDefault(false);


        QMetaObject::connectSlotsByName(ManagerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ManagerWindow)
    {
        ManagerWindow->setWindowTitle(QApplication::translate("ManagerWindow", "\344\270\226\347\225\214\346\235\257\346\225\260\346\215\256\347\256\241\347\220\206", Q_NULLPTR));
        label->setText(QString());
        playerButton->setText(QApplication::translate("ManagerWindow", "\347\274\226\350\276\221\347\220\203\345\221\230", Q_NULLPTR));
        teamButton->setText(QApplication::translate("ManagerWindow", "\347\274\226\350\276\221\347\220\203\351\230\237", Q_NULLPTR));
        matchDays->setText(QApplication::translate("ManagerWindow", "\347\274\226\350\276\221\350\265\233\347\250\213", Q_NULLPTR));
        stadiumButton->setText(QApplication::translate("ManagerWindow", "\347\274\226\350\276\221\345\234\272\351\246\206", Q_NULLPTR));
        score->setText(QApplication::translate("ManagerWindow", "\347\274\226\350\276\221\347\247\257\345\210\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ManagerWindow: public Ui_ManagerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERWINDOW_H
