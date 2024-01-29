/*
 * Copyright (C) 2021 ~ 2021 Deepin Technology Co., Ltd.
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
#ifndef DEEPIN_DEFENDER_SETTINGS_H
#define DEEPIN_DEFENDER_SETTINGS_H

#include "invokerinterface.h"

#include <QObject>

class QGSettings;

class DeepinDefenderSettingsInvoker : public QObject
    , public SettingsInvokerInterface
{
    Q_OBJECT
public:
    explicit DeepinDefenderSettingsInvoker(const QByteArray &schema_id, const QByteArray &path = QByteArray(), QObject *parent = nullptr);
    virtual ~DeepinDefenderSettingsInvoker() override {}

    virtual QVariant GetValue(const QString &key) const override;
    virtual void SetValue(const QString &key, const QVariant &value) override;
    virtual void Reset(const QString &key) override;

private:
    QGSettings *m_settings;

    // 禁用拷贝构造，没有这种操作的必要，并且会增加资源控制的麻烦
    DeepinDefenderSettingsInvoker(DeepinDefenderSettingsInvoker &);
    DeepinDefenderSettingsInvoker &operator=(const DeepinDefenderSettingsInvoker &);
};

#endif // DEEPIN_DEFENDER_SETTINGS_H
