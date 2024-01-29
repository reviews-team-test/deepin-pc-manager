/*
 * Copyright (C) 2020 ~ 2020 Deepin Technology Co., Ltd.
 *
 * Author:     caimengci <caimengci@uniontech.com>
 *
 * Maintainer: caimengci <caimengci@uniontech.com>
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
#include "securitytoolsmodule.h"
#include "securitytoolswidget.h"
#include "securitytoolsmodel.h"

#include <QModelIndex>
#include <QStandardItemModel>

#define TOOL_PKG_KEY_DATA_USAGE "deepin-defender_Data Usage"
#define TOOL_PKG_KEY_STARTUP "deepin-defender_Startup Programs"
#define TOOL_PKG_KEY_NET_CONTRL "deepin-defender_Internet Control"
#define TOOL_PKG_KEY_USB_CONN "deepin-defender_USB Connection"
#define TOOL_PKG_KEY_LOGIN_SAFETY "deepin-defender_Login Safety"
#define TOOL_PKG_KEY_TRUSTED_PROTECTION "deepin-defender_Execution Prevention"

SecurityToolsModule::SecurityToolsModule(FrameProxyInterface *frame, QObject *parent)
    : QObject(parent)
    , ModuleInterface(frame)
    , m_securityToolsWidget(nullptr)
    , m_securityToolsModel(nullptr)
{
}

SecurityToolsModule::~SecurityToolsModule()
{
    deactive();
}

void SecurityToolsModule::initialize()
{
}

void SecurityToolsModule::preInitialize()
{
}

const QString SecurityToolsModule::name() const
{
    return MODULE_SECURITY_TOOLS_NAME;
}

void SecurityToolsModule::active(int index)
{
    Q_UNUSED(index)
    if (!m_securityToolsModel) {
        m_securityToolsModel = new SecurityToolsModel(this);
    }

    m_securityToolsWidget = new SecurityToolsWidget(m_securityToolsModel);
    m_securityToolsWidget->show();
    m_frameProxy->pushWidget(this, m_securityToolsWidget);

    switch (index) {
    case STARTUP_CONTROL_INDEX: {
        m_securityToolsModel->openTool(TOOL_PKG_KEY_STARTUP);
        break;
    }
    case USB_CONN_INDEX: {
        m_securityToolsModel->openTool(TOOL_PKG_KEY_USB_CONN);
        break;
    }
    case LOGIN_SAFETY_INDEX:
        m_securityToolsModel->openTool(TOOL_PKG_KEY_LOGIN_SAFETY);
        break;
    case TRUSTED_PROTECTION_INDEX:
        m_securityToolsModel->openTool(TOOL_PKG_KEY_TRUSTED_PROTECTION);
        break;
    default:
        break;
    }
}

void SecurityToolsModule::deactive()
{
    if (nullptr != m_securityToolsWidget) {
        m_securityToolsWidget->deleteLater();
        m_securityToolsWidget = nullptr;
    }
}
