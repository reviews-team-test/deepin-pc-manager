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

#include "menuitem.h"

MenuItem::MenuItem(int iMenuId, const QString &strMenuName, bool bIsChecked /* = false */)
    : m_iMenuId(iMenuId)
    , m_strMenuName(strMenuName)
    , m_bIsChecked(bIsChecked)
{
}

MenuItem::MenuItem()
{
    m_iMenuId = -1;
    m_strMenuName = QString("");
    m_bIsChecked = false;
}

MenuItem::MenuItem(const MenuItem &menuItem)
{
    m_iMenuId = menuItem.GetMenuId();
    m_strMenuName = menuItem.GetMenuName();
    m_bIsChecked = menuItem.GetIsChecked();
}

MenuItem::~MenuItem()
{
}

int MenuItem::GetMenuId() const
{
    return m_iMenuId;
}

void MenuItem::SetMenuId(int iValue)
{
    m_iMenuId = iValue;
}

QString MenuItem::GetMenuName() const
{
    return m_strMenuName;
}

void MenuItem::SetMenuName(const QString &strValue)
{
    m_strMenuName = strValue;
}
// 返回当前控件是否被选中
bool MenuItem::GetIsChecked() const
{
    return m_bIsChecked;
}

void MenuItem::SetIsChecked(bool bValue)
{
    m_bIsChecked = bValue;
}
