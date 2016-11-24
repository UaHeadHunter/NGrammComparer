#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class QLabel;
class QProgressBar;
class TextFilesManager;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void textFilesLoaded(const QStringList &fileNames, int mode, bool includeNumbers);

private slots:
    void slotOpenTexts();
    void slotNGrammButtonClicked();

private:
    Ui::MainWindow *ui;
    QProgressBar *mProgressBar;
    QLabel *mStatusLabel;
    TextFilesManager *mFileManager;
    QStringList mFiles;
    int mMode;
};

#endif // MAINWINDOW_H
