#ifndef UNIVERSITYMODEL_H
#define UNIVERSITYMODEL_H

#include <QtSql>

class UniversityModel : public QSqlRelationalTableModel
{
public:
    UniversityModel();
    UniversityModel(QObject *parent,QSqlDatabase db);

};

#endif // UNIVERSITYMODEL_H
