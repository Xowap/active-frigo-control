#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include <QList>

#include "soundset.h"

typedef QList<SoundSet> SoundSetList;

class Config : public QObject
{
    Q_OBJECT
public:
    ~Config() {}

    static Config *instance() {
        static Config instance;
        return &instance;
    }

    SoundSetList getSoundSets() const;
    int getDelayMsec() const;

public slots:
    void load(const QString &filename);

private:
    Config();
    explicit Config(Config const&); // Don't Implement
    void operator=(Config const&); // Don't implement

    SoundSetList soundSets;
};

#endif // CONFIG_H
