#ifndef TEXTMODEL_H
#define TEXTMODEL_H

#include <QAbstractTableModel>

struct TextItem;
class TextModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    enum DisplayMode
    {
        AbsoluteFrequency = 0,
        RelativeFrequency,
        DeviationFromAbsoluteFrequency,
        DeviationFromRelativeFrequency
    };

    explicit TextModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    int mode() const;
    void setMode(int mode);

public slots:
    void slotAddWords(const QStringList& items);
    void slotBuildModel(QList<QHash<QString, int>> texts);
    void slotClear();

private:
    QMap<QString, QList<TextItem*>> mData;
    int mMode;
    int mCount;
};

#endif // TEXTMODEL_H
