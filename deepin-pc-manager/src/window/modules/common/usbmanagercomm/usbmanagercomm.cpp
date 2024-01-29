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

#include "usbmanagercomm.h"

bool USBConnectionInfo::operator==(const USBConnectionInfo &info)
{
    return (this->serial == info.serial)
           && (this->vendorID == info.vendorID)
           && (this->productID == info.productID);
}

bool USBConnectionInfo::operator!=(const USBConnectionInfo &info)
{
    return !(*this == info);
}

QDBusArgument &operator<<(QDBusArgument &argument, const USBConnectionInfo &info)
{
    argument.beginStructure();
    argument << info.id << info.name << info.addedTime << info.permMode << info.serial
             << info.vendorID << info.productID << info.size << info.isVisible;
    argument.endStructure();
    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, USBConnectionInfo &info)
{
    argument.beginStructure();
    argument >> info.id >> info.name >> info.addedTime >> info.permMode >> info.serial
        >> info.vendorID >> info.productID >> info.size >> info.isVisible;
    argument.endStructure();
    return argument;
}

void registerUSBConnectionInfoMetaType()
{
    qRegisterMetaType<USBConnectionInfo>("USBConnectionInfo");
    qDBusRegisterMetaType<USBConnectionInfo>();
}

void registerUSBConnectionInfoListMetaType()
{
    qRegisterMetaType<USBConnectionInfoList>("USBConnectionInfoList");
    qRegisterMetaType<QList<USBConnectionInfo>>("QList<USBConnectionInfo>");
    qDBusRegisterMetaType<USBConnectionInfoList>();
    qDBusRegisterMetaType<QList<USBConnectionInfo>>();
}
