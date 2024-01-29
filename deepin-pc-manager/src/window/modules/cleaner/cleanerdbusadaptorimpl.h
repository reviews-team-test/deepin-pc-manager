/*
 * Copyright (C) 2021 ~ 2021 Deepin Technology Co., Ltd.
 *
 * Author:      xuxin <xuxina@uniontech.com>
 *
 * Maintainer:  xuxin <xuxina@uniontech.com>
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

#ifndef CLEANERDBUSADAPTORIMPL_H
#define CLEANERDBUSADAPTORIMPL_H

#include "cleanerdbusadaptorinterface.h"

#include <QObject>

class DBusInvokerInterface;
class SettingsInvokerInterface;

class CleanerDBusAdaptorImpl : public QObject
    , public CleanerDBusAdaptorInterface
{
    Q_OBJECT
public:
    explicit CleanerDBusAdaptorImpl(QObject *parent = nullptr);
    virtual ~CleanerDBusAdaptorImpl() { }

    // 后台服务：deepin-pc-manager-session-daemon
    virtual QStringList GetTrashInfoList();
    virtual QStringList GetCacheInfoList();
    virtual QStringList GetLogInfoList();
    virtual QStringList GetHistoryInfoList();
    virtual QString GetAppTrashInfoList();
    virtual QString GetBrowserCookiesInfoList();
    virtual void DeleteSpecifiedFiles(QStringList);
    // 安全日志内容写入
    virtual void AddSecurityLog(int nType, const QString &sInfo);
    // Gsetting读写，单元测试不用使用gsetting，所以加到这里做mock
    virtual QString GetValueFromeGSettings(const QString &key);
    virtual void SetValueToGSettings(const QString &key, const QString &value);
    virtual void DeleteSpecifiedAppUninstallInfo(const QString &pkgName);

private:
    // 后台服务接口
    DBusInvokerInterface *m_dataInterFaceServer;
    DBusInvokerInterface *m_monitorInterFaceServer;
    SettingsInvokerInterface *m_gsettings;

private:
    // 禁用拷贝构造与赋值
    CleanerDBusAdaptorImpl(const CleanerDBusAdaptorImpl &);
    CleanerDBusAdaptorImpl &operator=(const CleanerDBusAdaptorImpl &);
};

#endif // CLEANERDBUSADAPTORIMPL_H
