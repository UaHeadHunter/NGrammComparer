#include "textmodel.h"
#include "textitem.h"

TextModel::TextModel(const QStringList &items, QAbstractTableModel *parent)
    : QAbstractTableModel(parent)
{
    for (const QString &item : items)
    {
        mData.insert(item, QList<TextItem*>());
    }
}

void TextModel::slotBuildModel(QList<QHash<QString, int> > texts)
{
    for (int i = 0 ; i < texts.length(); ++i)
    {
        QHash<QString, int> text = texts.value(i);
        for (const QString &word : text.keys())
        {
            int absFreq = text.value(word);
            double relFreq = text.value(word) / mData.count();
            double devAbsFreq = absFreq;
            double devRelFreq = relFreq;
            QList<TextItem*> list = mData.value(word);
            if (list.count() > 1)
            {
                devAbsFreq = list.first()->mAbsFreq - absFreq;
                devRelFreq = list.first()->mRelFreq - relFreq;
            }
            mData.value(word).append(new TextItem(absFreq, relFreq, devAbsFreq, devRelFreq));
        }
    }
}
