#include "textfilesmanager.h"
#include "textparser.h"

#include <QFile>
#include <QDebug>

TextFilesManager::TextFilesManager(QObject *parent) : QObject(parent)
{

}
void TextFilesManager::slotTextFilesLoaded(const QFileInfoList &fileNames, int nGrammSize, int mode,
                                           bool includeNumbers)
{
    int textCount = 0;
    QHash<QString, int> dictionary;
    for (const QFileInfo& fileName: fileNames)
    {
        QFile file(fileName.filePath());
        if (file.open(QFile::ReadOnly))
        {
            QString text = file.readAll();
            TextParser parser(mode == Letters, includeNumbers);

            for (int i = 0 ; i < text.length() - nGrammSize; ++i)
            {
                QString nGramm;
                for (int n = i; nGramm.count() != nGrammSize; )
                {
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

                qDebug() << nGramm;

                if (dictionary.contains(nGramm))
                {
                    ++dictionary[nGramm];
                }
                else
                {
                    dictionary.insert(nGramm, 1);
                }
            }
        }
        ++textCount;
    }
    qDebug() << dictionary;
}
