/*
 * Copyright (C) 2019 ~ 2020 Deepin Technology Co., Ltd.
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

#include "../window/modules/common/comdata.h"

#include <DDialog>

#include <QObject>

DWIDGET_USE_NAMESPACE
///
/// \brief 安全中心弹窗管理类
///
class DialogManage : public QObject
{
    Q_OBJECT
public:
    explicit DialogManage(QObject *parent = nullptr);

public:
    // 扫描时更新提示框
    static void showUpdateWhenScanningDialog();

    // 常规的提示框   左上角图标和文本信息  底下的按钮都是确定
    /**
     * @brief showNormalTipDialog
     * @param icontype   图标类型
     * @param textInfo   提示信息
     */
    void showNormalTipDialog(TipIcon icontype, TipTextInfo textInfo);

    // 更新服务地址提示窗
    DDialog *creatChangeAddressTipDialog();

signals:
    // 关闭信号
    void closed();
    // 按钮点击
    void buttonClicked();
};
