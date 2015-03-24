#ifndef LAYOUTHELPER_H
#define LAYOUTHELPER_H

#include <QSizeF>

#define BEST_RATIO 1.3333333

class LayoutHelper
{
public:
    LayoutHelper();
    ~LayoutHelper();

    void setCount(int count);
    void setWidth(int width);
    void setHeight(int height);
    void setSpacing(int spacing);

    QSizeF sizeForCols(int cols);
    int chooseCols();

private:
    int count, width, height, spacing;
};

#endif // LAYOUTHELPER_H
