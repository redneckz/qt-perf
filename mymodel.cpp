#include <QTime>
#include "mymodel.h"

const int DEFAULT_ROW_COUNT = 1000;
const int DEFAULT_COL_COUNT = 10;

MyModel::MyModel(QObject *parent)
    :QAbstractTableModel(parent)
{
    size = DEFAULT_ROW_COUNT;
    timer = new QTimer(this);
    timer->setInterval(1000 / 60);
    connect(timer, SIGNAL(timeout()) , this, SLOT(timerHit()));
    timer->start();
}

int MyModel::rowCount(const QModelIndex & /*parent*/) const
{
    return size;
}

int MyModel::columnCount(const QModelIndex & /*parent*/) const
{
    return DEFAULT_COL_COUNT;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return QString("[%1,%2]%3")
            .arg(index.row())
            .arg(index.column())
            .arg(QTime::currentTime().msecsSinceStartOfDay());
    }
    return QVariant();
}

void MyModel::setSize(int newSize) {
    emit beginResetModel();
    size = newSize;
    emit endResetModel();
}

void MyModel::timerHit()
{
    QModelIndex topLeft = createIndex(0, 0);
    QModelIndex bottomRight = createIndex(this->rowCount() - 1, this->columnCount() - 1);
    emit dataChanged(topLeft, bottomRight);
}
