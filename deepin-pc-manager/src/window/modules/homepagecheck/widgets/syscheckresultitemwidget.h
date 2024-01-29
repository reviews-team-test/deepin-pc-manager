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
#ifndef SYSCHECKREUSLTITEMWIDGET_H
#define SYSCHECKREUSLTITEMWIDGET_H

#include "systemcheckdefinition.h"

#include <DFrame>
#include <DLabel>
#include <DTipLabel>
#include <DSpinner>
#include <DPushButton>
#include <DCommandLinkButton>

#include <QWidget>
#include <QStandardItemModel>

class SysCheckResultItemWidget : public Dtk::Widget::DFrame
{
    Q_OBJECT
public:
    explicit SysCheckResultItemWidget(SysCheckItemID id, QWidget *parent = nullptr);
    ~SysCheckResultItemWidget() {}

public Q_SLOTS:
    void onNotifyComplete(SysCheckItemID index, bool isAbnormal);
    void onNotifyFixStarted(SysCheckItemID index);
    void onNotifyFixFinished(SysCheckItemID index);
    void onNotifyIgnored(bool isIgnored);
    void setResult(const QStandardItemModel &);
    void onAutoStartAppCountChanged(int);

Q_SIGNALS:
    void requestFixItem(SysCheckItemID index);
    void requestSetIgnore(SysCheckItemID index, bool isNeedIgnore);
    void widgetHidden(); // 隐藏时需要刷新其它项的背景

private:
    void initUI();
    void initConnection();
    void hideAll();
    void setResult(QStandardItem *);

private:
    SysCheckItemID m_id;
    Dtk::Widget::DLabel *m_typeIconLabel;
    Dtk::Widget::DLabel *m_typeNameLabel;
    Dtk::Widget::DLabel *m_statusIconLabel;
    Dtk::Widget::DLabel *m_statusInfoLabel;
    Dtk::Widget::DTipLabel *m_fixTipLabel;
    // Dtk::Widget::DLabel *m_ignoreLabel;
    Dtk::Widget::DCommandLinkButton *m_jumpLabel;
    Dtk::Widget::DSpinner *m_fixSpinner;
    Dtk::Widget::DPushButton *m_ignoreBtn;
    Dtk::Widget::DPushButton *m_disIgnoreBtn;
    QStandardItem *m_resultItem;
};

#endif // SYSCHECKREUSLTITEMWIDGET_H
