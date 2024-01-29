// Copyright (C) 2019 ~ 2021 UnionTech Software Technology Co., Ltd.
// SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

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
