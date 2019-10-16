#include "detailmvcmodel.h"

DetailMVCMdel::DetailMVCMdel(){}

DetailMVCMdel::DetailMVCMdel(QObject *parent, QSqlDatabase db){
    setTable("pc_detail");
    setRelation(1,QSqlRelation("pc_detail_model","idpc_detail_model","pc_detail_model"));
    setEditStrategy(QSqlTableModel::OnFieldChange);
    setHeaderData( 0, Qt::Horizontal, "         Id      ");
    setHeaderData( 1, Qt::Horizontal, "         Id моделi       ");
    setHeaderData( 2, Qt::Horizontal, "         Назва       ");
    setHeaderData( 3, Qt::Horizontal, "         Цiна        ");
}
