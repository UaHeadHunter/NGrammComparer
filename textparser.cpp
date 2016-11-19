#include <textfilesmanager.h>
#include "textparser.h"

#include <QStringList>
//think about future usage of regexp
static const QStringList symbols = QStringList() << "," << ":" << ";" << "-" << "?"
                                                 << "!" << "." << "/" << "\\" << "|"
                                                 << "<" << ">" << "(" << ")" << "\""
                                                 << "'" << "[" << "]" << "{" << "}";

static const QStringList numbers = QStringList() << "1" << "2" << "3" << "4" << "5"
                                                 << "6" << "7" << "8" << "9" << "0";

static const QStringList notWritableConsts = QStringList() << "\n" << "\r" << "\t";

TextParser::TextParser()
{
}

void TextParser::parseText(QString &text, bool removeSymbols, bool removeNumbers)
{
    QStringList symbolsToRemove = notWritableConsts;
    if (removeSymbols)
    {
        symbolsToRemove << symbols;
    }

    if (removeNumbers)
    {
        symbolsToRemove << numbers;
    }

    for (int i = 0; i < text.length();)
    {
        if (symbolsToRemove.contains(QString(text[i])))
        {
            text.remove(i, 1);
        }
        else
        {
            ++i;
        }
    }
}
