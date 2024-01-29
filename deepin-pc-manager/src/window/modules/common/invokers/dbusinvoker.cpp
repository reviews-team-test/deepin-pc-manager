/*
 * Copyright (C) 2021 ~ 2021 Deepin Technology Co., Ltd.
 *
 * Author:     xuxin <xuxina@uniontech.com>
 *
 * Maintainer: xuxin <xuxina@uniontech.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "dbusinvoker.h"
#include "../common.h"

#include <QDebug>
#include <QDBusVariant>

DBusInvoker::DBusInvoker(const QString &service, const QString &path, const QString &interface, ConnectType type, QObject *parent)
    : QObject(parent)
    , m_service(service)
    , m_path(path)
    , m_interface(interface)
    , m_type(type)
    , m_connection(QDBusConnection::sessionBus())
{
    if (SYSTEM == m_type) {
        m_connection = QDBusConnection::systemBus();
    }
}

// signal-slot connection
bool DBusInvoker::Connect(const QString &signal, QObject *reciver, const char *slot)
{
    bool connectRst = false;
    connectRst = m_connection.connect(m_service, m_path, m_interface, signal, reciver, slot);
    if (!connectRst) {
        qCritical() << "signal connect failed : " << signal << "for reason [" << m_connection.lastError().message() << "]";
    }
    Q_ASSERT(connectRst);
    return connectRst;
}

// signal-slot disconnection
bool DBusInvoker::Disconnect(const QString &signal, QObject *reciver, const char *slot)
{
    bool disconnectRst = false;
    disconnectRst = m_connection.disconnect(m_service, m_path, m_interface, signal, reciver, slot);
    if (!disconnectRst) {
        qCritical() << "signal disconnect failed : " << signal << "for reason [" << m_connection.lastError().message() << "]";
    }
    Q_ASSERT(disconnectRst);
    return disconnectRst;
}

DBusInvoker::~DBusInvoker()
{
    // 确保在调用delete时，释放自身成员对象
    deleteLater();
}

// create method call or signal emit
// invoke like this :
// invoker->Connect("signalFunc", this, SLOT(slotFunc(bool, QString)));
// there would be param type validate when signal emitted
QDBusMessage DBusInvoker::Invoke(const QString &name, const QList<QVariant> &functionParams, BlockMode mode)
{
    if (name.isEmpty()) {
        return QDBusMessage::createError(QDBusError::InvalidArgs, QString("name.isEmpty"));
    }

    QDBusMessage msg;
    if (DBUS_PROPERTY_INVOKER_NAME == name) {
        if (functionParams.isEmpty()) {
            return QDBusMessage::createError(QDBusError::InvalidArgs, QString("property not exist"));
        }

        msg = QDBusMessage::createMethodCall(m_service, m_path, "org.freedesktop.DBus.Properties", "Get");
        msg.setArguments({m_interface, functionParams.first().toString()});

        QDBusMessage retMsg = m_connection.call(msg, QDBus::CallMode(mode));
        return retMsg;
    }

    msg = QDBusMessage::createMethodCall(m_service, m_path, m_interface, name);
    msg.setArguments(functionParams);

    return m_connection.call(msg, QDBus::CallMode(mode));
}

// emit signal
bool DBusInvoker::EmitSignal(const QString &name, const QList<QVariant> &arguments)
{
    if (name.isEmpty()) {
        return false;
    }

    QDBusMessage signal = QDBusMessage::createSignal(m_path, m_interface, name);
    signal.setArguments(arguments);
    return m_connection.send(signal);
}
