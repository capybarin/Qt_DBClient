#ifndef DETAILMVCMODEL_H
#define DETAILMVCMODEL_H
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>

class DetailMVCMdel:public QSqlRelationalTableModel
{
public:
    DetailMVCMdel();
    DetailMVCMdel(QObject *parent, QSqlDatabase db);
};


#endif // DETAILMVCMODEL_H
