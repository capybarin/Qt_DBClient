#include "typemodel.h"

typemodel::typemodel()
{

}

typemodel::typemodel(QObject *parent, QSqlDatabase db){
    setTable("pc_detail_type");
    setEditStrategy(QSqlTableModel::OnFieldChange);
    setHeaderData( 0, Qt::Horizontal, tr("Id"));
    setHeaderData( 1, Qt::Horizontal, tr("Назва"));
}
