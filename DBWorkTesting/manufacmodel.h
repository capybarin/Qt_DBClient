#ifndef MANUFACMODEL_H
#define MANUFACMODEL_H
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>

class ManufacModel:public QSqlRelationalTableModel
{
public:
    ManufacModel();
    ManufacModel(QObject *parent, QSqlDatabase db);
};

#endif // MANUFACMODEL_H

