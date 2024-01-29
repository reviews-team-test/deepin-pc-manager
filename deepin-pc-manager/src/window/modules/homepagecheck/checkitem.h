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

#include <DFrame>
#include <DLabel>
#include <DCommandLinkButton>
#include <DSpinner>

class QHBoxLayout;

DWIDGET_USE_NAMESPACE

class CheckItem : public DFrame
{
    Q_OBJECT
public:
    CheckItem(DLabel *titlePic, DLabel *title, DLabel *tipPic, DLabel *tip, DCommandLinkButton *btn = nullptr,
              DCommandLinkButton *ignoreBtn = nullptr, DCommandLinkButton *notIgnoreBtn = nullptr,
              DSpinner *spinner = nullptr, QWidget *parent = nullptr);

private:
    // 标题图标
    DLabel *m_lbTitlePic;
    // 标题文字
    DLabel *m_lbTitle;
    // 提示图标
    DLabel *m_lbTipPic;
    // 提示文字
    DLabel *m_lbTip;
    // 操作按钮
    DCommandLinkButton *m_btn;
    // 忽略按钮
    DCommandLinkButton *m_ignoreBtn;
    // 取消忽略按钮
    DCommandLinkButton *m_notIgnoreBtn;
    // 旋转等待按钮
    DSpinner *m_spinner;
};
