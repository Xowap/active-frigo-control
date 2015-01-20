#ifndef SOUNDSET_H
#define SOUNDSET_H

#include <QString>
#include <QStringList>
#include <QList>

#include "soundtarget.h"

typedef QList<SoundTarget> SoundTargetList;

class SoundSet
{
public:
    SoundSet() {}
    SoundSet(const QString &name, const SoundTargetList &targets) :
        name(name), targets(targets) {}
    ~SoundSet() {}

    QString getName() const;
    void setName(const QString &value);

    SoundTargetList getTargets() const;
    void setTargets(const SoundTargetList &value);
    void addTarget(const SoundTarget &target);

private:
    QString name;
    SoundTargetList targets;
};

#endif // SOUNDSET_H
