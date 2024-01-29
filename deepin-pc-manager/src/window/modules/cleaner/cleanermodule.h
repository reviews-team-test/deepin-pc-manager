/*
 * Copyright (C) 2019 ~ 2019 Deepin Technology Co., Ltd.
 *
 * Author:     luokai <luokai_cm@deepin.com>
 *
 * Maintainer: luokai <luokai_cm@deepin.com>
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

#include "window/interface/moduleinterface.h"
#include "window/interface/frameproxyinterface.h"
#include "window/modules/common/common.h"

DEF_NAMESPACE_BEGIN
DEF_ANTIVIRUS_NAMESPACE_BEGIN

class TrashCleanWidget;
class ModuleInterface;
class FrameProxyInterface;
class CleanerDBusAdaptorImpl;
class TrashCleanGreetingWidget;
class TrashCleanResultWidget;

class CleanerModule : public QObject
    , public ModuleInterface
{
    Q_OBJECT
public:
    explicit CleanerModule(FrameProxyInterface *frame, QObject *parent = nullptr);
    ~CleanerModule() override;

public:
    void initialize() override;
    void preInitialize() override;
    const QString name() const override;
    void active(int index) override;
    void deactive() override;

private:
    void showResultWidget();

public Q_SLOTS:

private:
    CleanerDBusAdaptorImpl *m_dbusAdaptorImpl;
    TrashCleanWidget *m_widget;
    TrashCleanGreetingWidget *m_greetingWidget;
    TrashCleanResultWidget *m_resutlWidget;
    FrameProxyInterface *m_framProxy;
};
DEF_ANTIVIRUS_NAMESPACE_END
DEF_NAMESPACE_END
