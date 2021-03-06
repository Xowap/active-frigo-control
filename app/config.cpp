#include "config.h"
#include "soundset.h"

#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

SoundSetList Config::getSoundSets() const
{
    return soundSets;
}

void Config::load(const QString &filename)
{
    QFile f(filename);

    if (!f.open(QFile::ReadOnly)) {
        return;
    }

    QByteArray data = f.readAll();
    QJsonDocument document = QJsonDocument::fromJson(data);

    if (!document.isArray()) {
        return;
    }

    soundSets.clear();
    QJsonArray sets = document.array();

    foreach (QJsonValue value, sets) {
        if (!value.isObject()) {
            continue;
        }

        SoundSet set;
        QJsonObject rawSet = value.toObject();

        if (!rawSet["targets"].isArray() || !rawSet["name"].isString()) {
            continue;
        }

        set.setName(rawSet["name"].toString());

        foreach (QJsonValue rawTarget, rawSet["targets"].toArray()) {
            SoundTarget target;

            if (!rawTarget.isObject()) {
                continue;
            }

            QJsonObject objTarget = rawTarget.toObject();

            if (!objTarget["name"].isString()
                    || !objTarget["volume"].isDouble()
                    || !objTarget["hosts"].isArray()
                    || !objTarget["delay"].isDouble()) {
                continue;
            }

            target.setName(objTarget["name"].toString());
            target.setVolume(objTarget["volume"].toDouble());
            target.setDelay(objTarget["delay"].toDouble());

            foreach (QJsonValue host, objTarget["hosts"].toArray()) {
                if (!host.isString()) {
                    continue;
                }

                target.addHost(host.toString());
            }

            set.addTarget(target);
        }

        soundSets << set;
    }
}

Config::Config() :
    QObject(0)
{
}
