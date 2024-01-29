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
#include "defenderauthoritywrapper.h"
#include "defenderauthority.h"

DefenderAuthorityWrapper::DefenderAuthorityWrapper(QObject *parent)
    : QObject(parent)
{
    m_authority = new DefenderAuthority;

    if (m_authority) {
        initConnection();
        m_authority->moveToThread(&m_authThread);
        m_authThread.start();
    }
}

DefenderAuthorityWrapper::~DefenderAuthorityWrapper()
{
    if (m_authority) {
        m_authority->deleteLater();
        m_authority = nullptr;
    }
    m_authThread.quit();
    m_authThread.wait(1000);
}

// 只处理信号转发
void DefenderAuthorityWrapper::initConnection()
{
    connect(m_authority, &DefenderAuthority::notifyAuthStarted, this, &DefenderAuthorityWrapper::notifyAuthStarted);
    connect(m_authority, &DefenderAuthority::notifyAuthFinished, this, &DefenderAuthorityWrapper::notifyAuthFinished);
    connect(m_authority, &DefenderAuthority::notifyAuthResult, this, &DefenderAuthorityWrapper::notifyAuthResult);

    connect(this, &DefenderAuthorityWrapper::onModulesActived, m_authority, &DefenderAuthority::onModulesActived);
    connect(this, &DefenderAuthorityWrapper::onAuthRequest, m_authority, &DefenderAuthority::checkAuthorization);
}
