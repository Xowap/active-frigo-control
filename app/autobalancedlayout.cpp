#include "autobalancedlayout.h"

#include <cmath>
#include <QPoint>

const double AutoBalancedLayout::ITEM_ASPECT = 4.0 / 3.0 ;
const int AutoBalancedLayout::MINIMUM_CELL_WIDTH = 50;

AutoBalancedLayout::~AutoBalancedLayout()
{
    foreach (QLayoutItem *item, items) {
        delete item;
    }
}

void AutoBalancedLayout::addItem(QLayoutItem *item)
{
    items << item;
}

QSize AutoBalancedLayout::sizeHint() const
{
    return QSize(sqrt(count()) * MINIMUM_CELL_WIDTH, sqrt(count()) * (double) MINIMUM_CELL_WIDTH / ITEM_ASPECT);
}

int AutoBalancedLayout::count() const
{
    return items.size();
}

QLayoutItem *AutoBalancedLayout::itemAt(int index) const
{
    return items.value(index);
}

QLayoutItem *AutoBalancedLayout::takeAt(int index)
{
    if (0 <= index && index < items.size()) {
        return items.takeAt(index);
    } else {
        return NULL;
    }
}

void AutoBalancedLayout::setGeometry(const QRect &rect)
{
    helper.setCount(items.size());
    helper.setWidth(rect.width() - 1);
    helper.setHeight(rect.height() - 1);
    helper.setSpacing(spacing());

    int columns = helper.chooseCols();
    int rows = ceil((double) items.size() / (double) columns);
    QSizeF size = helper.sizeForCols(columns);

    qDebug() << "set size" << size << columns << rows;

    for (int x = 0; x < columns; x += 1) {
        for (int y = 0; y < rows; y += 1) {
            int i = y * columns + x;

            if (i < count()) {
                items[i]->setGeometry(QRect(
                    QPoint((size.width() + spacing()) * x, (size.height() + spacing()) * y),
                    QPoint(size.width() * (x + 1) + spacing() * x, size.height() * (y + 1) + spacing() * y)
                ));
            }
        }
    }
}
