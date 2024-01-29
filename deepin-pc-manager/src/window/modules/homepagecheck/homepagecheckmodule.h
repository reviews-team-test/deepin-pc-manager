/*
 * Copyright (C) 2010 ~ 2010 Deepin Technology Co., Ltd.
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
#ifndef HOMEPAGECHECKMODULE_H
#define HOMEPAGECHECKMODULE_H

#include "window/interface/moduleinterface.h"
#include "window/interface/frameproxyinterface.h"
#include "src/window/modules/common/common.h"
#include "window/modules/homepagecheck/homepagecheckwidget.h"


#include <DGuiApplicationHelper>

class FrameProxyInterface;
class ModuleInterface;

class HomePageCheckModule : public QObject, public ModuleInterface
{
    Q_OBJECT
public:
    explicit HomePageCheckModule(FrameProxyInterface *frame, QObject *parent = nullptr);
    ~HomePageCheckModule() override {}

public:
    void initialize() override;
    void preInitialize() override;
    const QString name() const override;
    void active(int index) override;
    void deactive() override;

Q_SIGNALS:

public Q_SLOTS:

private:
    HomePageCheckWidget  *m_homePagecheckWidget = nullptr;
};

#endif // HOMEPAGECHECKMODULE_H
