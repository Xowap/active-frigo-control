#include "homescreen.h"
#include "ui_homescreen.h"

HomeScreen::HomeScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeScreen)
{
    ui->setupUi(this);
    connect(ui->volumeSlider, SIGNAL(valueChanged(int)), ui->soundButtons, SLOT(setVolume(int)));
}

HomeScreen::~HomeScreen()
{
    delete ui;
}
