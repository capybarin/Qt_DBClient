#ifndef PEOPLEMODEL_H
#define PEOPLEMODEL_H

#include <QtSql>

class PeopleModel : public QSqlRelationalTableModel
{
public:
    PeopleModel();
    PeopleModel(QObject *parent,QSqlDatabase db);
};

#endif // PEOPLEMODEL_H
