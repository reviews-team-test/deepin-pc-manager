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

#include "dlistviewmulticol.h"

#include <DFrame>

DWIDGET_USE_NAMESPACE

class DListViewMultiColFrame : public DFrame
{
    Q_OBJECT
public:
    explicit DListViewMultiColFrame(QStandardItemModel *model, QWidget *parent = nullptr);
    ~DListViewMultiColFrame() override;

    DListViewMultiCol *listViewMultiCol();

Q_SIGNALS:
    void headViewSortIndicatorChanged(int index, Qt::SortOrder order);

private:
    void initUi();
    void initConnection();

private:
    QStandardItemModel *m_model;
    DListViewMultiCol *m_listView;
};
