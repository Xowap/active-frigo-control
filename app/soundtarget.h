#ifndef SOUNDTARGET_H
#define SOUNDTARGET_H

#include <QString>
#include <QStringList>

class SoundTarget
{
public:
    SoundTarget() {}
    SoundTarget(const QString &name, int volume, const QStringList &hosts) :
        name(name), volume(volume), hosts(hosts) {}
    ~SoundTarget() {}

    QString getName() const;
    void setName(const QString &value);

    int getVolume() const;
    void setVolume(int value);

    QStringList getHosts() const;
    void setHosts(const QStringList &value);
    void addHost(const QString &value);

private:
    QString name;
    int volume;
    QStringList hosts;
};

#endif // SOUNDTARGET_H
