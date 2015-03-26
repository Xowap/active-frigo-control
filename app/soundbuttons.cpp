#include "soundbuttons.h"
#include "config.h"

#include <QtDebug>
#include <QUdpSocket>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QByteArray>
#include <QPushButton>
#include <QUuid>

#include "autobalancedlayout.h"

SoundButtons::SoundButtons(QWidget *parent) :
    QWidget(parent),
    tunnel(new FrigoTunnel(QUuid::createUuid().toString(), this)),
    layout(new AutoBalancedLayout(this)),
    volume(100)
{
    Config *config = Config::instance();
    config->load(":/config/config.json");

    setLayout(layout);

    foreach(SoundSet set, config->getSoundSets()) {
        QPushButton *button = new QPushButton(set.getName(), this);
        button->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
        layout->addWidget(button);
        connect(button, &QPushButton::pressed, [=]() {
            playSet(set);
        });
    }

    volumeTimer.setInterval(5000);
    connect(&volumeTimer, SIGNAL(timeout()), this, SLOT(sendVolume()));
    volumeTimer.start();
}

SoundButtons::~SoundButtons()
{
}

void SoundButtons::playSet(SoundSet set)
{
    FrigoPacket packet;

    foreach(SoundTarget target, set.getTargets()) {
        QJsonObject content;
        content["type"] = "play-sound";
        content["name"] = target.getName();
        content["volume"] = target.getVolume();

        qDebug() << "playing sound" << content;

        FrigoMessage *message = new FrigoMessage(content);
        message->to(target.getHosts());
        message->deleteLater();
        packet.append(message);
    }

    tunnel->send(&packet);
}

void SoundButtons::setVolume(int volume)
{
    this->volume = volume;
    sendVolume();
}

void SoundButtons::sendVolume()
{
    QJsonObject content;
    content["type"] = "set-volume";
    content["volume"] = this->volume;

    FrigoMessage *message = new FrigoMessage(content);
    message->to(QStringList("*"));
    message->deleteLater();

    FrigoPacket packet;
    packet.append(message);

    qDebug() << "setting volume" << content;

    tunnel->send(&packet);
}
