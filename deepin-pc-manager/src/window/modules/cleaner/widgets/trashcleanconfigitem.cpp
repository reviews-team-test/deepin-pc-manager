/*
 * Copyright (C) 2019 ~ 2022 UnionTech Software Technology Co., Ltd.
 *
 * Author:     xuxin <xuxina@uniontech.com>
 *
 * Maintainer: xuxin <xuxina@uniontech.com>
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
#include "trashcleanconfigitem.h"

#include <DLabel>
#include <DTipLabel>
#include <DBackgroundGroup>
#include <DFrame>
#include <QIcon>
#include <DFontSizeManager>

#include <QGridLayout>
#include <QHBoxLayout>
#include <QCheckBox>

DWIDGET_USE_NAMESPACE

TrashCleanConfigItem::TrashCleanConfigItem(QWidget *parent)
    : DFrame(parent)
    , m_checkbox(nullptr)
    , m_icon(nullptr)
    , m_title(nullptr)
    , m_tips(nullptr)
    , m_textFrame(nullptr)
{
    this->setFixedSize(516, 34);
    this->setFrameShape(QFrame::NoFrame);
    this->setFocusPolicy(Qt::NoFocus);
    this->setLineWidth(0);
    this->setContentsMargins(0, 0, 0, 0);

    initUI();
    initConnection();
}

void TrashCleanConfigItem::setTitles(const QString &mainTitle, const QString &tipTitle)
{
    m_title->setText(mainTitle);
    m_tips->setText(tipTitle);
}

void TrashCleanConfigItem::setCheckBoxStatus(bool isChecked)
{
    m_checkbox->setChecked(isChecked);
}

void TrashCleanConfigItem::setIconPath(const QString &path)
{
    m_icon->setPixmap(QIcon::fromTheme(path).pixmap(16, 16));
}

void TrashCleanConfigItem::initUI()
{
    m_icon = new DLabel(this);
    m_icon->setAccessibleName("configItemIcon");

    m_title = new DLabel("title", this);
    m_title->setAccessibleName("configItemTitle");
    QFont titleFont = m_title->font();
    titleFont.setPixelSize(14);
    titleFont.setWeight(QFont::Medium);
    m_title->setFont(titleFont);

    m_tips = new DTipLabel("tip", this);
    m_tips->setAccessibleName("configItemTip");
    DFontSizeManager::instance()->unbind(m_tips);
    QFont tipFont = m_tips->font();
    tipFont.setPixelSize(11);
    m_tips->setFont(tipFont);

    m_checkbox = new QCheckBox(this);
    m_checkbox->setAccessibleName("configItemCheckbox");
    m_checkbox->setFixedSize(20, 20);
    m_checkbox->setTristate(false);
    m_checkbox->setFocusPolicy(Qt::NoFocus);

    m_textFrame = new DFrame(this);
    m_textFrame->setFixedSize(450, 34);
    m_textFrame->setBackgroundRole(DPalette::ItemBackground);
    m_textFrame->setLineWidth(0);
    m_textFrame->setContentsMargins(0, 0, 0, 0);
    QGridLayout *textLayout = new QGridLayout;
    textLayout->setContentsMargins(14, 0, 0, 0);
    textLayout->setAlignment(Qt::AlignLeft | Qt::AlignHCenter);
    textLayout->setColumnMinimumWidth(0, 70);
    textLayout->setColumnMinimumWidth(1, 20);
    textLayout->addWidget(m_title, 0, 0, Qt::AlignLeft);
    textLayout->addWidget(m_tips, 0, 2, Qt::AlignLeft);
    m_textFrame->setLayout(textLayout);

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(m_checkbox, 0, 0, Qt::AlignLeft);
    mainLayout->addWidget(m_icon, 0, 1, Qt::AlignLeft);
    mainLayout->addWidget(m_textFrame, 0, 2, Qt::AlignLeft);

    this->setLayout(mainLayout);
}

void TrashCleanConfigItem::initConnection()
{
    connect(m_checkbox, &QCheckBox::stateChanged, this, [&](int stage) {
        qDebug() << "stagechanged";
        Q_EMIT this->stageChanged(m_configIndex, stage);
    });
}
