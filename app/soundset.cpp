#include "soundset.h"


QString SoundSet::getName() const
{
    return name;
}

void SoundSet::setName(const QString &value)
{
    name = value;
}

SoundTargetList SoundSet::getTargets() const
{
    return targets;
}

void SoundSet::setTargets(const SoundTargetList &value)
{
    targets = value;
}

void SoundSet::addTarget(const SoundTarget &target)
{
    targets << target;
}
