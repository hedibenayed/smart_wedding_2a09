#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"voiture.h"
#include"honeymonn.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{ voiture z;
    z.show();
    z.exec();
}


void MainWindow::on_pushButton_clicked()
{ the_band b;
    b.show();
    b.exec();


}
