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

#ifndef KLOGMANAGER_H
#define KLOGMANAGER_H

#include <QObject>
#include <Logger.h>

DCORE_USE_NAMESPACE

class KLogConfig : public QObject
{
    Q_OBJECT
public:
    explicit KLogConfig(QObject *parent = nullptr);

public:
    void setFileLogLevel(int level); //6,对应于不输出日志，其它值参见Logger.h中的LogLevel值。

private:
    static void qtLoggerMessageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg);

private:
    static int m_slogLevel;
};

#endif // KLOGMANAGER_H
