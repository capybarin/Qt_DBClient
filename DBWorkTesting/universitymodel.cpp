#include "universitymodel.h"

UniversityModel::UniversityModel()
{

}

UniversityModel::UniversityModel(QObject *parent, QSqlDatabase db)
{
    setTable("university_department");
    setEditStrategy(QSqlTableModel::OnFieldChange);

    setHeaderData( 0, Qt::Horizontal,"Id");
    setHeaderData( 1, Qt::Horizontal,"Назва підрозділа повна");
    setHeaderData( 2, Qt::Horizontal,"Скорочена");
    setHeaderData( 3, Qt::Horizontal,"Тип підрозділу");
    setHeaderData( 4, Qt::Horizontal,"Підпорядковується");
}
