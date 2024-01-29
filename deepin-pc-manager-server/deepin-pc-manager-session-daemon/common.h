/*
 * Copyright (C) 2019 ~ 2019 Deepin Technology Co., Ltd.
 *
 * Author:     wubowen <caimengci_cm@deepin.com>
 *
 * Maintainer: wubowen <caimengci_cm@deepin.com>
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

#include <QString>
#include <QMap>

const QString service = "com.deepin.pc.manager.session.daemon";
const QString path = "/com/deepin/pc/manager/session/daemon";

#define MB 1 << 10
#define GB 1 << 20
#define TB 1 << 30
#define KB_SECTION(temp) ((temp >= 0 && temp < (MB)) ? true : false)
#define MB_SECTION(temp) ((temp >= (MB) && temp < (GB)) ? true : false)
#define GB_SECTION(temp) ((temp >= (GB) && temp < (TB)) ? true : false)
#define TB_SECTION(temp) ((temp >= (TB)) ? true : false)
//解决转换解析的desktop与系统desktop不匹配问题

QString getSystemDesktop(QString desktop);
