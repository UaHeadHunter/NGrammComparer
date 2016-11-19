#ifndef TEXTPARSER_H
#define TEXTPARSER_H

#include <QString>

class TextParser
{
public:
    explicit TextParser();

    static void  parseText(QString &text, bool removeSymbols, bool removeNumbers);
};

#endif // TEXTPARSER_H
