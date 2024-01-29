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

#include <DFrame>

DWIDGET_USE_NAMESPACE

class AnimatedLineEdit;

class QVariantAnimation;
class QLabel;

class SearchLineEdit : public DFrame
{
    Q_OBJECT
public:
    explicit SearchLineEdit(QWidget *parent = nullptr);
    virtual ~SearchLineEdit() override;
    // 设置父对象标签名称
    virtual void setParentAccessibleName(const QString &name);

protected:
    virtual void resizeEvent(QResizeEvent *event) override;
    virtual bool eventFilter(QObject *obj, QEvent *event) override;

Q_SIGNALS:
    void textChanged(const QString &);

public Q_SLOTS:
    void updateIcon();

private:
    void initUi();
    void initConnection();

private:
    QWidget *m_topWidget;
    QLabel *m_searchIconLable;
    QLabel *m_topTextLable;
    AnimatedLineEdit *m_lineEdit;
    QAction *m_searchIconAction;
};
