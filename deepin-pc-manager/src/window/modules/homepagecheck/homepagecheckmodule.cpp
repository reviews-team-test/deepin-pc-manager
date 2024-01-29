/*
 * Copyright (C) 2019 ~ 2019 Deepin Technology Co., Ltd.
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
#include "homepagecheckmodule.h"
#include "window/modules/common/common.h"
#include "window/interface/moduleinterface.h"
#include "window/interface/frameproxyinterface.h"
#include <pwd.h>
#include <unistd.h>

#include <QTimer>
#include <QModelIndex>
#include <QStandardItemModel>

HomePageCheckModule::HomePageCheckModule(FrameProxyInterface *frame, QObject *parent)
    : QObject(parent)
    , ModuleInterface(frame)
{

}


void HomePageCheckModule::initialize()
{

}

void HomePageCheckModule::preInitialize()
{
}

const QString HomePageCheckModule::name() const
{
    return "homepage";
}

void HomePageCheckModule::active(int index)
{
    Q_UNUSED(index);
    // 首页是不可删除窗口, 所以始终保留
    if (nullptr == m_homePagecheckWidget) {
        m_homePagecheckWidget = new HomePageCheckWidget();
    }

    m_homePagecheckWidget->show();
    m_frameProxy->pushWidget(this, m_homePagecheckWidget);

}

void HomePageCheckModule::deactive()
{

}


