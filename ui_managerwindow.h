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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManagerWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *score;
    QPushButton *matchDays;
    QPushButton *pushButton_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ManagerWindow)
    {
        if (ManagerWindow->objectName().isEmpty())
            ManagerWindow->setObjectName(QStringLiteral("ManagerWindow"));
        ManagerWindow->resize(1000, 800);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ManagerWindow->setWindowIcon(icon);
        ManagerWindow->setStyleSheet(QStringLiteral("background-color: rgb(240, 245, 249);"));
        ManagerWindow->setIconSize(QSize(100, 100));
        centralwidget = new QWidget(ManagerWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1011, 111));
        label->setStyleSheet(QStringLiteral("background-color: rgb(65, 110, 162);"));
        score = new QPushButton(centralwidget);
        score->setObjectName(QStringLiteral("score"));
        score->setGeometry(QRect(420, 80, 81, 30));
        score->setCursor(QCursor(Qt::PointingHandCursor));
        score->setStyleSheet(QString::fromUtf8("background-color: rgb(65, 110, 162);\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"color: rgb(248, 250, 255);"));
        score->setCheckable(true);
        score->setFlat(true);
        matchDays = new QPushButton(centralwidget);
        matchDays->setObjectName(QStringLiteral("matchDays"));
        matchDays->setGeometry(QRect(240, 80, 81, 30));
        matchDays->setCursor(QCursor(Qt::PointingHandCursor));
        matchDays->setFocusPolicy(Qt::TabFocus);
        matchDays->setAutoFillBackground(false);
        matchDays->setStyleSheet(QString::fromUtf8("background-color: rgb(65, 110, 162);\n"
"\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"color: rgb(248, 250, 255);"));
        matchDays->setIcon(icon);
        matchDays->setCheckable(true);
        matchDays->setChecked(true);
        matchDays->setFlat(true);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(580, 80, 131, 30));
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(65, 110, 162);\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"color: rgb(248, 250, 255);"));
        pushButton_4->setCheckable(true);
        pushButton_4->setFlat(true);
        ManagerWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ManagerWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ManagerWindow->setStatusBar(statusbar);

        retranslateUi(ManagerWindow);

        matchDays->setDefault(false);


        QMetaObject::connectSlotsByName(ManagerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ManagerWindow)
    {
        ManagerWindow->setWindowTitle(QApplication::translate("ManagerWindow", "\344\270\226\347\225\214\346\235\257\346\225\260\346\215\256\347\256\241\347\220\206", Q_NULLPTR));
        label->setText(QString());
        score->setText(QApplication::translate("ManagerWindow", "\347\247\257\345\210\206\346\246\234", Q_NULLPTR));
        matchDays->setText(QApplication::translate("ManagerWindow", "\350\265\233\347\250\213", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("ManagerWindow", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ManagerWindow: public Ui_ManagerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERWINDOW_H
