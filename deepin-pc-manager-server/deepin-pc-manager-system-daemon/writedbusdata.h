/*
 * Copyright (C) 2019 ~ 2019 Deepin Technology Co., Ltd.
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

#include "daemon_adaptor.h"
#include "../../deepin-pc-manager/src/window/modules/common/gsettingkey.h"
#include "../../deepin-pc-manager/src/window/modules/common/common.h"
#include "disk/disk.h"

#include <QObject>
#include <QThread>
#include <QSqlDatabase>

class QDBusContext;
class NetManagerModel;
class SecurityLogSql;
class ScanWhiteListSql;
class VirusLibImport;
class FirewallSrvModel;
class SettingsSql;
class DBusInvokerInterface;

#define HEART_BEAT_TIME_OUT 3 // 心跳间隔,s
// 检测ssh登陆端口启动标志
#define REM_SSH_STATUS "running"
const QString service = "com.deepin.pc.manager.system.daemon";
const QString path = "/com/deepin/pc/manager/system/daemon";

class SecurityPkgNameSql;
class WriteDBusData : public QObject
    , protected QDBusContext
{
    Q_OBJECT
public:
    explicit WriteDBusData(QObject *parent = nullptr);
    ~WriteDBusData();

Q_SIGNALS:
    void SysSettingValueChanged(const QString &key, const QDBusVariant &value);

    // usb设备接入的信号，入参bflag 为false,表示限制状态
    void NotifyUsbConnectionInfo(bool bFlag, QString sUsbInfo);
    void SendUsbConnectionInfo(QString sUsbInfos);
    // 通知显示限制所有usb设备的系统通知
    void requestShowBlockAllSysNotify();
    // 通知显示限制非白名单usb设备的系统通知
    void requestShowOnlyWhiteListSysNotify();

    // 应用程序安装卸载刷新数据库信号
    void requestRefreshPackageTable();
    // 包名解析数据库插入完成信号
    void NotifySqlInsertFinish();

    // 同步界面状态到所有用户UI，需要同步的UI功能接收该信号并处理同步状态
    // true : enabled
    // false : disabled
    // moduleIndex 定义见common.h中 "系统工具各模块索引"
    // 比如 TRUSTED_PROTECTION_INDEX
    void RequestUIStatusSynchronization(int moduleIndex, bool status);

public Q_SLOTS:
    void StartApp();
    void ExitApp();
    // 系统设置
    bool SetSysSettingValue(const QString &key, const QDBusVariant &value);
    QDBusVariant GetSysSettingValue(const QString &key);

    // 获取磁盘设备路径列表
    QStringList GetDiskDevicePathList();

    // 清理选中的垃圾文件
    void CleanSelectFile(QStringList filePaths);

    // 清理journal目录下的日志文件
    void CleanJournal();

    // 添加安全日志
    void AddSecurityLog(int nType, QString sInfo);

    // 递归函数-获取/usr/share/deepin-pc-manager/config/目录下所有的lock文件
    void scanFile(const QString &path);

    // 初始化localcache.db数据库
    void initLocalCache();
    // 查询相关联文件对应的包名信息
    QString QueryPackageName(const QString sBinaryFile);
    // 应用程序安装卸载刷新数据库
    void RefreshPackageTable();
    // 接受数据库插入完成信号
    void acceptSqlInsertFinish();

    // 插入卸载记录
    void InsertUninstalledAppRecord(const QString &, const QString &);
    // 删除卸载记录
    void DeleteUninstalledAppRecord(const QString &);
    //获取卸载应用程序名称
    QVariantList GetUnInstalledApps();

private:
    // 校验调用者
    bool isValidInvoker();
    bool openLocalDb();

private:
    DaemonAdaptor *m_adaptor;
    SettingsSql *m_settingsSql; // 系统设置查询

    QString m_device;

    QSqlDatabase m_localCacheDb;
    SecurityPkgNameSql *m_securityPkgNameSql;
    QThread *m_securityPkgNameSqlThread;
    QMap<QString, QString> m_sPkgNameMap;

    bool m_isInitSqlDatabase;
};
