#ifndef TEXTPARSER_H
#define TEXTPARSER_H

#include <QChar>

class TextParser
{
public:
    explicit TextParser(bool removeSymbols, bool removeNumbers);

    bool isSymbolAllowed(QChar symbol);

private:
    bool mRemoveSybmols;
    bool mRemoveNumbers;
};

#endif // TEXTPARSER_H
