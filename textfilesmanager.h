#ifndef TEXTFILESMANAGER_H
#define TEXTFILESMANAGER_H

#include <QFileInfo>
#include <QObject>
#include <QHash>

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

public slots:
    void slotTextFilesLoaded(const QFileInfoList &fileNames, int nGrammSize,
                             int mode, bool includeNumbers);
private:
    QList<QHash<QString, int>> mTextWords;
};

#endif // TEXTFILESMANAGER_H
