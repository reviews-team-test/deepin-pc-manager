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

#include "defsecuritytoolsdbusinstaller.h"

#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusInterface>

DefSecurityToolsDbusInstaller::DefSecurityToolsDbusInstaller(QObject *parent)
    : DefSecurityToolsBaseInstaller(parent)
{
}

DefSecurityToolsDbusInstaller::~DefSecurityToolsDbusInstaller()
{
}

void DefSecurityToolsDbusInstaller::showtool(const QStringList &strParams)
{
    if (m_info.strReserve4.trimmed() == "system") {
        QDBusInterface interface(m_info.strReserve, m_info.strReserve2, m_info.strReserve3, QDBusConnection::systemBus());

        if (!strParams.isEmpty()) {
            QList<QVariant> varlist;

            foreach (QString strParam, strParams) {
                varlist.push_back(strParam);
            }

            interface.callWithArgumentList(QDBus::NoBlock, m_info.strCallMethodName, varlist);
        } else {
            interface.call(m_info.strCallMethodName);
        }
    } else {
        QDBusInterface interface(m_info.strReserve, m_info.strReserve2, m_info.strReserve3, QDBusConnection::sessionBus());

        if (!strParams.isEmpty()) {
            QList<QVariant> varlist;

            foreach (QString strParam, strParams) {
                varlist.push_back(strParam);
            }

            interface.callWithArgumentList(QDBus::NoBlock, m_info.strCallMethodName, varlist);
        } else {
            interface.call(m_info.strCallMethodName);
        }
    }
}
