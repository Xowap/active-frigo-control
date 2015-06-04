#include "soundtarget.h"


QString SoundTarget::getName() const
{
    return name;
}

void SoundTarget::setName(const QString &value)
{
    name = value;
}

int SoundTarget::getVolume() const
{
    return volume;
}

void SoundTarget::setVolume(int value)
{
    volume = value;
}

int SoundTarget::getDelay() const
{
    return delay;
}

void SoundTarget::setDelay(int value)
{
    delay = value;
}

QStringList SoundTarget::getHosts() const
{
    return hosts;
}

void SoundTarget::setHosts(const QStringList &value)
{
    hosts = value;
}

void SoundTarget::addHost(const QString &value)
{
    hosts << value;
}
