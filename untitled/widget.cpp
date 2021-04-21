#include "widget.h"
#include "ui_widget.h"
#include <string>
#include <stdlib.h>

int groop = 1;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./addrbooks.db");
    db.open();
    query = new QSqlQuery(db);

    QSqlQuery* query = new QSqlQuery();  // Добавление в комбобокс
    query -> exec("SELECT name FROM prj_group");
    while(query -> next()){
        ui -> comboBox -> addItem(query -> value(0).toString());
    }

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_comboBox_currentIndexChanged(int index)
{
    switch(index) {

    case 1: {

        groop = 1;

        ui->listWidget->clear();  // Отчистка виджета

        QSqlQuery query("SELECT family, first_name FROM prj_group_addrbook WHERE prj_group_id = 1");

        if(!query.exec()) { qDebug("---------"); } //проверка на правильность запроса

        while (query.next()) {  // вывод в листвиджет
            QString family = query.value(0).toString();
            QString first_name = query.value(1).toString();
            ui->listWidget->addItem(family + " " + first_name);
        }

        break;
    }

    case 2:
    {

        groop = 2;

        ui->listWidget->clear();

        QSqlQuery query("SELECT family, first_name FROM prj_group_addrbook WHERE prj_group_id = 2");

        if(!query.exec()) { qDebug("---------"); }

        while (query.next()) {
            QString family = query.value(0).toString();
            QString first_name = query.value(1).toString();
            ui->listWidget->addItem(family + " " + first_name);
        }

        break;
    }
    case 3:
    {
        groop = 3;

        ui->listWidget->clear();

        QSqlQuery query("SELECT family, first_name FROM prj_group_addrbook WHERE prj_group_id = 3");

        if(!query.exec()) { qDebug("---------"); }

        while (query.next()) {
            QString family = query.value(0).toString();
            QString first_name = query.value(1).toString();
            ui->listWidget->addItem(family + " " + first_name);
        }

        break;
    }
    case 4:
    {
        groop = 4;

        ui->listWidget->clear();

        QSqlQuery query("SELECT family, first_name FROM prj_group_addrbook WHERE prj_group_id = 4");

        if(!query.exec()) { qDebug("---------"); }

        while (query.next()) {
            QString family = query.value(0).toString();
            QString first_name = query.value(1).toString();
            ui->listWidget->addItem(family + " " + first_name);
        }

        break;
    }
    default:
        ui->listWidget->clear();
    }
}


void Widget::on_pushButton_clicked() //Add
{
    if (ui -> lineEdit_2 -> text() == "") {
        QMessageBox::information(this, tr("Error"), tr("Insert famile and first name user pls!!!"));
        return;
    }

    QString full_name =  (ui -> lineEdit_2 -> text());
    std::string lay1 = full_name.toStdString();
    std::string lay2 = "";
    std::string lay3 = "";
    bool OK = false;

    for (int i = 0; i < lay1.length(); i++) {
        if (lay1[i] == ' ') { OK = true; }
        if (OK == true) { lay3 += lay1[i]; }
        else { lay2 += lay1[i]; }
    }

    std::string ss = std::to_string(groop);

    std::string insert = "INSERT INTO prj_group_addrbook (addrbook_type_id, prj_group_id, family, first_name) VALUES ('1', '"+ss+"', '"+lay2+"', '"+lay3+"')" ;
    QString str = QString::fromUtf8(insert.c_str());

    QSqlQuery query (str);

}

void Widget::on_pushButton_3_clicked() //Rename
{

}

void Widget::on_pushButton_2_clicked() //Delete
{
    QListWidgetItem *item = ui->listWidget->item(ui->listWidget->currentRow());

    QString full_name = item->text();
    std::string lay1 = full_name.toStdString();
    std::string lay2 = "";
    std::string lay3 = "";
    bool OK = false;

    for (int i = 0; i < lay1.length(); i++) {
        if (lay1[i] == ' ') { OK = true; }
        if (OK == true) { lay3 += lay1[i]; }
        else { lay2 += lay1[i]; }
    }

    std::string delet = "DELETE FROM prj_group_addrbook WHERE family = '"+lay2+"' or  first_name = '"+lay3+"'" ;
    QString str = QString::fromUtf8(delet.c_str());

    QSqlQuery query (str);

    ui->listWidget->takeItem (ui->listWidget->currentRow());
}

void Widget::on_pushButton_4_clicked() //Search
{
    if (ui -> lineEdit -> text() == "") {
        QMessageBox::information(this, tr("Error"), tr("Insert user pls!!!"));
        return;
    }

    QString full_name =  (ui -> lineEdit -> text());
    std::string lay1 = full_name.toStdString();
    std::string lay2 = "";
    std::string lay3 = "";
    bool OK = false;

    for (int i = 0; i < lay1.length(); i++) {
        if (lay1[i] == ' ') { OK = true; }
        else {
        if (OK == true) { lay3 += lay1[i]; }
        else { lay2 += lay1[i]; }
        }
    }

    QStringList items = full_name.split(' ');
    QStringListIterator it(items);
    std::string select = "SELECT family, first_name FROM prj_group_addrbook WHERE family = '"+lay2+"' or  first_name = '"+lay3+"' or family = '"+lay3+"' or  first_name = '"+lay2+"' ";
    QString str = QString::fromUtf8(select.c_str());
    QSqlQuery query (str);

    if (!query.exec()) {
        QMessageBox::information(this, tr("Error"), tr("User is not in the database"));
        return;
    }
    else {
        ui -> listWidget -> clear();
        while (query.next()) {
            QString family = query.value(0).toString();
            QString first_name = query.value(1).toString();
            ui->listWidget->addItem(family + " " + first_name);
        }
    }
}
