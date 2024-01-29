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

#include <DBackgroundGroup>
#include <DCommandLinkButton>
#include <DPushButton>

#include <QWidget>
#include <QLabel>
#include <QObject>
#include <QDebug>

DWIDGET_USE_NAMESPACE

class FixItemWindow : public QFrame
{
    Q_OBJECT
public:
    FixItemWindow(bool flag, QWidget *parent = nullptr);
    void setIcon(QIcon icon);
    void setText(QString text);
    void setButtonText(QString text, bool flag);
    DCommandLinkButton *getButton();
    // 获得按钮的名字
    QString getButtonText();
protected:
    void resizeEvent(QResizeEvent *event);

private:
    DBackgroundGroup *m_bgGroup;
    QLabel *m_leftIcon;
    QLabel *m_leftLabel;
    DCommandLinkButton *m_rightBtn;
    bool m_isFlag;
//    DPushButton *m_rightBtn;
//    DPushButton *m_rightBtn;
};
