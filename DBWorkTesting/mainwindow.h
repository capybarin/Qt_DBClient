#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "typemodel.h"
#include "manufacmodel.h"
#include "detailmvcmodel.h"
#include "detail_model_model.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_connectButton_released();

    void on_disconectButton_released();

    void on_addButton_released();

    void on_addButton_2_released();

    void on_addButton_3_released();

    void on_addButton_4_released();

private:
    Ui::MainWindow *ui;

protected:
    QSqlDatabase db;
    QString userLogin;
    QString userPassword;
    QString userHost;
    int     localPortDB;
    bool    DBConnectionState;
    typemodel *Typemodel;
    ManufacModel *manufa;
    DetailMVCMdel *detmvc;
    Detail_model_modeil *detmm;
};

#endif // MAINWINDOW_H
