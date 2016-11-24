#ifndef TEXTFILESMANAGER_H
#define TEXTFILESMANAGER_H

#include <QFileInfo>
#include <QObject>
#include <QHash>

class TextModel;
class TextFilesManager : public QObject
{
    Q_OBJECT
public:
    enum Mode
    {
        Symbols,
        Letters
    };

    explicit TextFilesManager(QObject *parent = 0);

    TextModel *model() const;

public slots:
    void slotTextFilesLoaded(QStringList &texts, int nGrammSize,
                             int mode, bool includeNumbers, int displayMode);
private:
    QList<QHash<QString, int>> mTextWords;
    QStringList mAllWords;

    TextModel *mModel;
};

#endif // TEXTFILESMANAGER_H
