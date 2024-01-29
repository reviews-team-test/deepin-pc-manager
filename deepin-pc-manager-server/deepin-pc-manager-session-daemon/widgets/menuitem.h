/*
* Copyright (C) 2021 ~ 2021 Uniontech Technology Co., Ltd.
*
* Author:      caimengci <caimengci@uniontech.com>
*
* Maintainer:  caimengci <caimengci@uniontech.com>
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

#ifndef MENUITEM_H
#define MENUITEM_H

#include <QObject>

class MenuItem
{
public:
    MenuItem(int iMenuId, const QString &strMenuName, bool bIsChecked = false);
    MenuItem();
    ~MenuItem();

    MenuItem(const MenuItem &menuItem);
    int GetMenuId() const;
    void SetMenuId(int iValue);

    QString GetMenuName() const;
    void SetMenuName(const QString &strValue);

    bool GetIsChecked() const;
    void SetIsChecked(bool bValue);

private:
    int m_iMenuId;
    QString m_strMenuName;
    bool m_bIsChecked;
};

#endif // MENUITEM_H
