#include "manufacmodel.h"

ManufacModel::ManufacModel(){

}

ManufacModel::ManufacModel(QObject *parent, QSqlDatabase db){
    setTable("manufacture");
    setEditStrategy(QSqlTableModel::OnFieldChange);
    setHeaderData( 0, Qt::Horizontal, "         Id          ");
    setHeaderData( 1, Qt::Horizontal, "         Виробник    ");
}
