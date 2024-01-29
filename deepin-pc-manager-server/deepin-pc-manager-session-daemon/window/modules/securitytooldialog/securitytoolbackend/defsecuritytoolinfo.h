// Copyright (C) 2020 ~ 2022 Uniontech Software Co., Ltd.
// SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef DEFSECURITYTOOLINFO_H
#define DEFSECURITYTOOLINFO_H

#include <QString>
#include <QMetaType>

//定义工具状态信息
enum DEFSECURITYTOOLSTATUS {
    UNINSTALLED, //未安装
    INSTALLING, //安装中
    INSTALLED, //已安装
    INSTALLFAILED, //安装失败
    INSTALLSUCCESS, //安装成功
    WAITFORUPDATE, //待更新状态
    UPDATING, //更新中
    UPDATEFAIL, //更新失败
    UPDATASUCCESS //更新成功
};

//定义工具安装状态
enum TOOLSSTATUS {
    ALL,
    INSTALLEDTOOL,
    UNINSTALLEDTOOL
};

//定义工具分类
enum TOOLCLASSIFY {
    ALLTOOLS, //所有
    SYSTEMTOOLS, //系统
    NETWORKTOOLS, //网络
    DATATOOLS, //数据
    APPMGRTOOLS, //应用管理
    DEVICETOOLS //外设
};

//定义工具信息结构体
typedef struct DefSecurityToolInfo {
    explicit DefSecurityToolInfo()
        : strPackageName("")
        , strAppName("")
        , strImagePath("")
        , strDescription("")
        , strCompany("")
        , strInallModel("")
        , strCallMethodName("")
        , bSystemTool(false)
        , bHasInstalled(false)
        , iClassify(ALLTOOLS)
    {
    }

    QString strPackageName; //安装包名称
    QString strAppName; //应用名称
    QString strImagePath; //图标名称
    QString strDescription; //应用描述
    QString strCompany;
    QString strInallModel; //安装模型
    QString strCallMethodName; //调用方法名称
    bool bSystemTool; //是否可卸载
    bool bHasInstalled; //已安装
    TOOLCLASSIFY iClassify; //应用分类
} DEFSECURITYTOOLINFO, *LPDEFSECURITYTOOLINFO;

typedef QList<DEFSECURITYTOOLINFO> DEFSECURITYTOOLINFOLIST;

Q_DECLARE_METATYPE(DEFSECURITYTOOLINFO);
Q_DECLARE_METATYPE(DEFSECURITYTOOLINFOLIST);

#endif // DEFSECURITYTOOLINFO_H
