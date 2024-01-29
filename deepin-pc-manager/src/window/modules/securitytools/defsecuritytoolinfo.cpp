/*
 * Copyright (C) 2020 ~ 2022 Uniontech Software Co., Ltd.
 *
 * Author:     shenfusheng <shenfusheng@uniontech.com>
 *
 * Maintainer: shenfusheng <shenfusheng@uniontech.com>
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

#include "defsecuritytoolinfo.h"

#include <QDBusMetaType>

void registerDefSecurityToolInfo()
{
    qRegisterMetaType<DEFSECURITYTOOLINFO>("DEFSECURITYTOOLINFO");
    qDBusRegisterMetaType<DEFSECURITYTOOLINFO>();
}

void registerDefSecurityToolInfoList()
{
    qRegisterMetaType<DEFSECURITYTOOLINFOLIST>("DEFSECURITYTOOLINFOLIST");
    qRegisterMetaType<QList<DEFSECURITYTOOLINFO>>("QList<DEFSECURITYTOOLINFO>");
    qDBusRegisterMetaType<DEFSECURITYTOOLINFOLIST>();
    qDBusRegisterMetaType<QList<DEFSECURITYTOOLINFO>>();
}

QDBusArgument &operator<<(QDBusArgument &argument, const DEFSECURITYTOOLINFO &toolInfo)
{
    argument.beginStructure();
    argument << toolInfo.strPackageName;
    argument << toolInfo.strAppName;
    argument << toolInfo.strImagePath;
    argument << toolInfo.strDescription;
    argument << toolInfo.strCompany;
    argument << toolInfo.strInallModel;
    argument << toolInfo.strCallMethodName;
    argument << toolInfo.bSystemTool;
    argument << toolInfo.bHasInstalled;
    argument << toolInfo.bCanUpdate;
    argument << toolInfo.iClassify;
    argument << toolInfo.strReserve;
    argument << toolInfo.strReserve2;
    argument << toolInfo.strReserve3;
    argument << toolInfo.strReserve4;
    argument.endStructure();
    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, DEFSECURITYTOOLINFO &toolInfo)
{
    argument.beginStructure();
    argument >> toolInfo.strPackageName;
    argument >> toolInfo.strAppName;
    argument >> toolInfo.strImagePath;
    argument >> toolInfo.strDescription;
    argument >> toolInfo.strCompany;
    argument >> toolInfo.strInallModel;
    argument >> toolInfo.strCallMethodName;
    argument >> toolInfo.bSystemTool;
    argument >> toolInfo.bHasInstalled;
    argument >> toolInfo.bCanUpdate;
    argument >> toolInfo.iClassify;
    argument >> toolInfo.strReserve;
    argument >> toolInfo.strReserve2;
    argument >> toolInfo.strReserve3;
    argument >> toolInfo.strReserve4;
    argument.endStructure();
    return argument;
}
