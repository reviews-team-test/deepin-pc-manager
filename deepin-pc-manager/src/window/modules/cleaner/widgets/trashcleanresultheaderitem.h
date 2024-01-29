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
#ifndef TRASHCLEANRESULTHEADERITEM_H
#define TRASHCLEANRESULTHEADERITEM_H

#include <DLabel>
#include <DTipLabel>
#include <DFrame>

#include <QWidget>

class TrashCleanResultHeaderItem : public Dtk::Widget::DFrame
{
    Q_OBJECT
public:
    explicit TrashCleanResultHeaderItem(QWidget *parent = nullptr);
    ~TrashCleanResultHeaderItem() {}

public Q_SLOTS:
    void setScanStarted();
    // 扫描结束时总文件数
    void setScanStopped(const QString &totalFiles);
    // 清理结束时总文件数与大小
    void setCleanFinished(const QString &, const QString &);
    // 扫描中时间与路径变化
    void updateScanPath(const QString &);
    // 扫描中标题变化
    void updateScanTitleInfo(const QString &total, const QString &selected);

    void setTitle(const QString &);
    void setTip(const QString &);
    void setTimeInfo(const QString &);
    void setLogo(const QString &);

private:
    void initUI();

private:
    Dtk::Widget::DLabel *m_infos;
    Dtk::Widget::DTipLabel *m_actionInfo;
    Dtk::Widget::DTipLabel *m_scanTimeInfo;
    Dtk::Widget::DLabel *m_scanIcon;
};

#endif // TRASHCLEANRESULTHEADERITEM_H
