#ifndef TEXTMODEL_H
#define TEXTMODEL_H

#include <QAbstractTableModel>

class TextItem;
class TextModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit TextModel(const QStringList& items, QAbstractTableModel *parent = 0);

public slots:
    void slotBuildModel(QList<QHash<QString, int>> texts);

private:
    void

private:
    QMap<QString, QList<TextItem*>> mData;
};

#endif // TEXTMODEL_H
