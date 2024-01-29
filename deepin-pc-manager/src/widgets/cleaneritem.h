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
#include <DCheckBox>
#include <DTipLabel>

#include <QWidget>
#include <QLabel>
#include <QTimer>

DWIDGET_USE_NAMESPACE
class CleanerItem : public DFrame
{
    Q_OBJECT
public:
    explicit CleanerItem(QWidget *parent = nullptr);
    ~CleanerItem();

    // 设置标题和提示
    void setLevelText(QString text);
    void setTipText(QString text);

    // 设置/获取 勾选框状态
    void setCheckBoxStatus(bool isbStatus);
    bool getCheckBoxStatus() const;

    // 设置相关标签名称
    void setAccessibleParentText(const QString &sAccessibleName);

protected:
    void paintEvent(QPaintEvent *event);

Q_SIGNALS:
    void itemClicked();

private:
    QWidget *m_firstLayerWidgt;
    DCheckBox *m_checkBox;
    DLabel *m_levelLabel;
    DTipLabel *m_tipLabel;

    QString m_tipStr;
};
