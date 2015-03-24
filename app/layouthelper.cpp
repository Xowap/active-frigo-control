#include "layouthelper.h"

#include <cmath>
#include <QtDebug>

LayoutHelper::LayoutHelper()
{

}

LayoutHelper::~LayoutHelper()
{

}

void LayoutHelper::setCount(int count)
{
    this->count = count;
}

void LayoutHelper::setWidth(int width)
{
    this->width = width;
}

void LayoutHelper::setHeight(int height)
{
    this->height = height;
}

void LayoutHelper::setSpacing(int spacing)
{
    this->spacing = spacing;
}

QSizeF LayoutHelper::sizeForCols(int cols)
{
    int rows = ceil((double) count / (double) cols);
    double aWidth = width - (cols - 1) * spacing;
    double aHeight = height - (rows - 1) * spacing;

    return QSizeF(aWidth / (double) cols, aHeight / (double) rows);
}

int LayoutHelper::chooseCols()
{
    int i;
    double bestDiff, lastDiff = INFINITY;

    for (i = 1; i < count; i += 1) {
        QSizeF size = sizeForCols(i);
        double ratio = size.width() / size.height();
        double diff = fabs(BEST_RATIO - ratio);

        if (diff < bestDiff) {
            bestDiff = diff;
        }

        if (diff > lastDiff) {
            break;
        }

        lastDiff = diff;
    }

    return i;
}

