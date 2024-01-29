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

#include "defsecuritytoolsbaseinstaller.h"
#include "defsecuritytoolsdbusinstaller.h"
#include "defsecuritytoolswineinstaller.h"
#include "window/modules/common/invokers/invokerfactory.h"

#include <QtDBus/QDBusInterface>
#include <QtDBus/QDBusPendingCallWatcher>
#include <QtDBus/QDBusError>
#include <QJsonObject>
#include <QJsonArray>
#include <QProcess>
#include <QDebug>

DefSecurityToolsBaseInstaller::DefSecurityToolsBaseInstaller(QObject *parent)
    : QObject(parent)
    , m_pManagerInvoker(nullptr)
    , m_jobPath("")
    , m_strType("")
    , m_strStatus("")
    , m_bUpdate(false)
{
}

DefSecurityToolsBaseInstaller::~DefSecurityToolsBaseInstaller()
{
}

void DefSecurityToolsBaseInstaller::setInfo(const DEFSECURITYTOOLINFO &info)
{
    m_info = info;
}

DEFSECURITYTOOLINFO DefSecurityToolsBaseInstaller::toolInfo() const
{
    return m_info;
}

void DefSecurityToolsBaseInstaller::setLatestPackageInfo(const PACKAGEMSG &packagemsg)
{
    m_LatestPackageMsg = packagemsg;
}

void DefSecurityToolsBaseInstaller::installPackage()
{
    if (!isPackageInstallable()) {
        Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::INSTALLFAILED);
        return;
    }

    Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::INSTALLING);
    qInfo() << "Begin Install Package";
    m_bUpdate = false;
    DBUS_NOBLOCK_INVOKE(m_pManagerInvoker, "IntallPackage", "deepin-defender", m_info.strPackageName);
}

void DefSecurityToolsBaseInstaller::unInstallPackage()
{
    if (!isPackageExist()) {
        Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::UNINSTALLFAILED);
    }

    Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::UNINSTALLING);
    DBUS_NOBLOCK_INVOKE(m_pManagerInvoker, "RemovePackage", "deepin-defender", m_info.strPackageName);
}

void DefSecurityToolsBaseInstaller::updatePackage()
{
    if (!isPackageExist()) {
        Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::UPDATEFAIL);
    }

    Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::UPDATING);
    qInfo() << "Begin Update Package";
    m_bUpdate = true;
    DBUS_NOBLOCK_INVOKE(m_pManagerInvoker, "IntallPackage", "deepin-defender", m_info.strPackageName);
}

void DefSecurityToolsBaseInstaller::setStoreManagerInter(DBusInvokerInterface *pInterface)
{
    if (m_pManagerInvoker) {
        m_pManagerInvoker->Disconnect("sigStartInstall", this, SLOT(onInstallStart(const QString &, const QString &)));
        m_pManagerInvoker->Disconnect("sigIntallProgress", this, SLOT(onSigIntallProgress(const QString &, const QString &, int, int, int, const QString &)));
        m_pManagerInvoker->Disconnect("sigRemoveProgress", this, SLOT(onSigRemoveProgress(const QString &, const QString &, bool)));
    }

    m_pManagerInvoker = pInterface;
    m_pManagerInvoker->Connect("sigStartInstall", this, SLOT(onInstallStart(const QString &, const QString &)));
    m_pManagerInvoker->Connect("sigIntallProgress", this, SLOT(onSigIntallProgress(const QString &, const QString &, int, int, int, const QString &)));
    m_pManagerInvoker->Connect("sigRemoveProgress", this, SLOT(onSigRemoveProgress(const QString &, const QString &, bool)));
}

bool DefSecurityToolsBaseInstaller::isPackageExist()
{
    QDBusMessage msg = DBUS_BLOCK_INVOKE(m_pManagerInvoker, "GetLocalPackageInfo", m_info.strPackageName);
    GET_MESSAGE_VALUE(QString, strMsg, msg);
    return !strMsg.isEmpty();
}

bool DefSecurityToolsBaseInstaller::isUpdatable()
{
    QDBusMessage msg = DBUS_BLOCK_INVOKE(m_pManagerInvoker, "GetLocalPackageInfo", m_info.strPackageName);
    GET_MESSAGE_VALUE(QString, strLocal, msg);

    if (strLocal.trimmed().isEmpty()) {
        return false;
    }

    PACKAGEMSG localPackage = getLocalPackageInfo(strLocal);
    return (localPackage < m_LatestPackageMsg);
}

bool DefSecurityToolsBaseInstaller::isPackageInstallable()
{
    bool bInstallAble = false;
    QString strCmd = QString("apt policy %1").arg(m_info.strPackageName);
    QProcess process;
    process.start(strCmd);

    if (process.waitForStarted()) {
        qDebug() << "process id" << process.pid();

        if (process.waitForFinished()) {
            QByteArray byArr = process.readAllStandardOutput();
            QString strMsg = QString::fromLocal8Bit(byArr);

            if (!strMsg.contains("N:") && strMsg.contains(m_info.strPackageName)) {
                bInstallAble = true;
            }
        }
    }

    return bInstallAble;
}

PACKAGEMSG DefSecurityToolsBaseInstaller::getLocalPackageInfo(QString strMsg)
{
    PACKAGEMSG packageMsg;
    int iIndex = strMsg.indexOf("[");

    if (iIndex < 0) {
        qWarning() << "Error Package Message!";
        return packageMsg;
    }

    strMsg = strMsg.left(iIndex).trimmed();
    QStringList strList = strMsg.split(" ");

    if (strList.count() != 3) {
        qWarning() << "Error Package Message!";
        return packageMsg;
    }

    packageMsg.strPackageName = strList.at(0);
    packageMsg.strVersion = strList.at(1);
    return packageMsg;
}

void DefSecurityToolsBaseInstaller::showtool(const QStringList &strParams)
{
    Q_UNUSED(strParams);
}

void DefSecurityToolsBaseInstaller::onInstallStart(const QString &strID, const QString &strPackage)
{
    Q_UNUSED(strID);

    if (strPackage.trimmed() == m_info.strPackageName) {
        Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::INSTALLING);
    }
}

void DefSecurityToolsBaseInstaller::onSigIntallProgress(const QString &strID, const QString &strPackage, int iState, int iTotal, int iProcess, const QString &strStatusMsg)
{
    Q_UNUSED(strID);
    Q_UNUSED(strStatusMsg);

    if (strPackage.trimmed() == m_info.strPackageName) {
        if (1 == iState) {
            if (iTotal > 0) {
                if (iProcess < 0) { //安装失败
                    if (m_bUpdate) {
                        Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::UPDATEFAIL);
                    } else {
                        Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::INSTALLFAILED);
                    }
                } else if (iProcess < iTotal) { //安装中
#ifdef QT_DEBUG
                    if (m_bUpdate) {
                        Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::UPDATING);
                    } else {
                        Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::INSTALLING);
                    }
#endif
                } else { //安装成功
                    if (m_bUpdate) {
                        Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::UPDATASUCCESS);
                    } else {
                        Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::INSTALLSUCCESS);
                    }
                }
            } else { //表示安装进度输出，用于客户端显示进度
#ifdef QT_DEBUG
                if (m_bUpdate) {
                    Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::UPDATING);
                } else {
                    Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::INSTALLING);
                }
#endif
            }
        } else if (0 == iState) {
            if (iTotal > 0) {
                if (iProcess < 0) { //下载失败
                    if (m_bUpdate) {
                        Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::UPDATEFAIL);
                    } else {
                        Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::INSTALLFAILED);
                    }
                }
#ifdef QT_DEBUG
                else if (iProcess < iTotal) { //下载中
                    if (m_bUpdate) {
                        Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::UPDATING);
                    } else {
                        Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::INSTALLING);
                    }
                } else { //下载成功
                    if (m_bUpdate) {
                        Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::UPDATING);
                    } else {
                        Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::INSTALLING);
                    }
                }
#endif
            } else { //异常
                if (m_bUpdate) {
                    Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::UPDATEFAIL);
                } else {
                    Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::INSTALLFAILED);
                }
            }
        }
    }
}

void DefSecurityToolsBaseInstaller::onSigRemoveProgress(const QString &strID, const QString &strPackage, bool bSuccess)
{
    Q_UNUSED(strID);

    if (strPackage.trimmed() == m_info.strPackageName) {
        if (bSuccess) {
            Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::UNINSTALLED);
        } else {
            Q_EMIT sAppStatusChanged(m_info.getPackageKey(), DEFSECURITYTOOLSTATUS::UNINSTALLFAILED);
        }
    }
}

DefSecurityToolsInstallerFactory::DefSecurityToolsInstallerFactory(QObject *parent)
    : QObject(parent)
{
}

DefSecurityToolsInstallerFactory::~DefSecurityToolsInstallerFactory()
{
}

DefSecurityToolsBaseInstaller *DefSecurityToolsInstallerFactory::createInstaller(const DEFSECURITYTOOLINFO &info)
{
    DefSecurityToolsBaseInstaller *pInstaller = nullptr;

    if (info.strInallModel == "dbus") {
        pInstaller = new DefSecurityToolsDbusInstaller;
    } else if (info.strInallModel == "wine") {
        pInstaller = new DefSecurityToolsWineInstaller;
    }

    return pInstaller;
}
