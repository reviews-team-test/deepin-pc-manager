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
#ifndef DBUS_INVOKE_INTERFACE_H
#define DBUS_INVOKE_INTERFACE_H

#include <QObject>
#include <QVariant>
#include <QtDBus/QDBusMessage>

enum ConnectType {
    SYSTEM,
    SESSION
};

enum InvokeType {
    CALL,
    SIGNAL
};

enum BlockMode {
    NOBLOCK,
    BLOCK,
    BLOCKWITHGUI,
    AUTODETECT
};

// interface
class DBusInvokerInterface
{
public:
    virtual QDBusMessage Invoke(const QString &name, const QList<QVariant> &functionParams = QList<QVariant>(), BlockMode mode = BlockMode::BLOCKWITHGUI) = 0;
    virtual bool EmitSignal(const QString &name, const QList<QVariant> &arguments = QList<QVariant>()) = 0;
    virtual bool Connect(const QString &signal, QObject *reciver, const char *slot) = 0;
    virtual bool Disconnect(const QString &signal, QObject *reciver, const char *slot) = 0;
    virtual ~DBusInvokerInterface() {}
};

class SettingsInvokerInterface
{
public:
    virtual QVariant GetValue(const QString &key) const = 0;
    virtual void SetValue(const QString &key, const QVariant &value) = 0;
    virtual void Reset(const QString &key) = 0;
    virtual ~SettingsInvokerInterface() {}
};

class InvokerFactoryInterface
{
public:
    virtual DBusInvokerInterface *CreateInvoker(const QString &service, const QString &path, const QString &interface, ConnectType type = ConnectType::SESSION, QObject *parent = nullptr) = 0;
    virtual SettingsInvokerInterface *CreateSettings(const QByteArray &schema_id, const QByteArray &path = QByteArray(), QObject *parent = nullptr) = 0;
    virtual ~InvokerFactoryInterface() {}
};

#endif
