#pragma once
#include "mainwindow.h"
#include <QApplication>
#include "Text.h"
#include <QGridLayout>
#include <QtWidgets>


using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
