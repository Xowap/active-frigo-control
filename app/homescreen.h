#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#include <QWidget>

#include "frigotunnel.h"
#include "autobalancedlayout.h"
#include "soundset.h"

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
    void playSet(SoundSet set);

private:
    FrigoTunnel *tunnel;
    AutoBalancedLayout *layout;
};

#endif // HOMESCREEN_H
