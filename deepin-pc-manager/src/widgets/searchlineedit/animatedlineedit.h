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

#include <QLineEdit>

class QVariantAnimation;

class AnimatedLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit AnimatedLineEdit(QWidget *parent = nullptr);
    virtual ~AnimatedLineEdit() override;

    void startAnimation();

protected:
    virtual void resizeEvent(QResizeEvent *e) override;
    virtual void paintEvent(QPaintEvent *e) override;

Q_SIGNALS:

public Q_SLOTS:
    void updateIcon();

private:
    void initUi();
    void initConnection();

private:
    QVariantAnimation *m_animation;
    QPixmap m_toLeftGlowingImg;
    QPixmap m_toRightGlowingImg;
};
