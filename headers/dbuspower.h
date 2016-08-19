#ifndef DBUSPOWER_H
#define DBUSPOWER_H


/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -c DBusPower -p dbuspower com.deepin.daemon.Power.xml
 *
 * qdbusxml2cpp is Copyright (C) 2015 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */


#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

typedef QMap<QString, quint32> BatteryStateMap;
typedef QMap<QString, double> BatteryPercentageMap;
Q_DECLARE_METATYPE(BatteryPercentageMap)
Q_DECLARE_METATYPE(BatteryStateMap)

/*
 * Proxy class for interface com.deepin.daemon.Power
 */
class DBusPower: public QDBusAbstractInterface
{
    Q_OBJECT

    Q_SLOT void __propertyChanged__(const QDBusMessage& msg)
    {
        QList<QVariant> arguments = msg.arguments();
        if (3 != arguments.count())
            return;
        QString interfaceName = msg.arguments().at(0).toString();
        if (interfaceName !="com.deepin.daemon.Power")
            return;
        QVariantMap changedProps = qdbus_cast<QVariantMap>(arguments.at(1).value<QDBusArgument>());
        foreach(const QString &prop, changedProps.keys()) {
        const QMetaObject* self = metaObject();
            for (int i=self->propertyOffset(); i < self->propertyCount(); ++i) {
                QMetaProperty p = self->property(i);
                if (p.name() == prop) {
                Q_EMIT p.notifySignal().invoke(this);
                }
            }
        }
   }
public:
    static inline const char *staticInterfaceName()
    { return "com.deepin.daemon.Power"; }

public:
    explicit DBusPower(QObject *parent = 0);

    ~DBusPower();

    Q_PROPERTY(bool OnBattery READ onBattery NOTIFY OnBatteryChanged)
    inline bool onBattery() const
    { return qvariant_cast< bool >(property("OnBattery")); }

    Q_PROPERTY(BatteryPercentageMap BatteryPercentage READ batteryPercentage NOTIFY BatteryPercentageChanged)
    inline BatteryPercentageMap batteryPercentage() const
    { return qvariant_cast< BatteryPercentageMap >(property("BatteryPercentage")); }

    Q_PROPERTY(BatteryStateMap BatteryState READ batteryState NOTIFY BatteryStateChanged)
    inline BatteryStateMap batteryState() const
    { return qvariant_cast< BatteryStateMap >(property("BatteryState")); }

public Q_SLOTS: // METHODS
Q_SIGNALS: // SIGNALS
// begin property changed signals
void OnBatteryChanged();
void BatteryPercentageChanged();
void BatteryStateChanged();
};

namespace com {
  namespace deepin {
    namespace daemon {
      typedef ::DBusPower Power;
    }
  }
}


#endif // DBUSPOWER_H
