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
#ifndef TRASHCLEANGREETINGWIDGET_H
#define TRASHCLEANGREETINGWIDGET_H

#include "trashcleanconfigitem.h"

#include <DLabel>
#include <DFrame>
#include <DSuggestButton>
#include <DGuiApplicationHelper>

#include <QWidget>
#include <QList>

class CleanerDBusAdaptorInterface;

class TrashCleanGreetingWidget : public Dtk::Widget::DFrame
{
    Q_OBJECT
public:
    explicit TrashCleanGreetingWidget(QWidget *parent = nullptr);
    ~TrashCleanGreetingWidget() {}

    inline const QList<int> &getScanConfig() { return m_scanConfigList; }

    void setGreeing(const QString &info);

Q_SIGNALS:
    void notifyStartScan();

public Q_SLOTS:
    void onItemStageChanged(int, int);
    void setPixmapByTheme(Dtk::Gui::DGuiApplicationHelper::ColorType themeType);

private:
    void initUI();
    void initConnection();

private:
    Dtk::Widget::DLabel *m_logo;
    Dtk::Widget::DLabel *m_title;
    Dtk::Widget::DLabel *m_greeting;
    TrashCleanConfigItem *m_sysItem;
    TrashCleanConfigItem *m_appItem;
    TrashCleanConfigItem *m_hisItem;
    TrashCleanConfigItem *m_cookiesItem;
    Dtk::Widget::DSuggestButton *m_scanBtn;
    QList<int> m_scanConfigList;

    // 应用界面工具对象，方便使用系统主题相关方法
    //DGuiApplicationHelper *m_guiHelper;
};

#endif // TRASHCLEANGREETINGWIDGET_H
