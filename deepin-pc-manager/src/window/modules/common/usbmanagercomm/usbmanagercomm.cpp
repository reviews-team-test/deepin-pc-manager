// Copyright (C) 2019 ~ 2022 UnionTech Software Technology Co., Ltd.
// SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

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
