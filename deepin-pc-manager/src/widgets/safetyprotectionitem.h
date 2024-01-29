/*
 * Copyright (C) 2019 ~ 2019 Deepin Technology Co., Ltd.
 *
 * Author:     caitao <caitao@deepin.com>
 *
 * Maintainer: caitao <caitao@deepin.com>
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

#include "window/namespace.h"
#include "dtkwidget_global.h"
#include "widgets/switchwidget.h"

#include <DFrame>
#include <DCheckBox>
#include <DTipLabel>

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QMouseEvent>

DWIDGET_USE_NAMESPACE
class SafetyProtectionItem : public DFrame
{
    Q_OBJECT
public:
    explicit SafetyProtectionItem(QWidget *parent = nullptr);
    virtual ~SafetyProtectionItem();

    // 设置标题
    void setText(QString text);

    // 设置标题可以点击
    void setTextClick();

    // 设置开关状态
    virtual void setSwitchStatus(bool isbStatus);
    void enableSwitch(bool enable);

    // 设置相关标签名称
    void setAccessibleParentText(QString sAccessibleName);

    DSwitchButton *getSwitchBtn();
    // 复用
    // 不修改本类的情况下，改变layout与字体
    // 子类自行实现
    virtual void resetUI();

Q_SIGNALS:
    // 标题点击信号
    void sendTextClickedChange();

    // 点击
    void switchPressed();

    // 按钮状态转换
    void switchChanged(bool gStatus);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    QWidget *m_firstLayerWidgt;
    DLabel *m_lbText;
    DLabel *m_lbTextNull;
    DSwitchButton *m_switchButton;
    bool m_bTestClick;
};
