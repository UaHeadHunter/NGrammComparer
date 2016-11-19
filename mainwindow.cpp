#include "textfilesmanager.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

#include <QProgressBar>
#include <QFileDialog>
#include <QLabel>
#include <QDebug>
#include <QDir>

static const QStringList filters = QStringList() << "*.txt" << "*.rtf" << "*.doc" << "*.docx";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mStatusLabel(new QLabel("Status:", this)),
    mProgressBar(new QProgressBar(this)),
    mFileManager(new TextFilesManager(this))
{
    ui->setupUi(this);

    ui->statusBar->addWidget(mStatusLabel);
    ui->statusBar->addWidget(mProgressBar);

    connect(ui->actionOpen_text, SIGNAL(triggered(bool)), this, SLOT(slotOpenTexts()),
            Qt::UniqueConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::slotOpenTexts()
{
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::DirectoryOnly);
    dialog.exec();

    if (dialog.result() == QFileDialog::Accepted)
    {
        QStringList dirs = dialog.selectedFiles();
        QFileInfoList files;
        for (QString &stringDir : dirs)
        {
            QDir dir(stringDir);

            files.append(dir.entryInfoList(filters, QDir::Files | QDir::NoDotAndDotDot));
        }
        int mode = -1;
        QString stringMode = ui->modesCombobox->currentText();
        if (stringMode == "Symbols")
        {
            mode = TextFilesManager::Symbols;
        }
        else if (stringMode == "Letters")
        {
            mode = TextFilesManager::Letters;
        }
        //change with method
        int nGramm = ui->nGrammCountLineEdit->text().toInt();
        bool removeNumbers = !ui->includeNumbersCheckBox->isChecked();
        mFileManager->slotTextFilesLoaded(files, nGramm, mode, removeNumbers);
    }
}
