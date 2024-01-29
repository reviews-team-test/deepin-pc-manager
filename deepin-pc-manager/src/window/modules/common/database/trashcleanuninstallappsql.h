/*
 * Copyright (C) 2019 ~ 2021 Uniontech Software Technology Co.,Ltd.
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

#ifndef TRASHCLEANUNINSTALLAPPSQL_H
#define TRASHCLEANUNINSTALLAPPSQL_H

#include "defenderdatabaseoperationbase.h"

class TrashCleanUninstallAppSql : public DefenderDatabaseOperationBase
{
    Q_OBJECT
public:
    enum UninstalledAppSqlCmdType {
        GET_ALL_RECORDS,
        INSERT_A_RECORD,
        DELETE_A_RECORD
    };

public:
    typedef QList<QPair<QString, QString>> QueryRecordsList;
    explicit TrashCleanUninstallAppSql(QObject *parent = nullptr);
    virtual ~TrashCleanUninstallAppSql() override;

Q_SIGNALS:
    void sendQueryResultSignal(QVariantList);

private:
    QString tableName() override;
    void sendResult(int, QSqlQuery &) override;
    QString formatCmd(int, const QVariantList & = {}) override;
    virtual bool createTable() override;
};

#endif // TRASHCLEANUNINSTALLAPPSQL_H
