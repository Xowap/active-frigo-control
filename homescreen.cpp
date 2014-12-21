#include "homescreen.h"
#include "ui_homescreen.h"

#include <QUdpSocket>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QByteArray>

HomeScreen::HomeScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeScreen)
{
    ui->setupUi(this);
}

HomeScreen::~HomeScreen()
{
    delete ui;
}

void HomeScreen::on_pushButton_clicked()
{
    QUdpSocket socket;
    QByteArray data("{\"type\":\"play-sound\",\"name\":\"ahaha\"}");
    QHostAddress target("225.42.42.42");
    socket.writeDatagram(data, target, 42000);

//    foreach (QHostAddress address, QNetworkInterface::allAddresses()) {
//        QUdpSocket socket;

//        qDebug() << address;

//        if (address.protocol() == QAbstractSocket::IPv6Protocol
//                && address.isInSubnet(QHostAddress::parseSubnet("fe80::/64"))) {
//            socket.bind(address, 0);
//            socket.writeDatagram(data, target, 42000);
//        }
//    }
}
