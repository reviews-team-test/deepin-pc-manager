// Copyright (C) 2020 ~ 2022 Uniontech Software Co., Ltd.
// SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef SYSTEMLOGINFO_H
#define SYSTEMLOGINFO_H

#include <QMetaType>
#include <QDBusMetaType>

// 安全日志信息
struct SystemLogInfo {
    QString datetime;
    QString category;
    QString content;

    SystemLogInfo()
        : datetime("")
        , category("")
        , content("")
    {
    }

    SystemLogInfo(const SystemLogInfo &other)
    {
        if (this != &other) {
            datetime = other.datetime;
            category = other.category;
            content = other.content;
        }
    }

    SystemLogInfo &operator=(const SystemLogInfo &other)
    {
        if (this != &other) {
            datetime = other.datetime;
            category = other.category;
            content = other.content;
        }

        return *this;
    }
};

typedef QList<SystemLogInfo> SystemLogInfoList;
Q_DECLARE_METATYPE(SystemLogInfo);
Q_DECLARE_METATYPE(SystemLogInfoList);
void registerSystemLogInfoType();
QDBusArgument &operator<<(QDBusArgument &argument, const SystemLogInfo &logInfo);
const QDBusArgument &operator>>(const QDBusArgument &argument, SystemLogInfo &logInfo);
#endif // SYSTEMLOGINFO_H
