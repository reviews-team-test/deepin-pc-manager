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
#include "checkitem.h"
#include "src/window/modules/common/common.h"

#include <DLabel>
#include <DCommandLinkButton>
#include <DSpinner>
#include <DFontSizeManager>

#include <QHBoxLayout>

CheckItem::CheckItem(DLabel *titlePic, DLabel *title, DLabel *tipPic, DLabel *tip, DCommandLinkButton *btn,
                     DCommandLinkButton *ignoreBtn, DCommandLinkButton *notIgnoreBtn,
                     DSpinner *spinner, QWidget *parent)
    : DFrame(parent)
    , m_lbTitlePic(titlePic)
    , m_lbTitle(title)
    , m_lbTipPic(tipPic)
    , m_lbTip(tip)
    , m_btn(btn)
    , m_ignoreBtn(ignoreBtn)
    , m_notIgnoreBtn(notIgnoreBtn)
    , m_spinner(spinner)
{
    // 设置背景色
    setBackgroundRole(DPalette::ItemBackground);
    setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
    // 设置外框线宽
    setLineWidth(0);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    // 设置边界间隔
    mainLayout->setContentsMargins(20, 0, 20, 0);
    setLayout(mainLayout);

    // 添加标题图标
    mainLayout->addWidget(m_lbTitlePic);

    // 添加标题
    m_lbTitle->setFont(Utils::getFixFontSize(14));
    m_lbTitle->setFixedWidth(200);
    m_lbTitle->setWordWrap(true);
    mainLayout->addWidget(m_lbTitle);

    // 添加提示图标
    mainLayout->addWidget(m_lbTipPic);
    // 添加提示文字

    // 设置字体
    QFont ft = m_lbTip->font();
    ft.setPixelSize(12);
    ft.setWeight(QFont::Weight::Medium);
    m_lbTip->setFont(ft);
    m_lbTip->setWordWrap(true);
    mainLayout->addWidget(m_lbTip, 1);

    // 如果存在操作按钮，则添加
    if (m_btn) {
        mainLayout->addWidget(m_btn);
    }

    // 如果存在忽略按钮，则添加
    if (m_ignoreBtn) {
        mainLayout->addWidget(m_ignoreBtn);
    }

    // 如果存在取消忽略按钮，则添加
    if (m_notIgnoreBtn) {
        mainLayout->addWidget(m_notIgnoreBtn);
    }

    // 如果存在旋转按钮，则添加
    if (m_spinner) {
        mainLayout->addWidget(m_spinner);
    }
}
