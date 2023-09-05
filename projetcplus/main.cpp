#include "mainwindow.h"
#include <QApplication>
#include<QFile>
#include<QFileDialog>
#include<QTabBar>
#include<QTextDocument>
#include<QDebug>
#include<QString>
#include<QIODevice>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Lecture fichier:

    //creation obejet QFile
    //QFile fichier("main.cpp");
    //ouverture fichier en lecture seule
    //fichier.open(QIODevice::ReadOnly);



    MainWindow w;
    w.show();
    return a.exec();
}
