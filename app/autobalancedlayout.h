#ifndef AUTOBALANCEDLAYOUT_H
#define AUTOBALANCEDLAYOUT_H

#include <QtWidgets>
#include <QVector>

class AutoBalancedLayout : public QLayout
{
    Q_OBJECT
public:
    static const double ITEM_ASPECT;
    static const int MINIMUM_CELL_WIDTH;

    AutoBalancedLayout(QWidget *parent): QLayout(parent) {}
    AutoBalancedLayout(): QLayout() {}
    ~AutoBalancedLayout();

    void addItem(QLayoutItem *item);
    QSize sizeHint() const;
    int count() const;
    QLayoutItem *itemAt(int index) const;
    QLayoutItem *takeAt(int index);
    void setGeometry(const QRect &rect);

private:
    QVector<QLayoutItem*> items;

    static int calcColumns(int n, double aspect, const QRect &r);
};

#endif // AUTOBALANCEDLAYOUT_H
