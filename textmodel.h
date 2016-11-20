#ifndef TEXTMODEL_H
#define TEXTMODEL_H

#include <QAbstractTableModel>

class TextItem;
class TextModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit TextModel(QObject *parent = 0);

private:
    QList<TextItem*> mData;
};

#endif // TEXTMODEL_H
