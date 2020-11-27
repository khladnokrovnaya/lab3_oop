#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Text.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_textEdit_textChanged();

    void on_undoButton_clicked();

    void on_redoButton_clicked();

    void on_saveButton_clicked();

    void on_loadFileBtn_clicked();

    void on_pushButton_clicked();

    void on_centralwidget_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow* ui;
    Text textEditor;
};
#endif // MAINWINDOW_H
