#ifndef MYTABLE_H
#define MYTABLE_H

#include <QTableView>
#include <QTime>

class MyTable : public QTableView
{
    Q_OBJECT

public:
    MyTable(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *e);

Q_SIGNALS:
    void framesPerSecond(unsigned fps);

private:
    QTime lastPaintTime;
};

#endif // MYTABLE_H
