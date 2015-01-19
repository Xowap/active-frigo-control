#include "homescreen.h"
#include "ui_homescreen.h"

#include <QUdpSocket>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QByteArray>
#include <QPushButton>

#include "autobalancedlayout.h"

HomeScreen::HomeScreen(QWidget *parent) :
    QWidget(parent),
    //ui(new Ui::HomeScreen),
    tunnel(new FrigoTunnel("control", this)),
    layout(new AutoBalancedLayout(this))
{
    //ui->setupUi(this);
    setLayout(layout);

    QPushButton *button1 = new QPushButton("Button 1", this);
    QPushButton *button2 = new QPushButton("Button 2", this);
    QPushButton *button3 = new QPushButton("Button 3", this);

    button1->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    button2->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    button3->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
}

HomeScreen::~HomeScreen()
{
}
