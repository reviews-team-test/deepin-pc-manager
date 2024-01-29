/*
 * Copyright (C) 2022 ~ 2022 UnionTech Software Technology Co., Ltd.
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
#ifndef AUTHORITYWRAPPER_H
#define AUTHORITYWRAPPER_H

#include "defenderauthority.h"

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QMutexLocker>

class DefenderAuthority;

class DefenderAuthorityWrapper : public QObject
{
    Q_OBJECT

public:
    explicit DefenderAuthorityWrapper(QObject *parent);
    ~DefenderAuthorityWrapper();

    void initConnection();

Q_SIGNALS:
    // 转发信号
    void notifyAuthStarted();
    void notifyAuthFinished();
    void notifyAuthResult(const QString &moduleName, int id, bool result);
    void onAuthRequest(const QString &moduleName, int id);

    void onModulesActived();

private:
    QThread m_authThread;
    DefenderAuthority *m_authority;
};

#endif // AUTHORITYWRAPPER_H
