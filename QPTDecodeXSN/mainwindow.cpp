#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tb_inputPath_clicked()
{
    inputSelected = false;
    inputFilename = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("XSN file (*.xsn)"));
    if (inputFilename != "") {
        qDebug() << inputFilename;
        ui->la_inputPath->setText(inputFilename);
        inputSelected = true;
    }

    ui->pb_run->setEnabled(inputSelected);
}



void MainWindow::on_pb_run_clicked()
{
    XsnDecoder decoder;
    bool ok = decoder.decode(inputFilename);


}
