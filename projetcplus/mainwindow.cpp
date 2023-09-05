#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionOuvrir, SIGNAL(triggered()),this,SLOT(ouvrir_fichier()));

}

void MainWindow::ouvrir_fichier()
{//creation objet QFile
    qDebug()<<"on ouvre le fichier";

    QFile f("Qt.txt");
    f.open(QIODevice::ReadOnly);
    f.close();
}


MainWindow::~MainWindow()
{
    delete ui;
}

