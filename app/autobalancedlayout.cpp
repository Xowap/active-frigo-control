#include "autobalancedlayout.h"

#include <cmath>

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
    int columns = calcColumns(count(), ITEM_ASPECT, rect), rows = ceil(count() / (double) columns);
    double width = (double) rect.width() / columns, height = (double) rect.height() / rows;

    for (int x = 0; x < columns; x += 1) {
        for (int y = 0; y < rows; y += 1) {
            int i = y * columns + x;

            if (i < count()) {
                items[i]->setGeometry(QRect(
                    rect.x() + x * width,
                    rect.y() + y * height,
                    width,
                    height
                ));
            }
        }
    }
}

int AutoBalancedLayout::calcColumns(int n, double aspect, const QRect &r)
{
    double beta = aspect * (double) r.width() / (double) r.height();
    return ceil(sqrt((double) n / beta));
}
