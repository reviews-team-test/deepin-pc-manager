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
#pragma once

#include "settingsitem.h"
#include "labels/tipslabel.h"

#include <QPushButton>

namespace def {
namespace widgets {

class TitleButtonItem : public SettingsItem
{
    Q_OBJECT
public:
    explicit TitleButtonItem(QWidget *parent = nullptr);

    inline QPushButton *button() { return m_button; }
    void setTitle(QString str);
    void setButtonText(QString str);

    // 设置相关标签名称
    void setAccessibleParentText(QString sAccessibleName);

Q_SIGNALS:

private:
    TipsLabel *m_titleLabel;
    QPushButton *m_button;
};

} // namespace widgets
} // namespace def
