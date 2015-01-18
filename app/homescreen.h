#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#include <QWidget>

#include "frigotunnel.h"

namespace Ui {
class HomeScreen;
}

class HomeScreen : public QWidget
{
    Q_OBJECT

public:
    explicit HomeScreen(QWidget *parent = 0);
    ~HomeScreen();

private slots:
    void on_pushButton_clicked();

private:
    Ui::HomeScreen *ui;
    FrigoTunnel *tunnel;
};

#endif // HOMESCREEN_H
