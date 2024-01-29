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
#include "invokerfactory.h"
#include "dbusinvoker.h"
#include "deepindefendersettingsInvoker.h"

InvokerFactory::InvokerFactory()
{
}

InvokerFactory::~InvokerFactory()
{
}

DBusInvokerInterface *InvokerFactory::CreateInvoker(const QString &service, const QString &path, const QString &interface, ConnectType type, QObject *parent)
{
#ifdef DEEPIN_DEFENDER_UNITTEST
    if (m_intefaceMap.contains(interface)) {
        // 这个逻辑是为了单元测试的配置需要增加的
        // 父指针在设置前指定
        return m_intefaceMap.value(interface);
    } else {
        // 使用者自行处理,必须通过set方法设置interface
        return nullptr;
    }

#endif
    return new DBusInvoker(service, path, interface, type, parent);
}

SettingsInvokerInterface *InvokerFactory::CreateSettings(const QByteArray &schema_id, const QByteArray &path, QObject *parent)
{
#ifdef DEEPIN_DEFENDER_UNITTEST
    if (m_settingsMap.contains(schema_id)) {
        // 这个逻辑是为了单元测试的配置需要增加的
        // 父指针在设置前指定
        return m_settingsMap.value(schema_id);
    } else {
        // 使用者自行处理,必须通过set方法设置interface
        return nullptr;
    }
#endif
    return new DeepinDefenderSettingsInvoker(schema_id, path, parent);
}

// 单元测试扩展处理
void InvokerFactory::setInvokerInteface(const QString &interfaceName, DBusInvokerInterface *interface)
{
#ifdef DEEPIN_DEFENDER_UNITTEST
    // 不关心是否重复
    m_intefaceMap.insert(interfaceName, interface);
#else
    Q_UNUSED(interfaceName);
    Q_UNUSED(interface);
#endif
}

// 单元测试扩展处理
void InvokerFactory::setSettinsInteface(const QString &settingName, SettingsInvokerInterface *interface)
{
#ifdef DEEPIN_DEFENDER_UNITTEST
    // 不关心是否重复
    m_settingsMap.insert(settingName, interface);
#else
    Q_UNUSED(settingName);
    Q_UNUSED(interface);
#endif
}
