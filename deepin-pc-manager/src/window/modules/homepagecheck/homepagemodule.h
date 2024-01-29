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
#pragma once

#include "window/modules/common/common.h"
#include "window/interface/moduleinterface.h"
#include "window/interface/frameproxyinterface.h"
#include "window/modules/common/common.h"
#include "widgets/checkprocessingwidget.h"
#include "window/modules/homepagecheck/syscheckadaptormodel.h"
#include "widgets/syscheckresultwidget.h"

class FrameProxyInterface;
class ModuleInterface;

class QObject;
class HomePageModel;
class HomePage;
class HomePageCheckWidget;
class QObject;

class HomePageModule : public QObject
    , public ModuleInterface
{
    Q_OBJECT
public:
    explicit HomePageModule(FrameProxyInterface *frame, QObject *parent = nullptr);
    ~HomePageModule() override;

public:
    // 初始化
    void initialize() override;
    // 预初始化
    void preInitialize() override;
    // 模块名称
    const QString name() const override;
    // 激活
    void active(int index) override;
    // 反激活
    void deactive() override;
    // 获得首页数据处理对象
    inline HomePageModel *getModel() { return m_homePageModel; }

Q_SIGNALS:

public Q_SLOTS:
    // 打开体检首页
    void showHomepage();
    // 打开体检页
    void showCheckPage();
    // v23重构，增加进度页
    void showProgressPage();
    // v23重构，打开结果页
    void showResultPage();
    // v23重构，检查中止处理
    void onCheckCanceled();
    // v23重构，重新检查
    void onRequestCheckAgain();
    // back farward
    void requestStopExaming();
    // request quit result widget
    void onRequestQuitResultWidget();
    // sync check score
    void onBackForward();

private:
    // 首页数据处理对象
    HomePageModel *m_homePageModel;
    // model适配器
    SysCheckAdaptorModel *m_sysCheckAdaptorModel;
    // 首页
    HomePage *m_homePage;
    // 体检页
    HomePageCheckWidget *m_homePagecheckWidget = nullptr;
    // 进度页
    CheckProcessingWidget *m_progressWidget;
    // V23结果页
    SysCheckResultWidget *m_resultWidget;
    bool m_isDeactived;
};
