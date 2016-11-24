#include "textfilesmanager.h"
#include "textparser.h"
#include "textmodel.h"

#include <QFile>

TextFilesManager::TextFilesManager(QObject *parent)
    : QObject(parent),
      mModel(new TextModel(this))
{

}

void TextFilesManager::slotTextFilesLoaded(QStringList &texts, int nGrammSize,
                                           int mode, bool includeNumbers, int displayMode)
{
    mAllWords.clear();
    mModel->slotClear();
    mTextWords.clear();
    mModel->setMode(displayMode);

    TextParser parser(mode == Letters, includeNumbers);

    for (QString& text: texts)
    {
        QHash<QString, int> dictionary;
        for (int i = 0 ; i < text.length() - nGrammSize; ++i)
        {
            QString nGramm;
            for (int n = i; n < i + nGrammSize; )
            {
                if (n >= text.length())
                {
                    break;
                }

                QChar symbol = text.at(n).toLower();

                if (parser.isSymbolAllowed(symbol))
                {
                    nGramm.append(symbol);
                    ++n;
                }
                else
                {
                    text.remove(n, 1);
                }
            }

            if (dictionary.contains(nGramm))
            {
                ++dictionary[nGramm];
            }
            else
            {
                dictionary.insert(nGramm, 1);
            }
            if (!mAllWords.contains(nGramm))
            {
                mAllWords.append(nGramm);
            }
        }
        mTextWords.append(dictionary);
    }

    mModel->slotAddWords(mAllWords);
    mModel->slotBuildModel(mTextWords);
}

TextModel *TextFilesManager::model() const
{
    return mModel;
}
