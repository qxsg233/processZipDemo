#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_doProcess, SIGNAL(clicked(bool)), this, SLOT(slot_pushButton_doProcess()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_pushButton_doProcess()
{
    QString filename = QFileDialog::getOpenFileName(this);
    qDebug()<<"filename"<<filename;
    zipObject zip;
    zip.doProcess(filename);
}


//test master

