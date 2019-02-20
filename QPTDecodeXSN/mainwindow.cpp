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
    ui->pb_folder->setEnabled(false);
}



void MainWindow::on_pb_run_clicked()
{
    bool raw = ui->cb_rawImages->isChecked();
    bool ok = decoder.decode(inputFilename,raw);
    ui->la_frames->setText(QString::number(decoder.frames));
    ui->la_data->setText(decoder.dateTime.toString("yyyy.MM.dd hh:mm:ss.zzz"));
    ui->pb_run->setEnabled(false);
    ui->pb_folder->setEnabled(true);

}

void MainWindow::on_pb_folder_clicked()
{
    QUrl url = QUrl("file:///" + decoder.mainFolder, QUrl::TolerantMode);
    QDesktopServices::openUrl(url);
}
