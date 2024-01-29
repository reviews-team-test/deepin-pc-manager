/*
 * Copyright (C) 2021 ~ 2021 Deepin Technology Co., Ltd.
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

#ifndef UPDATEADDRESSITEM_H
#define UPDATEADDRESSITEM_H

#include <DLineEdit>

#include <QWidget>

DWIDGET_BEGIN_NAMESPACE
class DLineEdit;
DWIDGET_END_NAMESPACE

class QLabel;
class QCheckBox;
DWIDGET_USE_NAMESPACE

/**
 * @brief 设置中升级病毒地址的Item
 */
class UpdateAddressItem : public QWidget
{
    Q_OBJECT
public:
    explicit UpdateAddressItem(QWidget *parent = nullptr);

    // 设置地址
    void setUpdateAddres(QString address);
    // 设置选择框状态
    void setCheckboxStatus(bool status);
    // 编辑改变
    void lineEditChange(QString str);
    // 焦点改变
    void focusChanged(bool change);

    // 获得地址
    inline QString getAddress() const {return m_address->text();}
    bool getCheckBoxStatus() const;

signals:
    // 发送结束完成的信号
    void sendInputFinised(QString address);
    // 选择框的状态信号
    void sendCheckBoxChange(int status);

private:
    QLabel      *m_context;             // 内容
    DLineEdit   *m_address;             // 地址输入框
    QCheckBox   *m_checkbox;            // 选择框
};

#endif // UPDATEADDRESSITEM_H
