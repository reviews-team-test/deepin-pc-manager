/*
 * Copyright (C) 2020 ~ 2021 Deepin Technology Co., Ltd.
 *
 * Author:     caimengci <caimengci@uniontech.com>
 *
 * Maintainer: caimengci <caimengci@uniontech.com>
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
#ifndef RESTARTDEFENDERDIALOG_H
#define RESTARTDEFENDERDIALOG_H

#include <DDialog>

// 心跳服务
class DBusInvokerInterface;

DWIDGET_USE_NAMESPACE
class RestartDefenderDialog : public DTK_WIDGET_NAMESPACE::DDialog
{
    Q_OBJECT
public:
    explicit RestartDefenderDialog(DDialog *parent = nullptr);
    ~RestartDefenderDialog() override;

private:
    // 初始化界面
    void initUi();

Q_SIGNALS:
    // 发送重启信号
    void onRestartClose();
    // 弹框关闭信号
    void onDialogClose();

private Q_SLOTS:
    // 按钮点击槽
    void doButtonClicked(int index, const QString &text);

private:
    DBusInvokerInterface *m_daemonservice; // 心跳接口
};

#endif // RESTARTDEFENDERDIALOG_H
