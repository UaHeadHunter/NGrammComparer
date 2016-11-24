#include "textfilesmanager.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "textmodel.h"

#include <QProgressBar>
#include <QFileDialog>
#include <QTextStream>
#include <QLabel>
#include <QDir>

static const QStringList filters = QStringList() << "*.txt" << "*.rtf" << "*.doc" << "*.docx";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mStatusLabel(new QLabel("Status:", this)),
    mProgressBar(new QProgressBar(this)),
    mFileManager(new TextFilesManager(this)),
    mMode(0)
{
    ui->setupUi(this);

    ui->statusBar->addWidget(mStatusLabel);
    ui->statusBar->addWidget(mProgressBar);

    connect(ui->actionOpen_text, SIGNAL(triggered(bool)), this, SLOT(slotOpenTexts()),
            Qt::UniqueConnection);
    connect(ui->nGrammButton, SIGNAL(clicked(bool)), this, SLOT(slotNGrammButtonClicked()),
            Qt::UniqueConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::slotOpenTexts()
{
    ui->mainGroupBox->setEnabled(true);
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::DirectoryOnly);
    dialog.exec();

    if (dialog.result() == QFileDialog::Accepted)
    {
        mFiles.clear();
        ui->tableView->setModel(nullptr);

        QStringList dirs = dialog.selectedFiles();
        QFileInfoList files;
        for (QString &stringDir : dirs)
        {
            QDir dir(stringDir);
            files.append(dir.entryInfoList(filters, QDir::Files | QDir::NoDotAndDotDot));
        }

        for (QFileInfo &info : files)
        {
            QFile file(info.filePath());
            if (file.open(QFile::ReadOnly))
            {
                QTextStream in(&file);
                in.setCodec("UTF-8");

                QString text = in.readAll();
                mFiles.append(text);
            }
        }

    }
}

void MainWindow::slotNGrammButtonClicked()
{
    ui->tableView->setModel(nullptr);\
    //change with signals
    int mode = ui->modesCombobox->currentIndex();
    int nGramm = ui->nGrammCountLineEdit->text().toInt();
    int displayMode = ui->actionComboBox->currentIndex();
    bool removeNumbers = !ui->includeNumbersCheckBox->isChecked();
    //
    mFileManager->slotTextFilesLoaded(mFiles, nGramm, mode, removeNumbers, displayMode);
    ui->tableView->setModel(mFileManager->model());
}
