/*
 * Copyright (C) 2020 ~ 2021 Deepin Technology Co., Ltd.
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
#include "appaccessiblebutton.h"

AppAccessibleButton::AppAccessibleButton(QPushButton *btn)
    : AppAccessibleBase(btn)
    , m_widget(btn)
{
}

QString AppAccessibleButton::text(int startOffset, int endOffset) const
{
    Q_UNUSED(startOffset);
    Q_UNUSED(endOffset);

    if (m_widget) {
        return m_widget->text();
    }

    return QString();
}
