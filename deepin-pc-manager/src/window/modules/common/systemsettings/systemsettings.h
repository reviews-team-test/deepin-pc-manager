/*
 * Copyright (C) 2019 ~ 2021 UnionTech Software Technology Co., Ltd.
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
#pragma once

#include <QObject>
#include <QDBusVariant>

class DBusInvokerInterface;

namespace def {
class SystemSettings : public QObject
{
    Q_OBJECT
public:
    explicit SystemSettings(QObject *parent = nullptr);
    virtual ~SystemSettings() override;

    bool setValue(const QString &key, const QVariant &value);
    QVariant getValue(const QString &key);

Q_SIGNALS:
    void valueChanged(const QString &key, const QVariant &value);

public Q_SLOTS:
    void onValueChanged(const QString &key, const QDBusVariant &value);

private:
    DBusInvokerInterface *m_netMonitorDBusInvoker;
};
} // namespace def
