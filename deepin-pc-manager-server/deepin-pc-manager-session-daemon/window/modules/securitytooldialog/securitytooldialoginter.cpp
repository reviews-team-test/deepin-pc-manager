/*
 * Copyright (C) 2022 ~ 2022 Deepin Technology Co., Ltd.
 *
 * Author:     caimengci <caimengci@uniontech.com>
 *
 * Maintainer: caimengci <caimengci@uniontech.com>
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
#include "securitytooldialoginter.h"
#include "window/modules/securitytooldialog/startupdialog/autostartmodel.h"

#include <QDBusContext>
#include <QGSettings>

const QString service = "com.deepin.pc.manager.securitytooldialog";
const QString path = "/com/deepin/pc/manager/securitytooldialog";

// 自动化标签
#define SET_ACCESS_NAME_T(control, className, name) control->setAccessibleName(ACCNAMESTR(className##_##name));
#define SET_ACC_NAME(control, name) SET_ACCESS_NAME_T(control, securityToolDialogInter, name)

SecurityToolDialogInter::SecurityToolDialogInter(QObject *parent)
    : QObject(parent)
    , m_guiHelper(nullptr)
    , m_gsetting(new QGSettings(DEEPIN_PC_MANAGER_GSETTING_PATH, QByteArray(), this))
    , m_adaptor(nullptr)
    , m_autoStartupMwnd(nullptr)
{
    m_adaptor = new SecuritytooldialogAdaptor(this);
    m_pToolBusLineMgr = new DefSecurityToolsBusLineMgr;
    DefToolAuthorityCheckObj *pCheckObj = new DefToolAuthorityCheckObj(m_pToolBusLineMgr);
    m_pToolBusLineMgr->setAutorityCheckObj(pCheckObj);

    if (!QDBusConnection::sessionBus().registerService(service) || !QDBusConnection::sessionBus().registerObject(path, this)) {
        exit(0);
    }

    // 主题
    m_guiHelper = DGuiApplicationHelper::instance();
    getDefenderPaletteType();

    //安全工具信息
    registerDefSecurityToolInfo();
    registerDefSecurityToolInfoList();
    initConnections();
}

SecurityToolDialogInter::~SecurityToolDialogInter()
{
    if (m_autoStartupMwnd) {
        m_autoStartupMwnd->deleteLater();
        m_autoStartupMwnd = nullptr;
    }

    if (m_pToolBusLineMgr) {
        m_pToolBusLineMgr->deleteLater();
        m_pToolBusLineMgr = nullptr;
    }
}

void SecurityToolDialogInter::initConnections()
{
    QObject::connect(m_pToolBusLineMgr, &DefSecurityToolsBusLineMgr::notifyToolsInfoUpdate, this, &SecurityToolDialogInter::notifyToolsInfoUpdate);
    QObject::connect(m_pToolBusLineMgr, &DefSecurityToolsBusLineMgr::notifyAppStatusChanged, this, &SecurityToolDialogInter::acceptAppStatusChanged);
}

void SecurityToolDialogInter::getDefenderPaletteType()
{
    int type = m_gsetting->get(DEFENDER_PALETTE_TYPE).toInt();
    m_guiHelper->setPaletteType(DGuiApplicationHelper::ColorType(type));
}

void SecurityToolDialogInter::SetDefenderPaletteType(int type)
{
    m_gsetting->set(DEFENDER_PALETTE_TYPE, type);
    m_guiHelper->setPaletteType(DGuiApplicationHelper::ColorType(type));
}

// 显示自启动管理弹框
void SecurityToolDialogInter::ShowStartup()
{
    if (!m_autoStartupMwnd) {
        m_autoStartupMwnd = new StartupMainWindow;
        connect(m_autoStartupMwnd, &StartupMainWindow::sendWindowClose, this, [=] {
            m_autoStartupMwnd->deleteLater();
            m_autoStartupMwnd = nullptr;
        });
    }

    m_autoStartupMwnd->show();
    m_autoStartupMwnd->activateWindow();
}

void SecurityToolDialogInter::OnRequestUpdateToolsInfo()
{
    m_pToolBusLineMgr->init();
}

void SecurityToolDialogInter::OnInstallPackage(const QString &strPackageKey)
{
    m_pToolBusLineMgr->installPackage(strPackageKey);
}

void SecurityToolDialogInter::OnUnInstallPackage(const QString &strPackageKey)
{
    m_pToolBusLineMgr->unInstallPackage(strPackageKey);
}

void SecurityToolDialogInter::OnUpdatePackage(const QString &strPackageKey)
{
    m_pToolBusLineMgr->updatePackage(strPackageKey);
}

void SecurityToolDialogInter::OnShowTool(const QString &strPackageKey, const QStringList &strParams)
{
    m_pToolBusLineMgr->showTool(strPackageKey, strParams);
}

// 接收app状态改变槽
void SecurityToolDialogInter::acceptAppStatusChanged(const QString &strPackageKey, DEFSECURITYTOOLSTATUS status)
{
    Q_EMIT notifyAppStatusChanged(strPackageKey, status);

    if (DEFSECURITYTOOLSTATUS::INSTALLING == status) {
        if (!m_appInstalling.contains(strPackageKey)) {
            m_appInstalling.append(strPackageKey);
        }
    } else if (DEFSECURITYTOOLSTATUS::UPDATING == status) {
        if (!m_appUpdating.contains(strPackageKey)) {
            m_appUpdating.append(strPackageKey);
        }
    } else if (DEFSECURITYTOOLSTATUS::UNINSTALLING == status) {
        if (!m_appUninstalling.contains(strPackageKey)) {
            m_appUninstalling.append(strPackageKey);
        }
    } else {
        if (m_appInstalling.contains(strPackageKey)) {
            m_appInstalling.removeOne(strPackageKey);
        }
        if (m_appUpdating.contains(strPackageKey)) {
            m_appUpdating.removeOne(strPackageKey);
        }
        if (m_appUninstalling.contains(strPackageKey)) {
            m_appUninstalling.removeOne(strPackageKey);
        }
    }
}
