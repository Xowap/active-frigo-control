#include "homescreen.h"
#include "ui_homescreen.h"

#include <QUdpSocket>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QByteArray>

HomeScreen::HomeScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeScreen),
    tunnel(new FrigoTunnel("control", this))
{
    ui->setupUi(this);
}

HomeScreen::~HomeScreen()
{
    delete ui;
}

void HomeScreen::on_pushButton_clicked()
{
    QJsonObject content;
    content["type"] = "play-sound";
    content["name"] = "ahaha";

    FrigoMessage message(content);
    message.to("*");

    FrigoPacket packet(&message);
    tunnel->send(&packet);
}
