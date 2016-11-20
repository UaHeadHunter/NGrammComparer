#include <textfilesmanager.h>
#include "textparser.h"

//think about future usage of regexp
static const QStringList symbols = QStringList() << "," << ":" << ";" << "-" << "?"
                                                 << "!" << "." << "/" << "\\" << "|"
                                                 << "<" << ">" << "(" << ")" << "\""
                                                 << "'" << "[" << "]" << "{" << "}";

static const QStringList numbers = QStringList() << "1" << "2" << "3" << "4" << "5"
                                                 << "6" << "7" << "8" << "9" << "0";

static const QStringList notWritableConsts = QStringList() << "\n" << "\r" << "\t";

TextParser::TextParser(bool removeSymbols, bool removeNumbers)
    : mRemoveSybmols(removeSymbols),
      mRemoveNumbers(removeNumbers)
{
}

bool TextParser::isSymbolAllowed(QChar symbol)
{
    if (mRemoveSybmols && !symbol.isLetter() && !symbol.isSpace()
            || mRemoveNumbers && symbol.isDigit()
            || notWritableConsts.contains(symbol))
    {
        return false;
    }
    return true;
}
