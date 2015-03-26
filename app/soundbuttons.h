#ifndef SOUNDBUTTONS_H
#define SOUNDBUTTONS_H

#include <QWidget>
#include <QTimer>

#include "frigotunnel.h"
#include "autobalancedlayout.h"
#include "soundset.h"

class SoundButtons : public QWidget
{
    Q_OBJECT

public:
    explicit SoundButtons(QWidget *parent = 0);
    ~SoundButtons();

private slots:
    void playSet(SoundSet set);
    void setVolume(int volume);
    void sendVolume();

private:
    FrigoTunnel *tunnel;
    AutoBalancedLayout *layout;
    QTimer volumeTimer;

    int volume;
};

#endif // SOUNDBUTTONS_H
