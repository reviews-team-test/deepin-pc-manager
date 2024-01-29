/*
 * Copyright (C) 2022 ~ 2022 UnionTech Software Technology Co., Ltd.
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
#ifndef AVCPULIMITATION_H
#define AVCPULIMITATION_H

#include <DLabel>

#include <QWidget>

class QCheckBox;

class AVCPULimitation : public QWidget
{
    Q_OBJECT
public:
    explicit AVCPULimitation(QWidget *parent = nullptr);
    virtual ~AVCPULimitation();

    // 设置选择框
    void setcheckbox(bool status);

    // 选择框的改变
    void checkBoxChange(bool);

Q_SIGNALS:
    // 选择框的状态信号
    void notifyCheckBoxChange(bool);

private:
    DTK_WIDGET_NAMESPACE::DLabel *m_context; // 内容
    DTK_WIDGET_NAMESPACE::DLabel *m_tips; // 单位
    QCheckBox *m_check; // 选择框
};

#endif // AVCPULIMITATION_H
