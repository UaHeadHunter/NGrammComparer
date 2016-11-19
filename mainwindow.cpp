#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QProgressBar>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mStatusLabel = new QLabel("Status:", this);
    mProgressBar = new QProgressBar(this);

    ui->statusBar->addWidget(mStatusLabel);
    ui->statusBar->addWidget(mProgressBar);
}

MainWindow::~MainWindow()
{
    delete ui;
}
