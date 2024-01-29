/*
 * Copyright (C) 2019 ~ 2022 UnionTech Software Technology Co., Ltd.
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

#include <QDBusArgument>
#include <QtCore>
#include <QtDBus>

#define USB_MANAGER_PERM_MODE_RW 0
#define USB_MANAGER_PERM_MODE_RO 1
#define USB_MANAGER_PERM_MODE_NO 2

#define USB_MANAGER_CONN_TIME_FORMATION "yyyy-MM-dd HH:mm:ss" // 时间格式化规则

// 执行异常类型
#define USB_MANAGER_ERR_TYPE_NO_ERROR 0
#define USB_MANAGER_ERR_TYPE_UDISKS_CONFIG_WRITE_FAILED -1
#define USB_MANAGER_ERR_TYPE_UDISKS_RESTART_FAILED -2

// 白名单 操作类型
#define USB_MANAGER_OP_TYPE_ADD 0 // 添加
#define USB_MANAGER_OP_TYPE_REMOVE 1 // 删除
#define USB_MANAGER_OP_TYPE_MODIFY 2 // 修改

// usb连接/管控信息
struct USBConnectionInfo {
    uint id;
    QString name;
    QString addedTime;
    int permMode; // 权限模式，0 - 读写，1 - 只读，禁止 - 2
    QString serial;
    QString vendorID;
    QString productID;
    qint64 size; // 分区大小
    bool isVisible; // 是否忽略
    USBConnectionInfo()
        : id(0)
        , permMode(USB_MANAGER_PERM_MODE_RW)
        , size(0)
        , isVisible(true)
    {
    }
    bool operator==(const USBConnectionInfo &info);
    bool operator!=(const USBConnectionInfo &info);
};
Q_DECLARE_METATYPE(USBConnectionInfo);
typedef QList<USBConnectionInfo> USBConnectionInfoList;
Q_DECLARE_METATYPE(USBConnectionInfoList);

QDBusArgument &operator<<(QDBusArgument &argument, const USBConnectionInfo &procInfo);
const QDBusArgument &operator>>(const QDBusArgument &argument, USBConnectionInfo &procInfo);

void registerUSBConnectionInfoMetaType();
void registerUSBConnectionInfoListMetaType();
