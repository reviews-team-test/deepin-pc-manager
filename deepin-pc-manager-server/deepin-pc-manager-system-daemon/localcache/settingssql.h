/*
 * Copyright (C) 2019 ~ 2021 Deepin Technology Co., Ltd.
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

//#include "../common/common.h"
#include "../common/gsettingkey.h"
//#include "../common/comdata.h"

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class QXmlStreamReader;

class SettingsSql : public QObject
{
    Q_OBJECT

public:
    explicit SettingsSql(const QString &connName, QObject *parent = nullptr);
    ~SettingsSql();

    bool setValue(const QString &key, const QVariant &value, const bool isDefault = false);
    QVariant getValue(const QString &key);

public Q_SLOTS:
    void initDb();

Q_SIGNALS:

private:
    // 解析gsetting xml文件，并根据文件内容设置默认值
    void setDefaultKeyValues();
    // 从xml中读取默认值，并向数据库中写入
    void readAndSetKeyDefaultValueFromXml(QXmlStreamReader *xmlReader, QString &keyName, QString &keyType);

private:
    QString m_connName;
    QString m_localCacheDbPath;
    QSqlDatabase m_db;
    QSqlQuery m_sqlQuery;
};
