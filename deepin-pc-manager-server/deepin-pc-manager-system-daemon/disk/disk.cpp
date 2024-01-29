/*
 * Copyright (C) 2019 ~ 2020 Deepin Technology Co., Ltd.
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
#include "disk.h"

#include <QList>
#include <QDebug>

// 检查是否为可用设备
bool useableDevice(const PedDevice *lpDevice)
{
    Q_ASSERT(nullptr != lpDevice);
    char *buf = static_cast<char *>(malloc(size_t(lpDevice->sector_size)));
    if (!buf)
        return false;

    // Must be able to read from the first sector before the disk device is considered
    // useable in GParted.
    bool success = false;
    int fd = open(lpDevice->path, O_RDONLY | O_NONBLOCK);
    if (fd >= 0) {
        ssize_t bytesRead = read(fd, buf, size_t(lpDevice->sector_size));
        success = (bytesRead == lpDevice->sector_size);
        close(fd);
    }
    free(buf);
    return success;
}

// 获取磁盘设备路径列表
QList<QString> getDiskDevicePathList()
{
    QList<QString> devicepaths{};

    ped_device_probe_all();
    PedDevice *lpDevice = ped_device_get_next(nullptr);
    while (lpDevice) {
        if (useableDevice(lpDevice)) {
            devicepaths.append(lpDevice->path);
        }
        lpDevice = ped_device_get_next(lpDevice);
    }

    return devicepaths;
}
