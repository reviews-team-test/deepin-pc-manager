/*
 * Copyright (C) 2017 ~ 2019 Deepin Technology Co., Ltd.
 *
 * Author:     wubowen <wubowen_cm@deepin.com>
 *
 * Maintainer: wubowen <wubowen_cm@deepin.com>
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

#include "securitytooldialog_adaptor.h"
#include "window/modules/securitytooldialog/startupdialog/startupwidget.h"
#include "window/modules/securitytools/defsecuritytoolinfo.h"
#include "securitytoolbackend/defsecuritytoolsbuslinemgr.h"
#include "../../window/modules/common/gsettingkey.h"

#include <DGuiApplicationHelper>

#include <QObject>

class QGSettings;
class SecurityToolDialogInter : public QObject
{
    Q_OBJECT
public:
    explicit SecurityToolDialogInter(QObject *parent = nullptr);
    virtual ~SecurityToolDialogInter() override;

Q_SIGNALS:
    //所有的安全工具状态更新信号
    void notifyToolsInfoUpdate(const DEFSECURITYTOOLINFOLIST &infos);
    //某一个安全工具的状态发生变化的信号
    void notifyAppStatusChanged(const QString &strPackageKey, int status);
    //安全工具状态检测完成信号，在安全工具状态更新过程中可能会耗时较长，此时不应让使用者操作会禁用界面，最后使用此信号通知可以让用户进行操作了。
    //此方法暂未使用，需要在实现依据具体情况判断是否需要使用。
    void notifyStatusCheckFinished();

public Q_SLOTS:
    // 显示自启动管理弹框
    void ShowStartup();
    // 响应更新工具信息请求
    void OnRequestUpdateToolsInfo();
    // 响应工具包安装请求
    void OnInstallPackage(const QString &strPackageKey);
    // 响应包安装请求
    void OnUnInstallPackage(const QString &strPackageKey);
    // 响应包更新请求
    void OnUpdatePackage(const QString &strPackageKey);
    // 响应显示工具请求
    void OnShowTool(const QString &strPackageKey, const QStringList &strParams);

    // 得到正在安装/更新/卸载的app
    QStringList GetInstallingApps() { return m_appInstalling; }
    QStringList GetUpdatingApps() { return m_appUpdating; }
    QStringList GetUninstallingApps() { return m_appUninstalling; }

    // 接收app状态改变槽
    void acceptAppStatusChanged(const QString &strPackageKey, DEFSECURITYTOOLSTATUS status);

    void getDefenderPaletteType();
    void SetDefenderPaletteType(int type);

private:
    void initConnections();

private:
    DGuiApplicationHelper *m_guiHelper; // 方便得到系统主题
    QGSettings *m_gsetting; // gsetting配置对象

    SecuritytooldialogAdaptor *m_adaptor;
    StartupMainWindow *m_autoStartupMwnd;
    DefSecurityToolsBusLineMgr *m_pToolBusLineMgr;

    QStringList m_appInstalling;
    QStringList m_appUpdating;
    QStringList m_appUninstalling;
};
