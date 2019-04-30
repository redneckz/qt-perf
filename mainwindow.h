#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mytable.h"
#include "mymodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private Q_SLOTS:
    void on_horizontalSlider_valueChanged(int value);

    void on_tableView_framesPerSecond(unsigned fps);

private:
    Ui::MainWindow *ui;
    MyModel myModel;
};

#endif // MAINWINDOW_H
