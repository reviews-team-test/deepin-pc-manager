/*
 * Copyright (C) 2020 ~ 2020 Deepin Technology Co., Ltd.
 *
 * Author:     caimengci <caimengci@uniontech.com>
 *
 * Maintainer: caimengci <caimengci@uniontech.com>
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
#ifndef DEFENDERTABLEHEADERVIEW_H
#define DEFENDERTABLEHEADERVIEW_H

#include <DHeaderView>

DWIDGET_USE_NAMESPACE

// DHeaderView重载类
class DefenderTableHeaderView : public DHeaderView
{
public:
    DefenderTableHeaderView(Qt::Orientation orientation, QWidget *parent = nullptr);

    // 表头seize
    QSize sizeHint() const override;
    int sectionSizeHint(int logicalIndex) const;

    // 表头间隔
    inline int getSpacing() const { return m_spacing; }
    inline void setSpacing(int spacing) { m_spacing = spacing; }

    // 掩藏某列表头下标
    void setHeadViewSortHide(int nIndex);
    // 设置某列表头下标是否可见
    void setSortingIndicatorVisible(int nIndex, bool visible);

protected:
    // 表头类绘制事件
    void paintEvent(QPaintEvent *e) override;
    virtual void paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const override;

    // 焦点事件
    void focusInEvent(QFocusEvent *event) override;

private:
    int m_spacing;
    QList<int> m_indicatorHiddingColList;
    Qt::FocusReason m_reson;
};

#endif // DEFENDERTABLEHEADERVIEW_H
