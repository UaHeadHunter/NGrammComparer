#ifndef TEXTFILESMANAGER_H
#define TEXTFILESMANAGER_H

#include <QObject>

class TextFilesManager : public QObject
{
    Q_OBJECT
public:
    explicit TextFilesManager(QObject *parent = 0);

signals:

public slots:
private:
    QList<QHash<QString, int>> mTextWords;
};

#endif // TEXTFILESMANAGER_H
