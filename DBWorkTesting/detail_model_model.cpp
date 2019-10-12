#include "detail_model_model.h"

Detail_model_modeil::Detail_model_modeil(){}

Detail_model_modeil::Detail_model_modeil(QObject *parent, QSqlDatabase db){
    setTable("pc_detail_model");
    setEditStrategy(QSqlTableModel::OnFieldChange);
    setHeaderData( 0, Qt::Horizontal, "Id");
    setHeaderData( 1, Qt::Horizontal, "Назва");
    setHeaderData( 2, Qt::Horizontal, "Id_Виробник");
    setHeaderData( 3, Qt::Horizontal, "Id_Тип_Деталi");
}
