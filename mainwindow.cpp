#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mymodel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    myModel(parent)
{
    ui->setupUi(this);
    setWindowTitle(QString("[Qt perf.]"));
    ui->tableView->setModel(&myModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    myModel.setSize(value * 1000);
}
