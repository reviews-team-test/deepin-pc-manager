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
#include "dlistviewmulticolframe.h"

#include <DApplicationHelper>

#include <QDebug>
#include <QVBoxLayout>

DListViewMultiColFrame::DListViewMultiColFrame(QStandardItemModel *model, QWidget *parent)
    : DFrame(parent)
    , m_model(model)
    , m_listView(nullptr)
{
    initUi();
    initConnection();
}

DListViewMultiColFrame::~DListViewMultiColFrame()
{
}

DListViewMultiCol *DListViewMultiColFrame::listViewMultiCol()
{
    return m_listView;
}

void DListViewMultiColFrame::initUi()
{
    setContentsMargins(1, 1, 1, 1);
    setLineWidth(0);

    setBackgroundRole(DPalette::ColorType::ItemBackground);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(mainLayout);

    m_listView = new DListViewMultiCol(m_model, this);
    m_listView->setAccessibleName("listViewFrame_listView");
    mainLayout->addWidget(m_listView);
}

void DListViewMultiColFrame::initConnection()
{
    connect(m_listView, &DListViewMultiCol::headViewSortIndicatorChanged, this, &DListViewMultiColFrame::headViewSortIndicatorChanged);
}
