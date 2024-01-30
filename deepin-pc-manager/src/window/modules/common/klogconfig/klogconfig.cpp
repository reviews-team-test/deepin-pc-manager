// SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <QtGlobal>

#include "klogconfig.h"

int KLogConfig::m_slogLevel = 6;

KLogConfig::KLogConfig(QObject *parent)
    : QObject(parent)
{
    qInstallMessageHandler(qtLoggerMessageHandler);
}

//由于未定义
void KLogConfig::setFileLogLevel(bool isStatus)
{
    m_slogLevel = isStatus ? 0 : 6;
}

void KLogConfig::qtLoggerMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Logger::LogLevel level;

    switch (type) {
#if QT_VERSION >= 0x050500
    case QtInfoMsg:
        level = Logger::Info;
        break;
#endif
    case QtWarningMsg:
        level = Logger::Warning;
        break;
    case QtCriticalMsg:
        level = Logger::Error;
        break;
    case QtFatalMsg:
        level = Logger::Fatal;
        break;
    default:
        level = Logger::Debug;
        break;
    }

    if (level >= m_slogLevel) {
        bool isDefaultCategory = QString::fromLatin1(context.category) == "default";
        Logger::globalInstance()->write(level, context.file, context.line, context.function, isDefaultCategory ? nullptr : context.category, msg);
    }
}
