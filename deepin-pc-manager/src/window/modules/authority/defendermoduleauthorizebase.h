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
#ifndef DEFENDERMODULEAUTHORIZEBASE_H
#define DEFENDERMODULEAUTHORIZEBASE_H

#include "common/invokers/invokerfactory.h"

#include <QObject>

class DefenderModuleAuthorizeBase : public QObject
{
    Q_OBJECT

public:
    explicit DefenderModuleAuthorizeBase(const QString &moduleName, QObject *parent = nullptr);
    virtual ~DefenderModuleAuthorizeBase();

    void init();
    void initServiceConnection();

    // signals
    // 模块启动时向上注册
    // 调用授权接口方法，将模块
    void onModulesActived();
    // 请求授权
    void requestAuthWithID(int id);
    // 注册模块名称
    const QString &getModuleName();

public Q_SLOTS:
    // slots
    // 收到提权结果
    // 对应ID处理自己的流程,为了调试方便，调用者自行固定操作ID
    void onAuthResultRecived(const QString &moduleName, int id, bool result);

Q_SIGNALS:
    // 界面状态通知，实现该方法以处理界面变化
    // 调用者处理以下信号
    void onAuthorizeStarted();
    void onAuthorizeFinished();
    // 授权结果通知
    void onAuthorized(int id, bool result);

private:
    DBusInvokerInterface *m_authService;
    QString m_moduleName;
};

#endif // DEFENDERMODULEAUTHORIZEBASE_H
