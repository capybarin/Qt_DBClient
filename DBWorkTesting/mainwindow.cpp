#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QChar>
#include <QString>
#include "dialog.h"

#include "windows.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    userLogin="root";
    userPassword="qwerty";
    localPortDB=3306;

    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("mydb");
    db.setHostName("localhost");
    db.setUserName(userLogin);
    db.setPassword(userPassword);
    db.setPort(localPortDB);

}

MainWindow::~MainWindow()
{
    delete Typemodel;
    delete manufa;
    delete detmvc;
    delete detmm;
    delete ui;
}


void MainWindow::on_connectButton_released()
{
    for(int i=0;i<30;i++)
      {
        Sleep(250);
        DBConnectionState = db.open();
        if(true==DBConnectionState)
            break;
      }

    if(true==DBConnectionState)
       {
         ui->statusString->setText("Подключение выполнено !!!");
         Typemodel = new typemodel(this,db);
         ui->tableView->setModel(Typemodel);
         ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
         //ui->tableView->resizeColumnsToContents();

         manufa = new ManufacModel(this,db);
         ui->secondTableView->setModel(manufa);
         ui->secondTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

         detmvc = new DetailMVCMdel(this,db);
         ui->secondTableView_3->setModel(detmvc);
         ui->secondTableView_3->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

         detmm = new Detail_model_modeil(this,db);
         ui->secondTableView_4->setModel(detmm);
         ui->secondTableView_4->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
         Typemodel->select();
         manufa->select();
         detmvc->select();
         detmm->select();

       }

    else
    {
      ui->statusString->setText("Подключение не выполнено."+db.lastError().text());
    }

}



void MainWindow::on_disconectButton_released()
{
    db.close();
}

void MainWindow::on_addButton_released()
{
    QSqlQuery query;
    query.prepare("INSERT INTO  pc_detail_type (pc_detail_type) VALUES(?)");
    query.addBindValue(ui->lineEdit->text());
    if (!query.exec()) {
      ui->statusString->setText("Добавление не выполнено."+db.lastError().text());
    };
}

void MainWindow::on_addButton_2_released()
{
    QSqlQuery query;
    query.prepare("INSERT INTO  manufacture (manufacture_name) VALUES(?)");
    query.addBindValue(ui->lineEdit_2->text());
    if (!query.exec()) {
      ui->statusString->setText("Добавление не выполнено."+db.lastError().text());
    };
}

void MainWindow::on_addButton_3_released()
{
    QSqlQuery query;
    query.prepare("INSERT INTO  pc_detail (pc_detail_model_id, detail_name, detail_price) VALUES(?,?,?)");
    query.addBindValue(ui->lineEdit_3->text());
    query.addBindValue(ui->lineEdit_4->text());
    query.addBindValue(ui->lineEdit_5->text());
    if (!query.exec()) {
      ui->statusString->setText("Добавление не выполнено."+db.lastError().text());
    };
}

void MainWindow::on_addButton_4_released()
{
    QSqlQuery query;
    query.prepare("INSERT INTO  pc_detail_model (pc_detail_model, manufacture_id, pc_detail_type_id) VALUES(?,?,?)");
    query.addBindValue(ui->lineEdit_8->text());
    query.addBindValue(ui->lineEdit_7->text());
    query.addBindValue(ui->lineEdit_6->text());
    if (!query.exec()) {
      ui->statusString->setText("Добавление не выполнено."+db.lastError().text());
    };
}
