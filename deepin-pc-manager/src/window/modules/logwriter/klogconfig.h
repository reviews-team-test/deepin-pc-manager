// Copyright (C) 2020 ~ 2022 Uniontech Software Co., Ltd.
// SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

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
