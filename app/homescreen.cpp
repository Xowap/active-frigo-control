#include "homescreen.h"
#include "config.h"

#include <QtDebug>
#include <QUdpSocket>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QByteArray>
#include <QPushButton>

#include "autobalancedlayout.h"

HomeScreen::HomeScreen(QWidget *parent) :
    QWidget(parent),
    tunnel(new FrigoTunnel("control", this)),
    layout(new AutoBalancedLayout(this))
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
}

HomeScreen::~HomeScreen()
{
}

void HomeScreen::playSet(SoundSet set)
{
    FrigoPacket packet;

    foreach(SoundTarget target, set.getTargets()) {
        QJsonObject content;
        content["type"] = "play-sound";
        content["name"] = target.getName();
        content["volume"] = target.getVolume();

        FrigoMessage *message = new FrigoMessage(content);
        message->to(target.getHosts());
        message->deleteLater();
        packet.append(message);
    }

    tunnel->send(&packet);
}
