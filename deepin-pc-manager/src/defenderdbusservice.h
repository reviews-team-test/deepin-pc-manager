/*
 * Copyright (C) 2011 ~ 2019 Deepin Technology Co., Ltd.
 *
 * Author:     wubw <wubowen_cm@deepin.com>
 *
 * Maintainer: wubw <wubowen_cm@deepin.com>
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

#include <QObject>
#include "manager_adaptor.h"

class MainWindow;

class DefenderDBusService : public QObject
{
    Q_OBJECT
public:
    explicit DefenderDBusService(QObject *parent = nullptr);

Q_SIGNALS:

public Q_SLOTS:
    void Show();
    MainWindow *parent();
    void ShowModule(const QString &module);
    void ShowPage(const QString &module, const QString &page);
    void ExitApp();

private:
    ManagerAdaptor *m_adaptor;
};
