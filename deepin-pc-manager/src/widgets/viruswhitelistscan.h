/*
* Copyright (C) 2021 ~ 2021 Uniontech Technology Co., Ltd.
*
* Author:      herun <herun@uniontech.com>
*
* Maintainer:  herun <herun@uniontech.com>
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

#ifndef VIRUSWHITELISTSCAN_H
#define VIRUSWHITELISTSCAN_H

#include <DIconButton>

#include <QToolButton>
#include <QWidget>

class QLabel;
class QCheckBox;

DWIDGET_USE_NAMESPACE

/**
 * @brief 设置中白名单扫描
 */

class VirusWhitelistScanItem : public QWidget
{
    Q_OBJECT
public:
    explicit VirusWhitelistScanItem(QWidget *parent = nullptr);
    ~VirusWhitelistScanItem();

    // 设置显示内容
    void setText(const QString &text);
    // 按钮触发弹窗
    void pushButtonTrigger(bool status);

signals:
    // 按钮点击发射信号
    void buttonTrigger(bool val);

private:
    QLabel *m_lbText; // 内容
    QLabel *m_lbTip; // 提示
    DIconButton *m_dialogBtn; // 前进按钮
};

#endif // VIRUSWHITELISTSCAN_H
