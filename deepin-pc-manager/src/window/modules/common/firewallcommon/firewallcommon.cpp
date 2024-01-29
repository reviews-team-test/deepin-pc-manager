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

#include "firewallcommon.h"

// app
QDBusArgument &operator<<(QDBusArgument &argument, const FirewallApp &firewallApp)
{
    argument.beginStructure();
    argument << firewallApp.id << firewallApp.name << firewallApp.type << firewallApp.exePath << firewallApp.presetRuleId;
    argument.endStructure();
    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, FirewallApp &firewallApp)
{
    argument.beginStructure();
    argument >> firewallApp.id >> firewallApp.name >> firewallApp.type >> firewallApp.exePath >> firewallApp.presetRuleId;
    argument.endStructure();
    return argument;
}

void registerFirewallAppMetaType()
{
    qRegisterMetaType<FirewallApp>("FirewallApp");
    qDBusRegisterMetaType<FirewallApp>();
}

void registerFirewallAppListMetaType()
{
    qRegisterMetaType<FirewallAppList>("FirewallAppList");
    qDBusRegisterMetaType<FirewallAppList>();
}

//rule
QDBusArgument &operator<<(QDBusArgument &argument, const FirewallRule &rule)
{
    argument.beginStructure();
    argument << rule.id << rule.action << rule.dir << rule.protocol
             << rule.localPortRange << rule.localIpRange
             << rule.remotePortRange << rule.remoteIpRange;
    argument.endStructure();
    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, FirewallRule &rule)
{
    argument.beginStructure();
    argument >> rule.id >> rule.action >> rule.dir >> rule.protocol
        >> rule.localPortRange >> rule.localIpRange
        >> rule.remotePortRange >> rule.remoteIpRange;
    argument.endStructure();
    return argument;
}

void registerFirewallRuleMetaType()
{
    qRegisterMetaType<FirewallRule>("FirewallRule");
    qDBusRegisterMetaType<FirewallRule>();
}

void registerFirewallRuleListMetaType()
{
    qRegisterMetaType<FirewallRuleList>("FirewallRuleList");
    qDBusRegisterMetaType<FirewallRuleList>();
}

// policy
QDBusArgument &operator<<(QDBusArgument &argument, const FirewallPolicy &policy)
{
    argument.beginStructure();
    argument << policy.id << policy.name << policy.type << policy.addTime << policy.status
             << policy.app << policy.rule;
    argument.endStructure();
    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, FirewallPolicy &policy)
{
    argument.beginStructure();
    argument >> policy.id >> policy.name >> policy.type >> policy.addTime >> policy.status
        >> policy.app >> policy.rule;
    argument.endStructure();
    return argument;
}

void registerFirewallPolicyMetaType()
{
    qRegisterMetaType<FirewallPolicy>("FirewallPolicy");
    qDBusRegisterMetaType<FirewallPolicy>();
}

void registerFirewallPolicyListMetaType()
{
    qRegisterMetaType<FirewallPolicyList>("FirewallPolicyList");
    qDBusRegisterMetaType<FirewallPolicyList>();
}
