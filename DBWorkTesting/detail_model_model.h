#ifndef DETAIL_MODEL_MODEL_H
#define DETAIL_MODEL_MODEL_H
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>

class Detail_model_modeil:public QSqlRelationalTableModel
{
public:
    Detail_model_modeil();
    Detail_model_modeil(QObject *parent, QSqlDatabase db);
};

#endif // DETAIL_MODEL_MODEL_H

