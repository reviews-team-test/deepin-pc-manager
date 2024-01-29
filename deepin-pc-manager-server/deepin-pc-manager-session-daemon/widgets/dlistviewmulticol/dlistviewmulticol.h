/*
 * Copyright (C) 2019 ~ 2021 UnionTech Software Technology Co., Ltd.
 *
 * Author:     caitao <caitao@uniontech.com>
 *
 * Maintainer: caitao <caitao@uniontech.com>
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

#include "../defendertableheaderview.h"

#include <DListView>

DWIDGET_USE_NAMESPACE

//class DFrame;
class QHeaderView;

class DListViewMultiCol : public DListView
{
    Q_OBJECT
public:
    explicit DListViewMultiCol(QStandardItemModel *model, QWidget *parent = nullptr);
    ~DListViewMultiCol() override;

    void setRowHeight(int height);
    void setItemIconSize(const QSize &size);
    // 设置某列表头下标是否可见
    void setHeadSortingIndicatorVisible(int col, bool visible);
    // 调整表头各列宽度
    void resizeHeaderSection(int logicalIndex, int size);

protected:
    void resizeEvent(QResizeEvent *event) override;
    void updateGeometries() override;

Q_SIGNALS:
    void headViewSortIndicatorChanged(int index, Qt::SortOrder order);

public slots:
    // 当表头各列宽度改变
    void updateHeaderWidth();
    // 当水平滑动条变动
    void onHorizontalScrollBarValueChanged(int value);
    // 当排序改变
    void onHeadViewSortIndicatorChanged(int index, Qt::SortOrder order);

private:
    void initUi();
    void initConnection();
    void stretchLastSectionToRightest();

private:
    QStandardItemModel *m_model;
    QWidget *m_headerWidget;
    DefenderTableHeaderView *m_headerView;
    QList<int> m_headerWidthList; // 表头各列宽度列表
};
