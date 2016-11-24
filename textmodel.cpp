#include "textmodel.h"
#include "textitem.h"

#include <QVariant>

TextModel::TextModel(QObject *parent)
    : QAbstractTableModel(parent),
      mMode(AbsoluteFrequency),
      mCount(0)
{
}

int TextModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mData.count();
}

int TextModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mCount + 1;
}

QVariant TextModel::data(const QModelIndex &index, int role) const
{
    QVariant rValue;

    if (index.row() < 0 || index.row() >= mData.count() || role != Qt::DisplayRole) {
        return QVariant();
    }
    int column = index.column();
    int row = index.row();

    if (column == 0)
    {
        rValue = mData.keys().at(index.row());
    }
    else if (column > 0 && column <= mData.values().at(row).count())
    {
        TextItem *item = mData.values().at(row).at(column - 1);
        switch (static_cast<DisplayMode>(mMode))
        {
        case AbsoluteFrequency:
            rValue = item->mAbsFreq;
            break;
        case RelativeFrequency:
            rValue = item->mRelFreq;
            break;
        case DeviationFromAbsoluteFrequency:
            rValue = item->mDevAbsFreq;
            break;
        case DeviationFromRelativeFrequency:
            rValue = item->mDevRelFreq;
            break;
        }

    }

    return rValue;
}

void TextModel::slotAddWords(const QStringList &items)
{
    beginInsertRows(index(0, 0), 0, items.count() - 1);
    for (const QString &item : items)
    {
        mData.insert(item, QList<TextItem*>());
    }
    endInsertRows();
}

void TextModel::slotBuildModel(QList<QHash<QString, int> > texts)
{
    beginInsertRows(index(0, 0), 0, texts.count() - 1);
    mCount = texts.count();
    for (QHash<QString, int> &text : texts)
    {
        for (const QString &word : text.keys())
        {
            int absFreq = text.value(word);
            double relFreq = text.value(word) / (double)mData.count();
            double devAbsFreq = absFreq;
            double devRelFreq = relFreq;
            QList<TextItem*> list = mData.value(word);

            if (list.count() > 0)
            {
                devAbsFreq = absFreq - list.first()->mAbsFreq;
                devRelFreq = relFreq - list.first()->mRelFreq;
            }
            mData[word].append(new TextItem(absFreq, relFreq, devAbsFreq, devRelFreq));
        }
    }
    endInsertRows();
    QVector<int> roles;
    roles.append(Qt::DisplayRole);
    emit dataChanged(index(0,0), index(mData.count() - 1, mData.values().at(0).count() - 1),
                     roles);
}

void TextModel::slotClear()
{
    beginResetModel();

    for (QList<TextItem*> item : mData.values())
    {
        qDeleteAll(item);
    }
    mData.clear();

    endResetModel();
}

int TextModel::mode() const
{
    return mMode;
}

void TextModel::setMode(int mode)
{
    mMode = mode;
}
