/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QListWidget *listWidget;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(511, 250);
        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 291, 201));
        comboBox = new QComboBox(Widget);
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(310, 10, 191, 22));
        comboBox->setInsertPolicy(QComboBox::InsertAtCurrent);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(310, 40, 191, 21));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(310, 100, 191, 23));
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(310, 70, 191, 23));
        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(220, 220, 81, 21));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 220, 191, 20));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        comboBox->setItemText(0, QApplication::translate("Widget", "\320\222\321\213\320\261\320\276\321\200 \320\272\320\275\320\270\320\263\320\270", nullptr));

        pushButton->setText(QApplication::translate("Widget", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_2->setText(QApplication::translate("Widget", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_3->setText(QApplication::translate("Widget", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        pushButton_4->setText(QApplication::translate("Widget", "\320\237\320\276\320\270\321\201\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
