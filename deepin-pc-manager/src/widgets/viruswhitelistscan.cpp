/*
* Copyright (C) 2021 ~ 2021 Uniontech Technology Co., Ltd.
*
* Author:      herun <herun@uniontech.com>
*
* Maintainer:  herun <herun@uniontech.com>
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

#include "viruswhitelistscan.h"
#include "../window/modules/common/compixmap.h"

#include <DFontSizeManager>
#include <DPalette>

#include <QHBoxLayout>
#include <QLabel>

VirusWhitelistScanItem::VirusWhitelistScanItem(QWidget *parent)
    : QWidget(parent)
    , m_lbText(new QLabel(this))
    , m_lbTip(new QLabel(this))
    , m_dialogBtn(new DIconButton(this))
{
    this->setContentsMargins(0, 0, 0, 0);
    // 布局
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(layout);

    // 设置文本属性
    m_lbText->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    // 设置提示文本属性
    m_lbTip->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    DFontSizeManager::instance()->bind(m_lbTip, DFontSizeManager::T9); // 字体设置
    m_lbTip->setText(tr("(Files in the whitelist will be excluded from virus scan)"));
    m_lbTip->setAlignment(Qt::AlignBottom);

    // 设置弹窗按钮
    m_dialogBtn->setAccessibleName("forwardButton");
    m_dialogBtn->setIcon(QStyle::SP_ArrowForward);
    m_dialogBtn->setFixedSize(QSize(30, 30));
    m_dialogBtn->setFlat(true);

    // 加入文本和弹窗按钮
    layout->addWidget(m_lbText);
    layout->addSpacing(10);
    layout->addWidget(m_lbTip);
    layout->addStretch(0); // 加入弹簧
    layout->addWidget(m_dialogBtn);

    // 信号绑定
    connect(m_dialogBtn, &DIconButton::clicked, this, &VirusWhitelistScanItem::pushButtonTrigger);
}

VirusWhitelistScanItem::~VirusWhitelistScanItem()
{
}

// 设置label显示内容
void VirusWhitelistScanItem::setText(const QString &text)
{
    m_lbText->setText(text);
}

// 按钮触发
void VirusWhitelistScanItem::pushButtonTrigger(bool status)
{
    emit buttonTrigger(status);
}
