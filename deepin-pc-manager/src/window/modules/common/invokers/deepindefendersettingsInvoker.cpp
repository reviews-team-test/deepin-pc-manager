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
#include "deepindefendersettingsInvoker.h"

#include <QGSettings>
#include <QVariant>

DeepinDefenderSettingsInvoker::DeepinDefenderSettingsInvoker(const QByteArray &schema_id, const QByteArray &path, QObject *parent)
    : QObject(parent)
{
    if (!parent) {
        parent = this;
    }
    m_settings = new QGSettings(schema_id, path, parent);
}

QVariant DeepinDefenderSettingsInvoker::GetValue(const QString &key) const
{
    if (m_settings) {
        return m_settings->get(key);
    }

    return QVariant(QVariant::Type::Invalid);
}

void DeepinDefenderSettingsInvoker::SetValue(const QString &key, const QVariant &value)
{
    if (m_settings) {
        m_settings->set(key, value);
    }
}

void DeepinDefenderSettingsInvoker::Reset(const QString &key)
{
    if (m_settings) {
        m_settings->reset(key);
    }
}
