/*
 * Copyright (C) 2019 ~ 2022 Deepin Technology Co., Ltd.
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
#ifndef SYSTEMMESSAGEHELPER_H
#define SYSTEMMESSAGEHELPER_H

#include <QObject>

class SystemMessageHelper : public QObject
{
    Q_OBJECT
public:
    explicit SystemMessageHelper(QObject *parent = nullptr);

    static void createMessageForAVEngineExpiredInDays(const QString &, int days);
};

#endif // SYSTEMMESSAGEHELPER_H
