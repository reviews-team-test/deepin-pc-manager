/*
 * Copyright (C) 2020 ~ 2022 Uniontech Software Co., Ltd.
 *
 * Author:     shenfusheng <shenfusheng@uniontech.com>
 *
 * Maintainer: shenfusheng <shenfusheng@uniontech.com>
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
#include "defsecuritytoollistwidget.h"

DefSecurityToolListWidget::DefSecurityToolListWidget(QWidget *parent)
    : DListWidget(parent)
{
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFocusPolicy(Qt::NoFocus);
    setMovement(QListView::Static);
    setFrameShape(QListWidget::NoFrame);
    setEditTriggers(QListView::NoEditTriggers);
    setViewMode(QListView::IconMode);
    setResizeMode(QListView::Adjust);
    setFlow(QListView::LeftToRight);
    setUniformItemSizes(true);
    setDragEnabled(false);
    //setStyleSheet("QListWidget {border:1px solid gray;}");
    setContentsMargins(0, 0, 0, 0);
}

DefSecurityToolListWidget::~DefSecurityToolListWidget()
{
}
