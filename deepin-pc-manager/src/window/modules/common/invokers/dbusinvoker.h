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
#ifndef DBUS_INVOKER_H
#define DBUS_INVOKER_H

#include "invokerinterface.h"

#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusReply>

// interface
class DBusInvoker : public QObject
    , public DBusInvokerInterface
{
    Q_OBJECT
public:
    DBusInvoker(const QString &service, const QString &path, const QString &interface, ConnectType type = ConnectType::SESSION, QObject *parent = nullptr);

    virtual QDBusMessage Invoke(const QString &name, const QList<QVariant> &functionParams = QList<QVariant>(), BlockMode mode = BlockMode::BLOCKWITHGUI) override;
    virtual bool EmitSignal(const QString &name, const QList<QVariant> &arguments = QList<QVariant>()) override;
    virtual bool Connect(const QString &signal, QObject *reciver, const char *slot) override;
    virtual bool Disconnect(const QString &signal, QObject *reciver, const char *slot) override;
    virtual ~DBusInvoker() override;

private:
    QString m_service;
    QString m_path;
    QString m_interface;
    ConnectType m_type;
    QDBusConnection m_connection;

private:
    DBusInvoker(const DBusInvoker &);
    DBusInvoker &operator=(const DBusInvoker &);
};

#endif
