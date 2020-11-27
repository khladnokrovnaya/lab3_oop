#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include "Text.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_textEdit_textChanged() {
   textEditor.replace(ui->textEdit->toPlainText().toStdString(), 0, textEditor.GetText().length());
}


void MainWindow::on_undoButton_clicked()
{
    textEditor.undo();
    ui->textEdit->blockSignals(true);
    ui->textEdit->setPlainText(textEditor.GetText().c_str());
    ui->textEdit->blockSignals(false);
}

void MainWindow::on_redoButton_clicked()
{
    textEditor.redo();
    ui->textEdit->blockSignals(true);
    ui->textEdit->setPlainText(textEditor.GetText().c_str());
    ui->textEdit->blockSignals(false);
}


void MainWindow::on_saveButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                QString::fromUtf8("Открыть файл"),
                                QDir::currentPath(),
                                "TXT File(*.txt)");

    if(!(fileName =="")){
        ui->downloadFile->setText(fileName);
    }
}

void MainWindow::on_loadFileBtn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                QString::fromUtf8("Открыть файл"),
                                QDir::currentPath(),
                                "TXT File(*.txt)");

    if(!(fileName =="")){
        ui->downloadFile->setText(fileName);
    }
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_centralwidget_customContextMenuRequested(const QPoint &pos)
{

}
