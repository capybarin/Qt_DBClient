#include "detail_model_model.h"

Detail_model_modeil::Detail_model_modeil(){}

Detail_model_modeil::Detail_model_modeil(QObject *parent, QSqlDatabase db){
    setTable("pc_detail_model");
    setEditStrategy(QSqlTableModel::OnFieldChange);
    setRelation(2,QSqlRelation("manufacture","idmanufacture","manufacture_name"));
    setRelation(3,QSqlRelation("pc_detail_type","pc_detail_type_id","pc_detail_type_name"));
    setHeaderData( 0, Qt::Horizontal, "         Id       ");
    setHeaderData( 1, Qt::Horizontal, "         Назва       ");
    setHeaderData( 2, Qt::Horizontal, "         Id_Виробник         ");
    setHeaderData( 3, Qt::Horizontal, "         Id_Тип_Деталi       ");
}
