#ifndef TEXTITEM_H
#define TEXTITEM_H

#include <QString>

struct TextItem
{
public:
    explicit TextItem(QString nGramm, int absFreq, double relFreq, double devAbsFreq,
                      double devRelFreq, double arithMean, double quadMean)
        : mNGramm(nGramm),
          mAbsFreq(absFreq),
          mRelFreq(relFreq),
          mDevAbsFreq(devAbsFreq),
          mDevRelFreq(devRelFreq),
          mArithMean(arithMean),
          mQuadMean(quadMean)
    {
    }

private:
    QString mNGramm;

    int mAbsFreq;
    double mRelFreq;
    double mDevAbsFreq;
    double mDevRelFreq;

    double mArithMean;
    double mQuadMean;
};

#endif // TEXTITEM_H
