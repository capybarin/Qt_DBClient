#ifndef TYPEMODEL_H
#define TYPEMODEL_H
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>

class typemodel:public QSqlRelationalTableModel
{
public:
    typemodel();
    typemodel(QObject *parent, QSqlDatabase db);
};

#endif // TYPEMODEL_H

