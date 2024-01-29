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

#ifndef DEFSECURITYTOOLSBASEINSTALLER_H
#define DEFSECURITYTOOLSBASEINSTALLER_H

#include "window/modules/securitytools/defsecuritytoolinfo.h"
#include "window/modules/common/invokers/invokerinterface.h"

#include <QObject>
#include <QDebug>

typedef struct PackageMsg {
    explicit PackageMsg()
        : strPackageName("")
        , strVersion("")
    {
    }

    bool operator<(const PackageMsg &otherPackage)
    {
        if (this == &otherPackage) {
            return true;
        }

        if (strPackageName != otherPackage.strPackageName) {
            qWarning() << "can't been compared!";
            return false;
        }

        return strVersion < otherPackage.strVersion;
    }

    QString strPackageName;
    QString strVersion;
} PACKAGEMSG, *LPPACKAGEMSG;

class DefSecurityToolsBaseInstaller : public QObject
{
    Q_OBJECT
public:
    explicit DefSecurityToolsBaseInstaller(QObject *parent = nullptr);
    virtual ~DefSecurityToolsBaseInstaller();

public:
    void setInfo(const DEFSECURITYTOOLINFO &info);
    DEFSECURITYTOOLINFO toolInfo() const;
    void setLatestPackageInfo(const PACKAGEMSG &packagemsg);
    void installPackage();
    void unInstallPackage();
    void updatePackage();
    void setStoreManagerInter(DBusInvokerInterface *pInterface);
    bool isPackageExist();
    bool isUpdatable();
    bool isPackageInstallable();

    //virtual
public:
    virtual void showtool(const QStringList &strParams);

Q_SIGNALS:
    void sAppStatusChanged(const QString &strKey, DEFSECURITYTOOLSTATUS status);

public Q_SLOTS:
    void onInstallStart(const QString &strID, const QString &strPackage);
    void onSigIntallProgress(const QString &strID, const QString &strPackage, int iState, int iTotal, int iProcess, const QString &strStatusMsg);
    void onSigRemoveProgress(const QString &strID, const QString &strPackage, bool bSuccess);

private:
    PACKAGEMSG getLocalPackageInfo(QString strMsg);

protected:
    DEFSECURITYTOOLINFO m_info;
    PACKAGEMSG m_LatestPackageMsg;

private:
    DBusInvokerInterface *m_pManagerInvoker;
    QString m_jobPath;
    QString m_strType;
    QString m_strStatus;
    bool m_bUpdate;
};

class DefSecurityToolsInstallerFactory : public QObject
{
    explicit DefSecurityToolsInstallerFactory(QObject *parent = nullptr);
    ~DefSecurityToolsInstallerFactory() override;

public:
    static DefSecurityToolsBaseInstaller *createInstaller(const DEFSECURITYTOOLINFO &info);
};

#endif // DEFSECURITYTOOLSBASEINSTALLER_H
