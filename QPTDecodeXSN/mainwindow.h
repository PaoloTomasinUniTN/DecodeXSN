#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>

#include "xsndecoder.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_tb_inputPath_clicked();

    void on_pb_run_clicked();

private:
    Ui::MainWindow *ui;

    QString inputFilename = "";
    bool inputSelected = true;


};

#endif // MAINWINDOW_H
