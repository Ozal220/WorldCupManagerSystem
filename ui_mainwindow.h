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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *connectLable;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *managerButton;
    QPushButton *fansButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(600, 400);
        MainWindow->setMouseTracking(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        connectLable = new QLabel(centralWidget);
        connectLable->setObjectName(QStringLiteral("connectLable"));
        connectLable->setGeometry(QRect(460, 360, 121, 20));
        connectLable->setStyleSheet(QLatin1String("\n"
"color: rgb(104, 104, 104);"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 601, 401));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(100, 0, 100, 0);
        managerButton = new QPushButton(verticalLayoutWidget);
        managerButton->setObjectName(QStringLiteral("managerButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        managerButton->setFont(font);
        managerButton->setCursor(QCursor(Qt::PointingHandCursor));
        managerButton->setAutoFillBackground(true);
        managerButton->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(148, 148, 148);\n"
"\n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"selection-background-color: rgb(76, 76, 76);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/icons8-sql-database-administrators-group-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        managerButton->setIcon(icon);
        managerButton->setIconSize(QSize(50, 50));

        verticalLayout->addWidget(managerButton);

        fansButton = new QPushButton(verticalLayoutWidget);
        fansButton->setObjectName(QStringLiteral("fansButton"));
        fansButton->setCursor(QCursor(Qt::PointingHandCursor));
        fansButton->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"selection-color: rgb(223, 223, 223);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/icons8-soccer-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        fansButton->setIcon(icon1);
        fansButton->setIconSize(QSize(50, 50));

        verticalLayout->addWidget(fansButton);

        MainWindow->setCentralWidget(centralWidget);
        verticalLayoutWidget->raise();
        connectLable->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        connectLable->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\346\255\243\345\234\250\350\277\236\346\216\245...", Q_NULLPTR));
        managerButton->setText(QApplication::translate("MainWindow", "  \346\210\221\346\230\257\350\256\260\345\275\225\345\221\230", Q_NULLPTR));
        fansButton->setText(QApplication::translate("MainWindow", "\346\210\221\346\230\257\347\220\203\350\277\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
