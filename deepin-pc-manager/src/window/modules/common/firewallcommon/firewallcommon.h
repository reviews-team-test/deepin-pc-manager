// Copyright (C) 2019 ~ 2021 UnionTech Software Technology Co., Ltd.
// SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QtCore/QString>
#include <QtDBus/QtDBus>
#include <QDBusMetaType>
#include <QtCore/QList>

#define FIREWALL_APP_TYPE_NORMAL 0 // 防火墙应用信息-类型-普通
#define FIREWALL_APP_TYPE_PRESET 1 // 防火墙应用信息-类型-预置

#define FIREWALL_RULE_ACTION_ACCEPT 0 // 防火墙规则动作允许
#define FIREWALL_RULE_ACTION_DROP 1 // 防火墙规则动作拒绝
#define FIREWALL_RULE_DIR_OUT_AND_IN 0
#define FIREWALL_RULE_DIR_OUT 1
#define FIREWALL_RULE_DIR_IN 2

#define FIREWALL_POLICY_TYPE_PUBLIC 0 // 防火墙策略信息-类型-公网
#define FIREWALL_POLICY_TYPE_PRIVATE 1 // 防火墙策略信息-类型-专网
#define FIREWALL_POLICY_TYPE_CUSTOMIZED 2 // 防火墙策略信息-类型-自定义

// 防火墙运行状态
#define FIREWALL_STATUS_NORMAL 0 // 正常
#define FIREWALL_STATUS_BUSY 1 // 忙碌

// iptables链
#define FIREWALL_IPTABLES_CHAIN_IN "INPUT" // iptables链 - 进站
#define FIREWALL_IPTABLES_CHAIN_OUT "OUTPUT" // iptables链 - 出站
#define FIREWALL_IPTABLES_CUSTOMIZED_CHAIN_IN "IN_DEFENDER" // iptables自定义链 - 进站
#define FIREWALL_IPTABLES_CUSTOMIZED_CHAIN_OUT "OUT_DEFENDER" // iptables自定义链 - 出站

// 错误码记录
#define IPTABLES_NO_ERROR 0
#define IPTABLES_IN_CREATE_FAILE 1
#define IPTABLES_IN_ADD_FAILE 2
#define IPTABLES_OUT_CREATE_FAILE 3
#define IPTABLES_OUT_ADD_FAILE 4
#define IPTABLES_CLEAR_FAILE 5

// 防火墙策略应用错误码
#define FIREWALL_ERR_TYPE_NO_ERROR 0
#define FIREWALL_ERR_TYPE_CMD_EXEC_FAILED -1

enum IpPortType { Local = 0,
                  Remote };

struct FirewallApp {
    uint id;
    QString name;
    int type;
    QString exePath;
    uint presetRuleId;
    bool operator!=(const FirewallApp &firewallApp)
    {
        return (this->id != firewallApp.id);
    }
    FirewallApp()
    {
        id = 0;
        type = FIREWALL_APP_TYPE_NORMAL;
        presetRuleId = 0;
    }
};
Q_DECLARE_METATYPE(FirewallApp);
typedef QList<FirewallApp> FirewallAppList;
Q_DECLARE_METATYPE(FirewallAppList);

struct FirewallRule {
    uint id;
    int action; // 0-拒绝，1-允许
    int dir; // 0-出站，1-入站，2-出入站
    QString protocol;
    QString localPortRange;
    QString localIpRange;
    QString remotePortRange;
    QString remoteIpRange;
    bool operator!=(const FirewallRule &rule)
    {
        return !(this->id == rule.id);
    }
    FirewallRule()
    {
        id = 0;
        action = FIREWALL_RULE_ACTION_ACCEPT;
        dir = FIREWALL_RULE_DIR_OUT_AND_IN;
    }
};
Q_DECLARE_METATYPE(FirewallRule);
typedef QList<FirewallRule> FirewallRuleList;
Q_DECLARE_METATYPE(FirewallRuleList);

struct FirewallPolicy {
    uint id;
    QString name;
    int type;
    QString addTime; // 上次修改的时间
    bool status; // 策略启用状态，true-启用
    FirewallApp app;
    FirewallRule rule;
    bool operator!=(const FirewallPolicy &policy)
    {
        return id != policy.id;
    }
    bool operator==(const FirewallPolicy &policy)
    {
        return id == policy.id;
    }
    FirewallPolicy()
    {
        id = 0;
        type = FIREWALL_POLICY_TYPE_CUSTOMIZED;
        status = true;
    }
};
Q_DECLARE_METATYPE(FirewallPolicy);
typedef QList<FirewallPolicy> FirewallPolicyList;
Q_DECLARE_METATYPE(FirewallPolicyList);

// app
QDBusArgument &operator<<(QDBusArgument &argument, const FirewallApp &firewallApp);
const QDBusArgument &operator>>(const QDBusArgument &argument, FirewallApp &firewallApp);

void registerFirewallAppMetaType();
void registerFirewallAppListMetaType();

// rule
QDBusArgument &operator<<(QDBusArgument &argument, const FirewallRule &rule);
const QDBusArgument &operator>>(const QDBusArgument &argument, FirewallRule &rule);

void registerFirewallRuleMetaType();
void registerFirewallRuleListMetaType();

// policy
QDBusArgument &operator<<(QDBusArgument &argument, const FirewallPolicy &policy);
const QDBusArgument &operator>>(const QDBusArgument &argument, FirewallPolicy &policy);

void registerFirewallPolicyMetaType();
void registerFirewallPolicyListMetaType();
