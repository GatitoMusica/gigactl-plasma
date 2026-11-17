
#pragma once

#include <QObject>
#include <QString>
#include <QDBusConnection>
#include <QStringList>
#include <QVariant>
#include <QVariantList>

#include <QtQml/qqmlregistration.h>

class QDBusServiceWatcher;

class GigactlDaemonClient : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(bool available
               READ available
               NOTIFY availabilityChanged)

    Q_PROPERTY(QString activeProfile
               READ activeProfile
               NOTIFY stateChanged)

    Q_PROPERTY(QString ecStatus
               READ ecStatus
               NOTIFY stateChanged)

    Q_PROPERTY(QString daemonVersion
               READ daemonVersion
               NOTIFY stateChanged)

    Q_PROPERTY(bool telemetryAvailable
               READ telemetryAvailable
               NOTIFY telemetryChanged)

    Q_PROPERTY(int cpuTemperature
               READ cpuTemperature
               NOTIFY telemetryChanged)

    Q_PROPERTY(int gpuTemperature
               READ gpuTemperature
               NOTIFY telemetryChanged)

    Q_PROPERTY(int cpuFanRpm
               READ cpuFanRpm
               NOTIFY telemetryChanged)

    Q_PROPERTY(int gpuFanRpm
               READ gpuFanRpm
               NOTIFY telemetryChanged)

    Q_PROPERTY(int cpuFanDuty
               READ cpuFanDuty
               NOTIFY telemetryChanged)

    Q_PROPERTY(int gpuFanDuty
               READ gpuFanDuty
               NOTIFY telemetryChanged)

    Q_PROPERTY(QString telemetryError
               READ telemetryError
               NOTIFY telemetryErrorChanged)

    Q_PROPERTY(bool turboAvailable
               READ turboAvailable
               NOTIFY turboStateChanged)

    Q_PROPERTY(bool turboBoost
               READ turboBoost
               NOTIFY turboStateChanged)

    Q_PROPERTY(bool keyboardEnabled
               READ keyboardEnabled
               NOTIFY keyboardStateChanged)

    Q_PROPERTY(int keyboardRed
               READ keyboardRed
               NOTIFY keyboardStateChanged)

    Q_PROPERTY(int keyboardGreen
               READ keyboardGreen
               NOTIFY keyboardStateChanged)

    Q_PROPERTY(int keyboardBlue
               READ keyboardBlue
               NOTIFY keyboardStateChanged)

    Q_PROPERTY(int keyboardBrightness
               READ keyboardBrightness
               NOTIFY keyboardStateChanged)

    Q_PROPERTY(QString error
               READ error
               NOTIFY errorChanged)


public:
    explicit GigactlDaemonClient(QObject *parent = nullptr);

    bool available() const;
    QString activeProfile() const;
    QString ecStatus() const;
    QString daemonVersion() const;
    bool telemetryAvailable() const;
    int cpuTemperature() const;
    int gpuTemperature() const;
    int cpuFanRpm() const;
    int gpuFanRpm() const;
    int cpuFanDuty() const;
    int gpuFanDuty() const;
    QString telemetryError() const;
    bool turboAvailable() const;
    bool turboBoost() const;
    bool keyboardEnabled() const;
    int keyboardRed() const;
    int keyboardGreen() const;
    int keyboardBlue() const;
    int keyboardBrightness() const;
    QString error() const;

    Q_INVOKABLE void refreshState();
    Q_INVOKABLE void refreshTelemetry();
    Q_INVOKABLE void setProfile(const QString &name);
    Q_INVOKABLE void restoreFirmware();
    Q_INVOKABLE void setTurboBoost(bool enabled);
    Q_INVOKABLE void setKeyboardColor(int red, int green, int blue);
    Q_INVOKABLE void setKeyboardBrightness(int percent);
    Q_INVOKABLE void setKeyboardEnabled(bool enabled);

Q_SIGNALS:
    void availabilityChanged();
    void stateChanged();
    void telemetryChanged();
    void telemetryErrorChanged();
    void turboStateChanged();
    void keyboardStateChanged();
    void errorChanged();

private:
    void setAvailable(bool available);
    void setError(const QString &message);
    void setTelemetryError(const QString &message);
    void readState();
    void callKeyboardMethod(
        const QString &method,
        const QVariantList &arguments,
        const QString &errorPrefix
    );

private Q_SLOTS:
    void onPropertiesChanged(
        const QString &interfaceName,
        const QVariantMap &changedProperties,
        const QStringList &invalidatedProperties
    );

private:
    QDBusConnection m_bus;
    QDBusServiceWatcher *m_serviceWatcher = nullptr;

    bool m_available = false;

    QString m_activeProfile;
    QString m_ecStatus;
    QString m_daemonVersion;
    bool m_telemetryAvailable = false;
    int m_cpuTemperature = -1;
    int m_gpuTemperature = -1;
    int m_cpuFanRpm = -1;
    int m_gpuFanRpm = -1;
    int m_cpuFanDuty = -1;
    int m_gpuFanDuty = -1;
    QString m_telemetryError;
    quint64 m_telemetryReadSerial = 0;
    bool m_telemetryReadPending = false;
    bool m_turboAvailable = false;
    bool m_turboBoost = false;
    quint64 m_turboAvailableRevision = 0;
    quint64 m_turboBoostRevision = 0;
    quint64 m_turboAvailableReadSerial = 0;
    quint64 m_turboBoostReadSerial = 0;
    bool m_keyboardEnabled = true;
    int m_keyboardRed = 0;
    int m_keyboardGreen = 0;
    int m_keyboardBlue = 200;
    int m_keyboardBrightness = 100;
    QString m_error;

};
