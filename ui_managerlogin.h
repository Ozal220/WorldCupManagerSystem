/********************************************************************************
** Form generated from reading UI file 'managerlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERLOGIN_H
#define UI_MANAGERLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_managerLogin
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLineEdit *nameLineEdit;
    QLineEdit *pswLineEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *loginButton;
    QPushButton *returnButton;
    QLabel *warningLabel;

    void setupUi(QDialog *managerLogin)
    {
        if (managerLogin->objectName().isEmpty())
            managerLogin->setObjectName(QStringLiteral("managerLogin"));
        managerLogin->resize(600, 400);
        gridLayoutWidget = new QWidget(managerLogin);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(170, 120, 281, 151));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        nameLineEdit = new QLineEdit(gridLayoutWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        gridLayout_2->addWidget(nameLineEdit, 0, 1, 1, 1);

        pswLineEdit = new QLineEdit(gridLayoutWidget);
        pswLineEdit->setObjectName(QStringLiteral("pswLineEdit"));
        pswLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(pswLineEdit, 1, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font:  11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        loginButton = new QPushButton(managerLogin);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(370, 330, 81, 31));
        loginButton->setCursor(QCursor(Qt::ArrowCursor));
        returnButton = new QPushButton(managerLogin);
        returnButton->setObjectName(QStringLiteral("returnButton"));
        returnButton->setGeometry(QRect(500, 20, 93, 28));
        warningLabel = new QLabel(managerLogin);
        warningLabel->setObjectName(QStringLiteral("warningLabel"));
        warningLabel->setGeometry(QRect(170, 280, 241, 41));
        warningLabel->setStyleSheet(QLatin1String("color: rgb(163, 81, 73);\n"
"font: 9pt \"Consolas\";"));

        retranslateUi(managerLogin);

        QMetaObject::connectSlotsByName(managerLogin);
    } // setupUi

    void retranslateUi(QDialog *managerLogin)
    {
        managerLogin->setWindowTitle(QApplication::translate("managerLogin", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("managerLogin", "\350\264\246\345\217\267:", Q_NULLPTR));
        label_2->setText(QApplication::translate("managerLogin", "\345\257\206\347\240\201:", Q_NULLPTR));
        loginButton->setText(QApplication::translate("managerLogin", "\347\231\273\351\231\206", Q_NULLPTR));
        returnButton->setText(QApplication::translate("managerLogin", "\350\277\224\345\233\236", Q_NULLPTR));
        warningLabel->setText(QApplication::translate("managerLogin", "\350\264\246\345\217\267\346\210\226\345\257\206\347\240\201\351\224\231\350\257\257,\350\257\267\351\207\215\346\226\260\350\276\223\345\205\245...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class managerLogin: public Ui_managerLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERLOGIN_H
