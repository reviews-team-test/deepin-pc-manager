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
