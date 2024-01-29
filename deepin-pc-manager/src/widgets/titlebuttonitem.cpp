/*
 * Copyright (C) 2019 ~ 2021 Deepin Technology Co., Ltd.
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
#include "titlebuttonitem.h"

#include <QHBoxLayout>

namespace def {
namespace widgets {

TitleButtonItem::TitleButtonItem(QWidget *parent)
    : SettingsItem(parent)
    , m_titleLabel(new TipsLabel(this))
    , m_button(new QPushButton(this))
{
    addBackground();

    QHBoxLayout *layout = new QHBoxLayout;
    layout->setContentsMargins(10, 5, 10, 5);
    setLayout(layout);

    layout->addWidget(m_titleLabel, 0, Qt::AlignLeft);

    layout->addWidget(m_button, 0, Qt::AlignRight);
}

// 设置相关标签名称
void TitleButtonItem::setAccessibleParentText(QString sAccessibleName)
{
    m_titleLabel->setAccessibleName(sAccessibleName + "_titleLable");
    m_button->setAccessibleName(sAccessibleName + "_settingButton");
}

void TitleButtonItem::setTitle(QString str)
{
    m_titleLabel->setText(str);
}

void TitleButtonItem::setButtonText(QString str)
{
    m_button->setText(str);
}

} //namespace widgets
} //namespace def
