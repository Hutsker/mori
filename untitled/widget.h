#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QListWidget>
#include <QString>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <QStringList>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Widget *ui;
    QSqlDatabase db;
    QSqlQuery *query;

};
#endif // WIDGET_H
