#ifndef TEXTITEM_H
#define TEXTITEM_H

#include <QString>

struct TextItem
{
    explicit TextItem(int absFreq, double relFreq, double devAbsFreq, double devRelFreq)
        : mAbsFreq(absFreq),
          mRelFreq(relFreq),
          mDevAbsFreq(devAbsFreq),
          mDevRelFreq(devRelFreq)
    {
    }

    int mAbsFreq;
    double mRelFreq;
    double mDevAbsFreq;
    double mDevRelFreq;
};

#endif // TEXTITEM_H
