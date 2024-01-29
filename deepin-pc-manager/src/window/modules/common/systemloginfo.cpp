// Copyright (C) 2020 ~ 2022 Uniontech Software Co., Ltd.
// SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include "systemloginfo.h"

void registerSystemLogInfoType()
{
    qRegisterMetaType<SystemLogInfo>("SystemLogInfo");
    qDBusRegisterMetaType<SystemLogInfo>();
    qRegisterMetaType<SystemLogInfoList>("SystemLogInfoList");
    qDBusRegisterMetaType<SystemLogInfoList>();
}

QDBusArgument &operator<<(QDBusArgument &argument, const SystemLogInfo &logInfo)
{
    argument.beginStructure();
    argument << logInfo.datetime << logInfo.category << logInfo.content;
    argument.endStructure();
    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, SystemLogInfo &logInfo)
{
    argument.beginStructure();
    argument >> logInfo.datetime >> logInfo.category >> logInfo.content;
    argument.endStructure();
    return argument;
}
