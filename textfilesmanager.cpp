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
    for (const QFileInfo& fileName: fileNames)
    {
        QFile file(fileName.filePath());
        if (file.open(QFile::ReadOnly))
        {
            QString text = file.readAll();
            TextParser parser(mode == Letters, includeNumbers);

            for (int i = 0 ; i < text.length(); ++i)
            {
                if (parser.isSymbolAllowed(text.at(i)))
                {
                    qDebug() << text.at(i);
                }
            }
        }
    }
}
