/*
 * Copyright (C) 2019 ~ 2019 Deepin Technology Co., Ltd.
 *
 * Author:     wubowen <wubowen_cm@deepin.com>
 *
 * Maintainer: wubowen <wubowen_cm@deepin.com>
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

#include "operatedbusdata.h"
#include "window/modules/securitytooldialog/securitytooldialoginter.h"
#include "accessible/appaccessible.h"

#include <DApplication>
#include <DMainWindow>
#include <DWidgetUtil>
#include <DLog>

#include <QPushButton>

#include <signal.h>
#include <unistd.h>

DWIDGET_USE_NAMESPACE
DCORE_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication a(argc, argv);
    a.loadTranslator();
    a.setAttribute(Qt::AA_EnableHighDpiScaling);
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    a.setOrganizationName("deepin");
    a.setApplicationName("deepin-pc-manager-session-daemon");
    a.setApplicationDisplayName(""); //标题文字设置为空
    a.setQuitOnLastWindowClosed(false);

    // 设置异步线程退出时间，默认为30秒
    QThreadPool::globalInstance()->setExpiryTimeout(100);

    // 提供自动化测试所需要的实现
    QAccessible::installFactory([](const QString &classname, QObject *object) {
        QAccessibleInterface *interface = nullptr;
        if (object && object->isWidgetType()) {
            // 实测,QPushButton的access不能通过QAbstractButton实现
            if ("QPushButton" == classname) {
                interface = new AppAccessibleButton(static_cast<QPushButton *>(object));
            } else if ("QLabel" == classname) {
                interface = new AppAccessibleLabel(static_cast<QLabel *>(object));
            } else if ("QAbstractButton" == classname) {
                interface = new AppAccessibleQAbstractButton(static_cast<QAbstractButton *>(object));
            }
        }

        if (interface) {
            QAccessible::registerAccessibleInterface(interface);
        }

        return interface;
    });

    DLogManager::registerConsoleAppender();
    DLogManager::registerFileAppender();

    OperateDBusData dbus;
    SecurityToolDialogInter toolDialogDbusInter;

    return a.exec();
}
