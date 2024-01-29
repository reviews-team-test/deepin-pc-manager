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

#include <DFrame>
#include <DTipLabel>

#include <QWidget>
#include <QLabel>
#include <QTimer>

DEF_NAMESPACE_BEGIN
DEF_ANTIVIRUS_NAMESPACE_BEGIN

DWIDGET_USE_NAMESPACE

class SecurityLevelItem : public DFrame
{
    Q_OBJECT
public:
    SecurityLevelItem(QWidget *parent = nullptr);
    ~SecurityLevelItem();

    void setIcon(QIcon icon);
    void setLevelText(QString text);
    void setTipText(QString text);
    void setDisableStyle(bool disable);
    void setStatusIcon(QIcon icon);

protected:
    void mousePressEvent(QMouseEvent *event);

Q_SIGNALS:
    void clicked();

private:
    DLabel *m_icon;
    DLabel *m_levelLabel;
    DTipLabel *m_tipLabel;
    DLabel *m_statusIcon;
};
DEF_ANTIVIRUS_NAMESPACE_END
DEF_NAMESPACE_END
