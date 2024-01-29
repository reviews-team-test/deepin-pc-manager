/*
 * Copyright (C) 2011 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     sbw <sbw@sbw.so>
 *             kirigaya <kirigaya@mkacg.com>
 *             Hualet <mr.asianwang@gmail.com>
 *
 * Maintainer: sbw <sbw@sbw.so>
 *             kirigaya <kirigaya@mkacg.com>
 *             Hualet <mr.asianwang@gmail.com>
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

#include "widgets/switchwidget.h"
#include "widgets/labels/normallabel.h"

#include <QHBoxLayout>
#include <QDebug>
#include <QMouseEvent>

DWIDGET_USE_NAMESPACE

namespace def {
namespace widgets {

SwitchWidget::SwitchWidget(const QString &title, QWidget *parent)
    : SwitchWidget(parent, new NormalLabel(title, this))
{
}

SwitchWidget::SwitchWidget(QWidget *parent, QWidget *widget)
    : SettingsItem(parent)
    , m_mainLayout(nullptr)
    , m_leftWidget(widget)
    , m_switchBtn(new DSwitchButton(this))
{
    if (!m_leftWidget)
        m_leftWidget = new QLabel(this);

    m_mainLayout = new QHBoxLayout(this);
    m_mainLayout->setSpacing(0);

    m_mainLayout->addWidget(m_leftWidget, 1, Qt::AlignVCenter);
    m_mainLayout->addWidget(m_switchBtn, 0, Qt::AlignVCenter);

    m_leftWidget->setAccessibleName("switchItem_leftLable");
    m_switchBtn->setAccessibleName("switchItem_switchButton");

    m_leftWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    setLayout(m_mainLayout);

    connect(m_switchBtn, &DSwitchButton::toggled, this, &SwitchWidget::checkedChanged);
}

void SwitchWidget::setChecked(const bool checked)
{
    m_switchBtn->blockSignals(true);
    m_switchBtn->setChecked(checked);
    m_switchBtn->blockSignals(false);
}

void SwitchWidget::setTitle(const QString &title)
{
    QLabel *label = qobject_cast<QLabel *>(m_leftWidget);
    if (label) {
        label->setWordWrap(true);
        label->setText(title);
        label->setWordWrap(true);
    }

    setAccessibleName(title);
}

bool SwitchWidget::checked() const
{
    return m_switchBtn->isChecked();
}

QHBoxLayout *SwitchWidget::mainLayout()
{
    return m_mainLayout;
}

void SwitchWidget::setParentAccessibleName(const QString &name)
{
    m_leftWidget->setAccessibleName(QString("%1_leftLable").arg(name));
    m_switchBtn->setAccessibleName(QString("%1_switchButton").arg(name));

    SettingsItem::setParentAccessibleName(name);
}

void SwitchWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (!m_switchBtn->geometry().contains(event->pos())) {
        Q_EMIT clicked();
    }

    return SettingsItem::mouseReleaseEvent(event);
}

} // namespace widgets
} // namespace def
