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
#ifndef SYSCHECKRESULTHEADERWIDGET_H
#define SYSCHECKRESULTHEADERWIDGET_H

#include "systemcheckdefinition.h"

#include <DFrame>
#include <DLabel>
#include <DTipLabel>

#include <QWidget>

class SysCheckResultHeaderWidget : public Dtk::Widget::DFrame
{
    Q_OBJECT
public:
    explicit SysCheckResultHeaderWidget(QWidget *parent = nullptr);
    ~SysCheckResultHeaderWidget() {}

public Q_SLOTS:
    void onPointChanged(int, int);
    void onFastFixFinished();
    void onFastFixStarted();

private:
    void initUI();
    void hideAll();

private:
    Dtk::Widget::DLabel *m_pointValue;
    Dtk::Widget::DLabel *m_pointText;
    Dtk::Widget::DLabel *m_title;
    Dtk::Widget::DLabel *m_logo;
    Dtk::Widget::DTipLabel *m_tips;
    Dtk::Widget::DLabel *m_fixingTitle;
    Dtk::Widget::DTipLabel *m_fixingTips;
};

#endif // SYSCHECKRESULTHEADERWIDGET_H
