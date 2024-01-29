/*
 * Copyright (C) 2020 ~ 2021 Deepin Technology Co., Ltd.
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
#ifndef APPACCESSIBLEBASE_H
#define APPACCESSIBLEBASE_H

#include <QAccessibleInterface>
#include <QAccessibleWidget>
#include <QWidget>

class AppAccessibleBase : public QAccessibleWidget
    , public QAccessibleTextInterface
{
public:
    explicit AppAccessibleBase(QWidget *);
    virtual ~AppAccessibleBase() Q_DECL_OVERRIDE {}

    // 满足接口需要实现的无关方法
    void *interface_cast(QAccessible::InterfaceType t) Q_DECL_OVERRIDE;
    QString text(QAccessible::Text t) const Q_DECL_OVERRIDE;
    void selection(int selectionIndex, int *startOffset, int *endOffset) const Q_DECL_OVERRIDE;
    int selectionCount() const Q_DECL_OVERRIDE;
    void addSelection(int startOffset, int endOffset) Q_DECL_OVERRIDE;
    void removeSelection(int selectionIndex) Q_DECL_OVERRIDE;
    void setSelection(int selectionIndex, int startOffset, int endOffset) Q_DECL_OVERRIDE;
    int cursorPosition() const Q_DECL_OVERRIDE;
    void setCursorPosition(int position) Q_DECL_OVERRIDE;
    int characterCount() const Q_DECL_OVERRIDE;
    QRect characterRect(int offset) const Q_DECL_OVERRIDE;
    int offsetAtPoint(const QPoint &point) const Q_DECL_OVERRIDE;
    void scrollToSubstring(int startIndex, int endIndex) Q_DECL_OVERRIDE;
    QString attributes(int offset, int *startOffset, int *endOffset) const Q_DECL_OVERRIDE;

    // 与自动化测试实现相关处
    // 此处依旧是虚方法以方便继承
    // 因为QWidget没有text()方法,必须在子类中使用控件的text()方法
    virtual QString text(int startOffset, int endOffset) const Q_DECL_OVERRIDE;

private:
    QWidget *m_widget;
};

#endif // APPACCESSIBLEBASE_H
