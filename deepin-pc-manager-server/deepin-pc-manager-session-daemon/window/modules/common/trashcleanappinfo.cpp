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

#include "trashcleanappinfo.h"

QDBusArgument &operator<<(QDBusArgument &argument, const TrashCleanAppInfo &appInfo)
{
    argument.beginStructure();
    argument << appInfo.isUnistalled << appInfo.appPkgName << appInfo.appDisplayName
             << appInfo.appConfigPaths << appInfo.appCachePaths;
    argument.endStructure();
    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, TrashCleanAppInfo &appInfo)
{
    argument.beginStructure();
    argument >> appInfo.isUnistalled >> appInfo.appPkgName >> appInfo.appDisplayName
        >> appInfo.appConfigPaths >> appInfo.appCachePaths;
    argument.endStructure();
    return argument;
}

void registerTrashCleanAppInfoMetaType()
{
    qRegisterMetaType<TrashCleanAppInfo>("TrashCleanAppInfo");
    qDBusRegisterMetaType<TrashCleanAppInfo>();
}

void registerTrashCleanAppInfoListMetaType()
{
    qRegisterMetaType<TrashCleanAppInfoList>("TrashCleanAppInfoList");
    qDBusRegisterMetaType<TrashCleanAppInfoList>();
}
