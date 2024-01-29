/*
 * Copyright (C) 2019 ~ 2021 Uniontech Software Technology Co.,Ltd.
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

#ifndef TRASHCLEANAPPINFO_H
#define TRASHCLEANAPPINFO_H

#include <QtCore/QString>
#include <QtDBus/QtDBus>
#include <QDBusMetaType>
#include <QtCore/QList>

struct TrashCleanAppInfo {
    bool isUnistalled;
    QString appPkgName;
    QString appDisplayName;
    QString appConfigPaths;
    QString appCachePaths;
    TrashCleanAppInfo()
    {
        isUnistalled = false;
        appPkgName = "";
        appDisplayName = "";
        appConfigPaths = "";
        appCachePaths = "";
    }
    bool operator!=(TrashCleanAppInfo &other)
    {
        return this->appPkgName != other.appPkgName;
    }
};

QDBusArgument &operator<<(QDBusArgument &argument, const TrashCleanAppInfo &procInfo);
const QDBusArgument &operator>>(const QDBusArgument &argument, TrashCleanAppInfo &procInfo);
Q_DECLARE_METATYPE(TrashCleanAppInfo);
void registerTrashCleanAppInfoMetaType();

typedef QList<TrashCleanAppInfo> TrashCleanAppInfoList;
Q_DECLARE_METATYPE(TrashCleanAppInfoList);
void registerTrashCleanAppInfoListMetaType();

#endif // TRASHCLEANAPPINFO_H
