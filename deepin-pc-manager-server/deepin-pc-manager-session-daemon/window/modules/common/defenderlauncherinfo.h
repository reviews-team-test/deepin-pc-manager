/*
 * Copyright (C) 2021 ~ 2021 Uniontech Software Technology Co.,Ltd.
 *
 * Author:     herun <herun@uniontech.com>
 *
 * Maintainer: herun <herun@uniontech.com>
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

#ifndef SOCKETLAUNCHERINFO_H
#define SOCKETLAUNCHERINFO_H

#include <QtCore/QString>
#include <QtDBus/QtDBus>
#include <QDBusMetaType>
#include <QtCore/QList>

// com.deepin.dde.daemon.Launcher dbus GetAllItemInfos获取的结构体信息
struct LauncherItemInfo {
    QString Path;
    QString Name;
    QString ID;
    QString Icon;
    qint64 CategoryID;
    qint64 TimeInstalled;
};
Q_DECLARE_METATYPE(LauncherItemInfo);

typedef QList<LauncherItemInfo> LauncherItemInfoList;
Q_DECLARE_METATYPE(LauncherItemInfoList)

// 重载launcher dbus GetAllItemInfos获取的结构体操作符函数
const QDBusArgument &operator>>(const QDBusArgument &argument, LauncherItemInfo &iteminfos);
const QDBusArgument &operator<<(QDBusArgument &argument, const LauncherItemInfo &iteminfos);
void registerLauncherItemInfoMetaType();
void registerLauncherItemInfoListMetaType();

#endif // SOCKETLAUNCHERINFO_H
