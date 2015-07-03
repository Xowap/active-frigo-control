#ifndef SOUNDBUTTONS_H
#define SOUNDBUTTONS_H

#include <QWidget>
#include <QTimer>
#include <QMap>

#include "frigotunnel.h"
#include "autobalancedlayout.h"
#include "soundset.h"

#define LONG_PRESS_TIMEOUT 1000

typedef QMap<QPushButton *, bool> ButtonStatus;

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

    void enableButton(QPushButton *button);
    void disableButton(QPushButton *button);

private:
    FrigoTunnel *tunnel;
    AutoBalancedLayout *layout;
    QTimer volumeTimer;
    ButtonStatus buttonStatus;

    int volume;
};

#endif // SOUNDBUTTONS_H
