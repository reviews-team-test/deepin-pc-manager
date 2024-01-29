/*
 * Copyright (C) 2022 ~ 2022 UnionTech Software Technology Co., Ltd.
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
#include "avcpulimitation.h"

#include <QHBoxLayout>
#include <QCheckBox>

AVCPULimitation::AVCPULimitation(QWidget *parent)
    : QWidget(parent)
    , m_context(new DTK_WIDGET_NAMESPACE::DLabel(this))
    , m_tips(new DTK_WIDGET_NAMESPACE::DLabel(this))
    , m_check(new QCheckBox(this))
{
    this->setContentsMargins(0, 0, 0, 0);
    this->setAccessibleName("AVCPULimitation");
    // 布局
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(5);
    m_context->setText(tr("Energy-saving mode"));
    m_tips->setText("(" + tr("Virus scan takes a longer time in this mode") + ")");
    m_context->setElideMode(Qt::ElideMiddle);
    m_tips->setElideMode(Qt::ElideMiddle);

    layout->addWidget(m_check);
    layout->addWidget(m_context);
    layout->addWidget(m_tips);
    layout->addStretch(0);
    this->setLayout(layout);

    m_check->setTristate(false);
    m_check->setAccessibleName("mode_switch");

    connect(m_check, &QCheckBox::clicked, this, &AVCPULimitation::checkBoxChange);
}

AVCPULimitation::~AVCPULimitation()
{
}

void AVCPULimitation::setcheckbox(bool status)
{
    if (m_check->isChecked() == status) {
        return;
    }
    if (status) {
        m_check->setCheckState(Qt::Checked);
    } else {
        m_check->setCheckState(Qt::Unchecked);
    }
}

// 选择框的改变
void AVCPULimitation::checkBoxChange(bool ischecked)
{
    Q_EMIT notifyCheckBoxChange(ischecked);
}
