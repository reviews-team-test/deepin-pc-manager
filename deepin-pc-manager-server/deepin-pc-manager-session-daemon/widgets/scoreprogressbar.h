/*
 * Copyright (C) 2019 ~ 2019 Deepin Technology Co., Ltd.
 *
 * Author:     caitao <caitao@deepin.com>
 *
 * Maintainer: caitao <caitao@deepin.com>
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

#include "window/namespace.h"
#include "dtkwidget_global.h"

#include <QWidget>

class QPropertyAnimation;

#define VALUE_CHANGE_INTERVAL_MS 20

DEF_NAMESPACE_BEGIN
DEF_ANTIVIRUS_NAMESPACE_BEGIN

class ScoreProgressBar : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int currentValue READ currentValue WRITE setCurrentValue USER true)
public:
    explicit ScoreProgressBar(QWidget *parent = nullptr);
    ~ScoreProgressBar();

    QSize minimumSizeHint() const;
    // 设置当前显示值
    void setCurrentValue(int value);
    // 获取当前显示值
    int currentValue() const;
    void setValue(int value);
    inline void setColor(QColor color) { m_color = color; }

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *event);

private:
    // 当前显示值
    int m_currentValue;
    // 设定值
    int m_value;
    // 进度条颜色
    QColor m_color;
    // 进度条数值动画
    QPropertyAnimation *m_valueAnimation;
};
DEF_ANTIVIRUS_NAMESPACE_END
DEF_NAMESPACE_END
