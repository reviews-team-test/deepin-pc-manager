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
#include "cleaneritem.h"

#include <DBackgroundGroup>
#include <DApplicationHelper>
#include <DFontSizeManager>

#include <QPainter>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGraphicsOpacityEffect>
#include <QDebug>

DWIDGET_USE_NAMESPACE

#define MAX_WIDTH 300

CleanerItem::CleanerItem(QWidget *parent)
    : DFrame(parent)
    , m_firstLayerWidgt(new QWidget(this))
    , m_checkBox(new DCheckBox(this))
    , m_levelLabel(new DLabel(this))
    , m_tipLabel(new DTipLabel("", this))
{
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(mainLayout);

    mainLayout->addWidget(m_firstLayerWidgt);

    QHBoxLayout *firstLayerLayout = new QHBoxLayout;
    firstLayerLayout->setContentsMargins(5, 0, 10, 0);
    firstLayerLayout->setSpacing(10);
    m_firstLayerWidgt->setLayout(firstLayerLayout);

    m_checkBox->setFixedSize(QSize(25, 25));
    firstLayerLayout->addWidget(m_checkBox);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->setContentsMargins(5, 5, 5, 0);
    rightLayout->setSpacing(5);
    firstLayerLayout->addLayout(rightLayout, Qt::AlignLeft);

    m_levelLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_tipLabel->adjustSize();
    m_levelLabel->setContentsMargins(0, 0, 0, 0);
    QFont font = m_levelLabel->font();
    font.setWeight(QFont::Medium);
    // 字体样式
    DFontSizeManager::instance()->bind(m_levelLabel, DFontSizeManager::T6);
    QPalette pal;
    pal.setColor(QPalette::Text, QColor("#414D68"));
    m_levelLabel->setPalette(pal);
    rightLayout->addWidget(m_levelLabel, 0, Qt::AlignLeft);

    m_tipLabel->setAlignment(Qt::AlignLeft);
    m_tipLabel->adjustSize();
    m_tipLabel->setContentsMargins(0, 0, 0, 0);
    rightLayout->addWidget(m_tipLabel);
    // 字体样式
    DFontSizeManager::instance()->bind(m_tipLabel, DFontSizeManager::T8);
    QPalette pal1;
    pal1.setColor(QPalette::Text, QColor("#526A7F"));
    m_levelLabel->setPalette(pal1);
    setBackgroundRole(DPalette::ItemBackground);
    // 设置边框的宽度
    setLineWidth(0);

    connect(m_checkBox, &QCheckBox::clicked, this, &CleanerItem::setCheckBoxStatus);
}

CleanerItem::~CleanerItem()
{
}

// 设置相关标签名称
void CleanerItem::setAccessibleParentText(const QString &sAccessibleName)
{
    m_firstLayerWidgt->setAccessibleName(sAccessibleName + "_backGroundWidget");
    m_checkBox->setAccessibleName(sAccessibleName + "_backGroundWidget_checkBox");
    m_levelLabel->setAccessibleName(sAccessibleName + "_backGroundWidget_levelLable");
    m_tipLabel->setAccessibleName(sAccessibleName + "_backGroundWidget_tipLable");
}

// 设置标题和提示
void CleanerItem::setLevelText(QString text)
{
    m_levelLabel->setText(text);
}

void CleanerItem::setTipText(QString text)
{
    m_tipLabel->setText(text);
    m_tipStr = text;
}

// 设置/获取 勾选框状态
void CleanerItem::setCheckBoxStatus(bool isbStatus)
{
    m_checkBox->setChecked(isbStatus);
    Q_EMIT itemClicked();
}

bool CleanerItem::getCheckBoxStatus() const
{
    return m_checkBox->isChecked();
}

void CleanerItem::paintEvent(QPaintEvent *event)
{
    QFontMetrics fontmet(m_tipLabel->font());
    QString elidedStr = fontmet.elidedText(m_tipStr, Qt::TextElideMode::ElideRight, MAX_WIDTH - 30);
    m_tipLabel->setText(elidedStr);
    DFrame::paintEvent(event);
}
