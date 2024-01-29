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

#ifndef MULTICOMBOX_H
#define MULTICOMBOX_H

#include <QWidget>
#include <QComboBox>

class MenuItem;
class QLineEdit;
class QListView;
class QStandardItemModel;

class MultiComBox : public QComboBox
{
    Q_OBJECT

public:
    explicit MultiComBox(QWidget *parent = nullptr);
    ~MultiComBox() override;

    //添加Iiem
    void addItems(QList<MenuItem *> menus);

    QStringList getItemsText();
    QList<int> getItemsId();

    void setActivated(int row);
    QString getSelectedRows();
    QString getSelectedIndexs();

Q_SIGNALS:
    void sendSelected(QList<int> list);

private:
    void updateText();

public Q_SLOTS:
    void sltActivated(const QModelIndex &index);

protected:
    void hidePopup() override;

private:
    QList<MenuItem> m_Menus;
    QLineEdit *m_pLineEdit;
    QListView *m_pListView;
    QStandardItemModel *m_pItemModel;
};

#endif // MULTICOMBOX_H
