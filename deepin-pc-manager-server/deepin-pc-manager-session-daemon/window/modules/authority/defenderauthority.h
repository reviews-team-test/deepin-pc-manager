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
#ifndef DEFENDERAUTHORIZEADAPTER_H
#define DEFENDERAUTHORIZEADAPTER_H

#include <QObject>
#include <QMutex>
#include <QMutexLocker>

#include <polkit-qt5-1/PolkitQt1/Authority>

using namespace PolkitQt1;

class DefenderAuthority : public QObject
{
    Q_OBJECT

public:
    explicit DefenderAuthority(QObject *parent = nullptr);
    ~DefenderAuthority();

public Q_SLOTS:
    // 外部通知，需要进行授权
    void checkAuthorization(const QString &, int);
    void onModulesActived();

private:
    void preAuthorize();

    void postAuthorize();

    void processAuthorize(const QString &, int);
    Authority::ErrorCode checkAuthorizeStatus();

Q_SIGNALS:
    // 告知界面状态变化,所以界面都需要处理
    void notifyAuthStarted();
    void notifyAuthFinished();

    // 告知授权结果
    void notifyAuthResult(const QString &, int, bool);
    // 告知状态错误,返回授权是否可用
    void notifyAuthStatusAbnormal(int);

private:
    QMutex m_mutex;
    QPair<QString, int> m_currentAuthRequest;
};

#endif // DEFENDERAUTHORIZEADAPTER_H
