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
#ifndef SYSCHECKRESUTLWIDGET_H
#define SYSCHECKRESUTLWIDGET_H

#include "syscheckresultheaderwidget.h"
#include "syscheckresultitemwidget.h"

#include <DSuggestButton>
#include <DPushButton>
#include <DFrame>

#include <QWidget>
#include <QList>
#include <QStandardItemModel>

class SysCheckResultWidget : public Dtk::Widget::DFrame
{
    Q_OBJECT
public:
    explicit SysCheckResultWidget(QWidget *parent = nullptr);

public Q_SLOTS:
    void onCheckFinished();
    void onFixing();
    void onFixed();
    void setResultModel(const QStandardItemModel &);
    void setHeaderContent(int point, int issueCount);
    void setFastFixValid(bool);
    void resetItemsBackGround();
    void setAutoStartAppCount(int);
    void onFixStarted(SysCheckItemID id);
    void onFixFinished(SysCheckItemID id);

Q_SIGNALS:
    void onFixItemStarted(SysCheckItemID id);
    void onFixItemFinished(SysCheckItemID id);
    void requestFixItem(SysCheckItemID id);
    void requestFixAll();

    void requestCheckAgain();
    void requestSetIgnore(SysCheckItemID, bool);

    void requestQuit();
    void autoStartAppCountChanged(int);

private:
    void initUI();
    void initConnection();
    void createItemWidgets();
    void hideAll();

private:
    SysCheckResultHeaderWidget *m_header;
    Dtk::Widget::DSuggestButton *m_checkedButton;
    Dtk::Widget::DSuggestButton *m_fixedButton;
    Dtk::Widget::DPushButton *m_recheckButton;
    QList<SysCheckResultItemWidget *> m_itemWidgets;
    QList<SysCheckItemID> m_currentFixingItems;
};

#endif // SYSCHECKRESUTLWIDGET_H
