#include "peoplemodel.h"

PeopleModel::PeopleModel()
{

}

PeopleModel::PeopleModel(QObject *parent, QSqlDatabase db)
{
    setTable("person");
    setEditStrategy(QSqlTableModel::OnFieldChange);

    setHeaderData( 0, Qt::Horizontal,"Id");
    setHeaderData( 1, Qt::Horizontal,"     Фамилия     ");
    setHeaderData( 2, Qt::Horizontal,"          Имя           ");
    setHeaderData( 3, Qt::Horizontal,"   Отчество    ");
    setHeaderData( 4, Qt::Horizontal,"Дата рождения");
    setHeaderData( 5, Qt::Horizontal,"Место рождения");
    setHeaderData( 6, Qt::Horizontal,"Гражданство");
    setHeaderData( 7, Qt::Horizontal,"Пол");
    setHeaderData( 8, Qt::Horizontal,"Военнообязанный");
    setHeaderData( 9, Qt::Horizontal,"Семейное положение");
    setHeaderData(10, Qt::Horizontal,"Логин");
    setHeaderData(11, Qt::Horizontal,"Пароль");
}

