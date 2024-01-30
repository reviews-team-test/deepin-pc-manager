QT += core gui dbus sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = deepin-pc-manager-system-daemon
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget dframeworkdbus gsettings-qt

# 增加安全编译参数
QMAKE_LFLAGS += -z relro -z now -z noexecstack -pie
QMAKE_CFLAGS += -fstack-protector-all
QMAKE_CXXFLAGS += -fstack-protector-all

INCLUDEPATH += \
    ../deepin-pc-manager-session-daemon/window/modules/common \
    ../../deepin-pc-manager/src/window/modules/common

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

dbus.files += \
    com.deepin.pc.manager.system.daemon.xml
dbus.header_flags += \
    -i ../deepin-pc-manager-session-daemon/window/modules/common/defenderprocinfolist.h \
    -i ../../deepin-pc-manager/src/window/modules/common/common.h

DBUS_ADAPTORS += dbus
DBUS_INTERFACES += dbus

SOURCES += \
    main.cpp \
    writedbusdata.cpp \
    disk/disk.cpp \
    localcache/securitypkgnamesql.cpp \
    localcache/settingssql.cpp \
    ../../deepin-pc-manager/src/window/modules/common/common.cpp \
    ../../deepin-pc-manager/src/window/modules/common/systemloginfo.cpp \
    ../../deepin-pc-manager/src/window/modules/common/database/defenderdatabaseoperationbase.cpp \
    ../../deepin-pc-manager/src/window/modules/common/database/trashcleanuninstallappsql.cpp \
    ../../deepin-pc-manager/src/window/modules/common/invokers/invokerfactory.cpp \
    ../../deepin-pc-manager/src/window/modules/common/invokers/dbusinvoker.cpp \
    ../../deepin-pc-manager/src/window/modules/common/invokers/deepindefendersettingsInvoker.cpp \
    ../../deepin-pc-manager/src/window/modules/common/systemsettings/systemsettings.cpp

RESOURCES +=

HEADERS += \
    writedbusdata.h \
    disk/disk.h \
    localcache/securitypkgnamesql.h \
    localcache/settingssql.h \
    ../../deepin-pc-manager/src/window/modules/common/common.h \
    ../../deepin-pc-manager/src/window/modules/common/systemloginfo.h \
    ../../deepin-pc-manager/src/window/modules/common/database/defenderdatabaseoperationbase.h \
    ../../deepin-pc-manager/src/window/modules/common/database/trashcleanuninstallappsql.h \
    ../../deepin-pc-manager/src/window/modules/common/invokers/dbusinvoker.h \
    ../../deepin-pc-manager/src/window/modules/common/invokers/invokerfactory.h  \
    ../../deepin-pc-manager/src/window/modules/common/invokers/invokerinterface.h \
    ../../deepin-pc-manager/src/window/modules/common/invokers/deepindefendersettingsInvoker.h \
    ../../deepin-pc-manager/src/window/modules/common/gsettingkey.h \
    ../../deepin-pc-manager/src/window/modules/common/systemsettings/systemsettings.h

DISTFILES += \
    com.deepin.pc.manager.system.daemon.xml \
    com.deepin.pc.manager.system.daemon.conf
message("current dir:" + $$PWD)
system_dbus_conf.files += \
    $$PWD/com.deepin.pc.manager.system.daemon.conf
system_dbus_conf.path = /usr/share/dbus-1/system.d

install_service.files += \
    $$PWD/com.deepin.pc.manager.system.daemon.service
install_service.path = /usr/share/dbus-1/system-services

target.path=/usr/bin
#systemd_service.files = deepin-pc-manager-system-daemon.service
#systemd_service.path = /lib/systemd/system/
INSTALLS += target system_dbus_conf install_service

unix:!macx: LIBS += \
    # 磁盘管理库
    -L/lib/ -lparted


INCLUDEPATH += /usr/include/parted
DEPENDPATH += /usr/include/parted
