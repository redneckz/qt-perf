#include "mytable.h"

MyTable::MyTable(QWidget *parent) : QTableView(parent)
{
}

void MyTable::paintEvent(QPaintEvent *e)
{
    QTableView::paintEvent(e);
    const int millis = lastPaintTime.restart();
    if (millis > 0) {
        emit framesPerSecond(1000u / static_cast<unsigned>(millis));
    }
}
