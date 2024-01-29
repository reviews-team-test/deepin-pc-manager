/*
 * Copyright (C) 2019 ~ 2021 UnionTech Software Technology Co., Ltd.
 *
 * Author:     caitao <caitao@uniontech.com>
 *
 * Maintainer: caitao <caitao@uniontech.com>
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
#pragma once

#include "defsecuritytoolinfo.h"

#include <QObject>

class DBusInvokerInterface;
class SettingsInvokerInterface;

class SecurityToolsModel : public QObject
{
    Q_OBJECT
public:
    explicit SecurityToolsModel(QObject *parent = nullptr);
    ~SecurityToolsModel();

    void updateToolsInfo();

    //获取工具信息
    QList<DEFSECURITYTOOLINFO> getToolsInfo(TOOLSSTATUS status);
    void openTool(const QString &strPackageKey, const QStringList &strParams = QStringList());
    void updateTool(const QString &strPackageKey);
    void installTool(const QString &strPackageKey);
    void unInstallTool(const QString &strPackageKey);

    // 得到正在安装/更新/卸载的app
    QStringList getInstallingApps();
    QStringList getUpdatingApps();
    QStringList getUninstallingApps();

private:
    // 初始化数据
    void initData();
    void initConnectoin();

public Q_SLOTS:
    void onToolsInfoUpdate(const DEFSECURITYTOOLINFOLIST &infos);
    void onAppStatusChanged(const QString &strPackageKey, int status);
    void onStatusCheckFinished();

Q_SIGNALS:
    void sUpdateToolsInfo();
    void notityAppStatusChanged(const QString &strPackageKey, int status);

private:
    DBusInvokerInterface *m_pSecurityToolDBusInter; //安全工具
    SettingsInvokerInterface *m_gsetting; // 安全中心gsetting配置
    QList<DEFSECURITYTOOLINFO> m_toolinfos;
};
