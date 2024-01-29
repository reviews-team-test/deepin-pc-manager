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
#include "defendermoduleauthorizebase.h"

#include <QDebug>

#define SERVER_NAME "com.deepin.pc.manager.session.daemon"
#define SERVER_PATH "/com/deepin/pc/manager/session/daemon"

DefenderModuleAuthorizeBase::DefenderModuleAuthorizeBase(const QString &moduleName, QObject *parent)
    : QObject(parent)
    , m_authService(nullptr)
    , m_moduleName(moduleName)
{
    m_authService = InvokerFactory::GetInstance().CreateInvoker(SERVER_NAME, SERVER_PATH, SERVER_NAME, ConnectType::SESSION, this);
    initServiceConnection();
    init();
}

DefenderModuleAuthorizeBase::~DefenderModuleAuthorizeBase()
{
}

void DefenderModuleAuthorizeBase::init()
{
    onModulesActived();
}

const QString &DefenderModuleAuthorizeBase::getModuleName()
{
    return m_moduleName;
}

// 转发信号与结果处理
void DefenderModuleAuthorizeBase::initServiceConnection()
{
    bool connSuccess = false;
    connSuccess = m_authService->Connect("NotifyAuthStarted", this, SIGNAL(onAuthorizeStarted()));
    if (!connSuccess) {
        qWarning() << Q_FUNC_INFO << "[NotifyAuthStarted] connecte failed!";
    }
    connSuccess = m_authService->Connect("NotifyAuthFinished", this, SIGNAL(onAuthorizeFinished()));
    if (!connSuccess) {
        qWarning() << Q_FUNC_INFO << "[NotifyAuthFinished] connecte failed!";
    }
    connSuccess = m_authService->Connect("NotifyAuthResult", this, SLOT(onAuthResultRecived(const QString &, int, bool)));
    if (!connSuccess) {
        qWarning() << Q_FUNC_INFO << "[NotifyAuthResult] connecte failed!";
    }
}

// 授权模块初始化时需要注册自己的模块名称
void DefenderModuleAuthorizeBase::onModulesActived()
{
    DBUS_NOBLOCK_INVOKE(m_authService, "ModulesRequestAuthorityActived");
}

// 请求授权
void DefenderModuleAuthorizeBase::requestAuthWithID(int id)
{
    DBUS_NOBLOCK_INVOKE(m_authService, "RequestAuthWithID", m_moduleName, id);
}

// 转发结果
// 连接到这个信号以处理授权结果
void DefenderModuleAuthorizeBase::onAuthResultRecived(const QString &moduleName, int id, bool result)
{
    if (moduleName == m_moduleName) {
        Q_EMIT onAuthorized(id, result);
    }
}
