#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile fichier("main.cpp");
    //ouverture fichier en lecture seule
    fichier.open(QIODevice::ReadOnly);
}

MainWindow::~MainWindow()
{
    delete ui;
}

