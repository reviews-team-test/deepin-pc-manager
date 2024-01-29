/*
 * Copyright (C) 2020 ~ 2020 Deepin Technology Co., Ltd.
 *
 * Author:     maxiangzhi <maxiangzhi@uniontech.com>
 *
 * Maintainer: maxiangzhi <maxiangzhi@uniontech.com>
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
#ifndef COMDATA_H
#define COMDATA_H

#include <QString>

// 当前扫描处于状态
enum ScanStatus {
    Free = 0, // 空闲状态
    Scanning, // 扫描中　同　CONTINUE
    Pausing, // 暂停中
    ResultThreats, //　扫描结果页，有异常
    ResultNoThreats, //　扫描结果页，　无异常
    UsbScanning, // Usb扫描中
    HomePageScanning, // 首页扫描中
    HomePageResult, // 首页扫描结果
    HomePageFixing, // 首页修复中
    VdbUpdating, // 病毒库更新中
};

// 提示框表叫高的几种提示语
enum TipTextInfo {
    TipHomeChecking = 0, // 首页正在体检中
    TipHomeThreats, // 首页有异常但是没有修复
    TipHomeFixing, // 首页异常在修复中
    TipThreatScaning, // 三中扫描方式，右键  在开启扫描页面
    TipUsbScaning, // usb正在扫描中
    TipUpdate, // 更新中
    TipNetWorkEroor, // 网络异常
    TipDefault
};

// 提示的左上角图标
enum TipIcon {
    IconNormal = 0, // 常规 安全中心的图标
    IconTip, // 一般提示  浅黄色感叹号
    IconWaring, // 警告   红色感叹号
};

#endif // COMDATA_H
