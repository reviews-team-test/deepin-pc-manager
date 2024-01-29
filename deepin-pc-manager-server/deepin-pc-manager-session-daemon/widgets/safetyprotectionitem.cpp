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
#include "safetyprotectionitem.h"

#include <DFontSizeManager>
#include <DBackgroundGroup>
#include <DApplicationHelper>

#include <QPainter>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>

SafetyProtectionItem::SafetyProtectionItem(QWidget *parent)
    : DFrame(parent)
    , m_lbText(new DLabel(this))
    , m_lbTextNull(new DLabel(this))
    , m_switchButton(new DSwitchButton(this))
    , m_bTestClick(false)
{
    // DFrame
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(mainLayout);

    // QWidget and layout
    m_firstLayerWidgt = new QWidget(this);
    mainLayout->addWidget(m_firstLayerWidgt);
    QHBoxLayout *firstLayerLayout = new QHBoxLayout;
    firstLayerLayout->setContentsMargins(10, 0, 10, 0);

    // 设置文本属性
    m_lbText->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    DFontSizeManager::instance()->bind(m_lbText, DFontSizeManager::T8);
    m_lbTextNull->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    // 加入文本和开关
    firstLayerLayout->addWidget(m_lbText);
    firstLayerLayout->addWidget(m_lbTextNull);
    firstLayerLayout->addWidget(m_switchButton);

    connect(m_switchButton, &DSwitchButton::pressed, this, &SafetyProtectionItem::switchPressed);
    connect(m_switchButton, &DSwitchButton::toggled, this, &SafetyProtectionItem::switchChanged);

    m_firstLayerWidgt->setLayout(firstLayerLayout);

    setBackgroundRole(DPalette::ItemBackground);
    // 设置边框的宽度
    setLineWidth(0);
    setFixedHeight(36);

    this->setMouseTracking(true);
    m_firstLayerWidgt->setMouseTracking(true);
    m_lbText->setMouseTracking(true);
}

SafetyProtectionItem::~SafetyProtectionItem()
{
}

// 设置相关标签名称
void SafetyProtectionItem::setAccessibleParentText(QString sAccessibleName)
{
    m_firstLayerWidgt->setAccessibleName(sAccessibleName + "_backGroundWidget");
    m_switchButton->setAccessibleName(sAccessibleName + "_backGroundWidget_switchButton");
    m_lbText->setAccessibleName(sAccessibleName + "_backGroundWidget_textLable");
    m_lbTextNull->setAccessibleName(sAccessibleName + "_backGroundWidget_textNullLable");
}

DSwitchButton *SafetyProtectionItem::getSwitchBtn()
{
    return m_switchButton;
}

// 子类重写
void SafetyProtectionItem::resetUI()
{
    // 子类重写该方法以调整UI形式
    // 不要在这里加入代码
}

// 设置标题
void SafetyProtectionItem::setText(QString text)
{
    m_lbText->setText(text);
}

// 设置标题可以点击
void SafetyProtectionItem::setTextClick()
{
    m_bTestClick = true;

    // 字体样式
    QPalette pal;
    pal.setColor(QPalette::Text, QColor("#0082FA"));
    m_lbText->setPalette(pal);
}

// button status
void SafetyProtectionItem::setSwitchStatus(bool isbStatus)
{
    m_switchButton->setChecked(isbStatus);
}

void SafetyProtectionItem::enableSwitch(bool enable)
{
    m_switchButton->setEnabled(enable);
}

void SafetyProtectionItem::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if (m_lbText->geometry().contains(this->mapFromGlobal(QCursor::pos())) && m_bTestClick) {
        setCursor(Qt::PointingHandCursor);
    } else {
        setCursor(Qt::ArrowCursor);
    }
}

void SafetyProtectionItem::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if (m_lbText->geometry().contains(this->mapFromGlobal(QCursor::pos())) && m_bTestClick) {
        Q_EMIT sendTextClickedChange();
    }
}
