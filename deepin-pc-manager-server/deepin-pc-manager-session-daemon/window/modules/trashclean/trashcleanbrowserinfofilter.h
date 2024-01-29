/*
 * Copyright (C) 2019 ~ 2021 Uniontech Software Technology Co.,Ltd.
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

#ifndef TRASHCLEANBROWSERINFOFILTER_H
#define TRASHCLEANBROWSERINFOFILTER_H

#include "trashcleanappinfofilter.h"

class TrashCleanBrowserInfoFilter : public TrashCleanAppInfoFilter
{
    Q_OBJECT
public:
    explicit TrashCleanBrowserInfoFilter(QObject *parent = nullptr);
    virtual ~TrashCleanBrowserInfoFilter() override = default;
    // 针对浏览器cookies获取
    // 重写以下方法
    virtual TrashCleanAppList InitAppData(QString) override;
    virtual void MergeAppInfo() override;

private:
    virtual bool isValidConfig(const TrashCleanApp &) override;
};

#endif // TRASHCLEANBROWSERINFOFILTER_H
