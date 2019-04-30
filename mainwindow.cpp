#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mytable.h"
#include "mymodel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    myModel(parent)
{
    ui->setupUi(this);
    setWindowTitle(QString("[Qt perf]"));
    MyTable* myTable = ui->tableView;
    connect(myTable, SIGNAL(framesPerSecond(unsigned)),
            this, SLOT(on_tableView_framesPerSecond(unsigned)));
    myTable->setModel(&myModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    myModel.setSize(value * 1000);
}

void MainWindow::on_tableView_framesPerSecond(unsigned fps)
{
    setWindowTitle(QString("[Qt perf] %1 fps").arg(fps));
}
