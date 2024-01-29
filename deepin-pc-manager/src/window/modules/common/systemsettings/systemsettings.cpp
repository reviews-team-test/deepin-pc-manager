/*
 * Copyright (C) 2019 ~ 2021 UnionTech Software Technology Co., Ltd.
 *
 * Author:     caitao <caitao@uniontech.com>
 *
 * Maintainer: caitao <caitao@uniontech.com>
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

#include "systemsettings.h"
#include "../invokers/invokerfactory.h"

#include <QDebug>
namespace def {
SystemSettings::SystemSettings(QObject *parent)
    : QObject(parent)
    , m_netMonitorDBusInvoker(nullptr)
{
    m_netMonitorDBusInvoker = InvokerFactory::GetInstance().CreateInvoker("com.deepin.pc.manager.MonitorNetFlow",
                                                                          "/com/deepin/pc/manager/MonitorNetFlow",
                                                                          "com.deepin.pc.manager.MonitorNetFlow",
                                                                          ConnectType::SYSTEM, this);

    m_netMonitorDBusInvoker->Connect("SysSettingValueChanged", this, SLOT(onValueChanged(QString, QDBusVariant)));
}

SystemSettings::~SystemSettings()
{
}

bool SystemSettings::setValue(const QString &key, const QVariant &value)
{
    // 装载到QDBusVariant
    QDBusVariant dbusVar(value);
    // 装载到QVariant
    QVariant var;
    var.setValue(dbusVar);
    QDBusMessage msg = DBUS_BLOCK_INVOKE(m_netMonitorDBusInvoker, "SetSysSettingValue", key, var);
    GET_MESSAGE_VALUE(bool, ret, msg);
    return ret;
}

QVariant SystemSettings::getValue(const QString &key)
{
    QDBusMessage msg = DBUS_BLOCK_INVOKE(m_netMonitorDBusInvoker, "GetSysSettingValue", key);
    GET_MESSAGE_VALUE(QDBusVariant, valueDBusVar, msg);
    return valueDBusVar.variant();
}

void SystemSettings::onValueChanged(const QString &key, const QDBusVariant &value)
{
    Q_EMIT valueChanged(key, value.variant());
}
} // namespace def
