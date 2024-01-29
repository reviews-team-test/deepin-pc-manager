/*
 * Copyright (C) 2019 ~ 2022 UnionTech Software Technology Co., Ltd.
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
#include "selectediconwidget.h"

#include <DStyleHelper>

#include <QDebug>
#include <QPaintEvent>
#include <QPainter>
#include <QStyle>

DWIDGET_USE_NAMESPACE

namespace def {
namespace widgets {
SelectedIconWidget::SelectedIconWidget(QWidget *parent)
    : QWidget(parent)
{
    QStyleOption option;
    option.initFrom(this);
    m_icon = DStyleHelper(style()).standardIcon(DStyle::SP_IndicatorChecked, &option, this);
}

SelectedIconWidget::~SelectedIconWidget()
{
}

void SelectedIconWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    QPalette pa = this->palette();
    QColor color = pa.color(QPalette::ColorGroup::Normal, QPalette::ColorRole::Highlight);
    painter.setPen(color);

    QRect iconRect(QPoint(0, 0), size());

    iconRect.moveCenter(rect().center());
    iconRect.moveLeft(rect().left());

    m_icon.paint(&painter, iconRect);
}

} // namespace widgets
} // namespace def
