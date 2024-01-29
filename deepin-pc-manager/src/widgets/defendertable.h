/*
 * Copyright (C) 2019 ~ 2020 Deepin Technology Co., Ltd.
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

#include <DFrame>
#include <DTableView>

#include <QVBoxLayout>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QTableView>
#include <QScrollBar>

DWIDGET_USE_NAMESPACE

#define ROW_HEIGHT 30 // 初始化高度

class DefenderTableHeaderView;
namespace def {
namespace widgets {

class DefenderTable : public DFrame
{
    Q_OBJECT
public:
    explicit DefenderTable(QWidget *parent = nullptr, int height = ROW_HEIGHT);
    ~DefenderTable();

    // 初始化UI
    void initUI();

    // 设置相关联的表格和数据模型
    void setTableAndModel(DTableView *table, QStandardItemModel *model);

    // 设置行高
    void setRowHeight(int height);

    // 掩藏某列表头下标
    void setHeadViewSortHide(int nIndex);

protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    DefenderTableHeaderView *m_headerDelegate; // 表头代理类

    DFrame *m_mainBackgroundWidgt; // 填充背景的frame控件
    QStandardItemModel *m_tableModel; // 数据模型
    DTableView *m_table; // 表格
    QList<DFrame *> m_backgroundLst; // 背景列表

    int m_rowHeight; // 行高
    int m_rowCount; // 总共的行数
};

} // namespace widgets
} // namespace def
