#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QProgressBar>
#include <QFileDialog>
#include <QLabel>
#include <QDebug>
#include <QDir>

static const QStringList filters = QStringList() << "*.txt" << "*.rtf" << "*.doc" << "*.docx";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mStatusLabel = new QLabel("Status:", this);
    mProgressBar = new QProgressBar(this);

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
        QStringList files;
        for (QString &stringDir : dirs)
        {
            QDir dir(stringDir);

            files.append(dir.entryList(filters, QDir::Files | QDir::NoDotAndDotDot));
        }
        emit textFilesLoaded(files);
    }
}
