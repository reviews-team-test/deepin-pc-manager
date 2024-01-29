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
#ifndef TRASHCLEANCONFIGITEM_H
#define TRASHCLEANCONFIGITEM_H

#include <DLabel>
#include <DFrame>

#include <QWidget>
#include <QCheckBox>

DWIDGET_BEGIN_NAMESPACE
class DLable;
class DTipLabel;
class DBackgroundGroup;
DWIDGET_END_NAMESPACE

class TrashCleanConfigItem : public Dtk::Widget::DFrame
{
    Q_OBJECT

public:
    explicit TrashCleanConfigItem(QWidget *parent = nullptr);
    ~TrashCleanConfigItem() {}
    void setTitles(const QString &, const QString &);
    void setCheckBoxStatus(bool);
    void setIconPath(const QString &path);
    inline void setIndex(int index) { m_configIndex = index; }
Q_SIGNALS:
    void stageChanged(int, int);

private:
    void initUI();
    void initConnection();

private:
    QCheckBox *m_checkbox;
    Dtk::Widget::DLabel *m_icon;
    Dtk::Widget::DLabel *m_title;
    Dtk::Widget::DTipLabel *m_tips;
    Dtk::Widget::DBackgroundGroup *m_backgroup;
    Dtk::Widget::DFrame *m_textFrame;
    int m_configIndex;
};

#endif // TRASHCLEANCONFIGITEM_H
