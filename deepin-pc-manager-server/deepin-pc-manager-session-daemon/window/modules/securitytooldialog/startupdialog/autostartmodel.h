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

#include <QObject>

class DBusInvokerInterface;
class SettingsInvokerInterface;

namespace def {
class SystemSettings;
}

using namespace def;

class AutoStartModel : public QObject
{
    Q_OBJECT
public:
    explicit AutoStartModel(QObject *parent = nullptr);
    ~AutoStartModel();

    // 更新所有应用自启动状态
    bool updateAppsAutoStartStatus() const;
    // 获取所有自启动应用的信息字符串
    QString getAllAutoStartAppsInfoStr() const;
    // 获取所有非自启动应用的信息字符串
    QString getAllNonautoStartAppsInfoStr() const;
    // 应用是否自启动
    bool isAppAutoStart(const QString &path) const;
    // 设置应用自启动
    bool setAppAutoStart(int status, const QString &path) const;
    // 添加日志
    void addSecurityLog(int type, const QString &log) const;

Q_SIGNALS:
    void itemStatusChanged(bool isAuto, const QString &id);

private:
    void init();
    // 初始化信号
    void initSignalSLot();

private:
    DBusInvokerInterface *m_dataInterfaceInvoker; // 安全中心数据服务接口
};
