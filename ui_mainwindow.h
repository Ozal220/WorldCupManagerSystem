/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *fansButton;
    QPushButton *managerButton;
    QLabel *connectLable;
    QLabel *image;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(600, 400);
        MainWindow->setMouseTracking(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        fansButton = new QPushButton(centralWidget);
        fansButton->setObjectName(QStringLiteral("fansButton"));
        fansButton->setGeometry(QRect(90, 270, 401, 41));
        fansButton->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"selection-color: rgb(223, 223, 223);"));
        managerButton = new QPushButton(centralWidget);
        managerButton->setObjectName(QStringLiteral("managerButton"));
        managerButton->setGeometry(QRect(90, 140, 401, 41));
        managerButton->setAutoFillBackground(true);
        managerButton->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(148, 148, 148);\n"
"\n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"selection-background-color: rgb(76, 76, 76);"));
        connectLable = new QLabel(centralWidget);
        connectLable->setObjectName(QStringLiteral("connectLable"));
        connectLable->setGeometry(QRect(460, 360, 121, 20));
        connectLable->setStyleSheet(QLatin1String("\n"
"color: rgb(104, 104, 104);"));
        image = new QLabel(centralWidget);
        image->setObjectName(QStringLiteral("image"));
        image->setGeometry(QRect(40, 40, 72, 15));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        fansButton->setText(QApplication::translate("MainWindow", "\346\210\221\346\230\257\347\220\203\350\277\267", Q_NULLPTR));
        managerButton->setText(QApplication::translate("MainWindow", "\346\210\221\346\230\257\350\256\260\345\275\225\345\221\230", Q_NULLPTR));
        connectLable->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\345\267\262\345\234\250\350\277\236\346\216\245...", Q_NULLPTR));
        image->setText(QApplication::translate("MainWindow", "image", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
