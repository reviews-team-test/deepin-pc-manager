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
#pragma once

#include "window/interface/moduleinterface.h"
#include "window/modules/common/common.h"

class SecurityToolsWidget;
class SecurityToolsModel;

// 可信保护模块
class TrustedProtectionWidget;

class SecurityToolsModule : public QObject
    , public ModuleInterface
{
    Q_OBJECT
public:
    explicit SecurityToolsModule(FrameProxyInterface *frame, QObject *parent = nullptr);
    ~SecurityToolsModule() override;

public:
    void initialize() override;
    void preInitialize() override;
    const QString name() const override;
    void active(int index) override;
    void deactive() override;

private:
    SecurityToolsWidget *m_securityToolsWidget;
    SecurityToolsModel *m_securityToolsModel;
};
