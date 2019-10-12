#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QChar>
#include <QString>
#include <QModelIndex>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
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
      ui->textEdit->append("Подключение не выполнено."+db.lastError().text());
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
      ui->textEdit->append("Добавление в таблицу 'pc_detail_type' не выполнено"+db.lastError().text());
    };
    Typemodel->select();
}

void MainWindow::on_addButton_2_released()
{
    QSqlQuery query;
    query.prepare("INSERT INTO  manufacture (manufacture_name) VALUES(?)");
    query.addBindValue(ui->lineEdit_2->text());
    if (!query.exec()) {
      ui->textEdit->append("Добавление в таблицу 'manufacture' не выполнено"+db.lastError().text());
    };
    manufa->select();
}

void MainWindow::on_addButton_3_released()
{
    QSqlQuery query;
    query.prepare("INSERT INTO  pc_detail (pc_detail_model_id, detail_name, detail_price) VALUES(?,?,?)");
    query.addBindValue(ui->lineEdit_3->text());
    query.addBindValue(ui->lineEdit_4->text());
    query.addBindValue(ui->lineEdit_5->text());
    if (!query.exec()) {
      ui->textEdit->append("Добавление в таблицу 'pc_detail' не выполнено"+db.lastError().text());
    };
    detmvc->select();
}

void MainWindow::on_addButton_4_released()
{
    QSqlQuery query;
    query.prepare("INSERT INTO  pc_detail_model (pc_detail_model, manufacture_id, pc_detail_type_id) VALUES(?,?,?)");
    query.addBindValue(ui->lineEdit_8->text());
    query.addBindValue(ui->lineEdit_7->text());
    query.addBindValue(ui->lineEdit_6->text());
    if (!query.exec()) {
      ui->textEdit->append("Добавление в таблицу 'pc_detail_model' не выполнено"+db.lastError().text());
    };
    detmm->select();
}

void MainWindow::on_removeButton_released()
{
    QModelIndex index=ui->tableView->currentIndex();
    if(index.isValid()){
        QSqlRecord record=Typemodel->record(index.row());
        int Id=record.value(0).toInt();
        QString sql="DELETE FROM pc_detail_type WHERE pc_detail_type_id=%1;";
        sql=sql.arg(Id);
        QSqlQuery query(db);
        if(!query.exec(sql))
        ui->textEdit->append("Ошибка удаления"+db.lastError().text());
        }
        Typemodel->select();
}


void MainWindow::on_removeButton_3_released()
{
    QModelIndex index=ui->secondTableView->currentIndex();
    if(index.isValid()){
        QSqlRecord record=manufa->record(index.row());
        int Id=record.value(0).toInt();
        QString sql="DELETE FROM manufacture WHERE idmanufacture=%1;";
        sql=sql.arg(Id);
        QSqlQuery query(db);
        if(!query.exec(sql))
             ui->textEdit->append("Ошибка удаления"+db.lastError().text());
        }
        manufa->select();
}

void MainWindow::on_removeButton_4_released()
{
    QModelIndex index=ui->secondTableView_3->currentIndex();
    if(index.isValid()){
        QSqlRecord record=detmvc->record(index.row());
        int Id=record.value(0).toInt();
        QString sql="DELETE FROM pc_detail WHERE idpc_detail=%1;";
        sql=sql.arg(Id);
        QSqlQuery query(db);
        if(!query.exec(sql))
            ui->textEdit->append("Ошибка удаления"+db.lastError().text());
        }
        detmvc->select();
}

void MainWindow::on_removeButton_2_released()
{
    QModelIndex index=ui->secondTableView_4->currentIndex();
    if(index.isValid()){
        QSqlRecord record=detmm->record(index.row());
        int Id=record.value(0).toInt();
        QString sql="DELETE FROM pc_detail_model WHERE idpc_detail_model=%1;";
        sql=sql.arg(Id);
        QSqlQuery query(db);
        if(!query.exec(sql))
            ui->textEdit->append("Ошибка удаления"+db.lastError().text());
        }
        detmm->select();
}

void MainWindow::on_pushButton_released()
{
    QString outfile = QFileDialog::getSaveFileName(this, tr("Save"), "",tr("txt(*.txt)"));
        if (outfile != "") {
            QFile file(outfile);

            if (file.open(QIODevice::ReadWrite)) {
                QTextStream stream(&file);
                stream << ui->textEdit->toPlainText();
                file.flush();
                file.close();
            }
            else {
                ui->statusString->setText("Невозможно сохранить файл");
            }
        }
}
