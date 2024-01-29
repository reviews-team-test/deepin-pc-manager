QT += core gui dbus sql dtkwidget

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = deepin-pc-manager-session-daemon
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dframeworkdbus gsettings-qt gio-unix-2.0 polkit-qt5-1

# 增加安全编译参数
QMAKE_LFLAGS += -z relro -z now -z noexecstack -pie
QMAKE_CFLAGS += -fstack-protector-all
QMAKE_CXXFLAGS += -fstack-protector-all

INCLUDEPATH += \
    ../../deepin-pc-manager/src/window/modules \
    ../../deepin-pc-manager/src/

SOURCES += \
    main.cpp \
    operatedbusdata.cpp \
    csingleteon.cpp \
    widgets/scorebar.cpp \
    widgets/fixitemwindow.cpp \
    widgets/scoreprogressbar.cpp \
    widgets/basiclistdelegate.cpp \
    widgets/dccslider.cpp \
    widgets/dccsliderannotated.cpp \
    widgets/titledslideritem.cpp \
    widgets/settingsitem.cpp \
    widgets/basiclistmodel.cpp \
    widgets/settingsgroup.cpp \
    widgets/settingsheaderitem.cpp \
    widgets/translucentframe.cpp \
    widgets/titlelabel.cpp \
    widgets/titlebuttonitem.cpp \
    widgets/switchwidget.cpp \
    widgets/defendertable.cpp \
    widgets/defendertableheaderview.cpp \
    widgets/cleaneritem.cpp \
    widgets/safetyprotectionitem.cpp \
    widgets/tipwidget.cpp \
    widgets/custompushbutton.cpp \
    widgets/updateaddressitem.cpp \
    widgets/multiselectlistview.cpp \
    widgets/menuitem.cpp \
    widgets/multicombox.cpp \
    widgets/viruswhitelistscan.cpp \
    widgets/dlistviewmulticol/dlistviewmulticoldelegate.cpp \
    widgets/dlistviewmulticol/dlistviewmulticol.cpp \
    widgets/dlistviewmulticol/dlistviewmulticolframe.cpp \
    widgets/searchlineedit/searchlineedit.cpp \
    widgets/searchlineedit/animatedlineedit.cpp \
    widgets/passwordedit.cpp \
    widgets/selectediconwidget.cpp \
    window/modules/securitytooldialog/defsecuritytoolsmnd.cpp \
    window/modules/securitytooldialog/securitytooldialoginter.cpp \
    window/modules/securitytooldialog/startupdialog/autostartmodel.cpp \
    window/modules/securitytooldialog/startupdialog/startupwidget.cpp \
    window/modules/securitytooldialog/securitytoolbackend/defsecuritytoolsbuslinemgr.cpp \
    window/modules/securitytooldialog/securitytoolbackend/installer/defsecuritytoolsbaseinstaller.cpp \
    window/modules/securitytooldialog/securitytoolbackend/installer/defsecuritytoolsdbusinstaller.cpp \
    window/modules/securitytooldialog/securitytoolbackend/installer/defsecuritytoolswineinstaller.cpp \
    window/modules/common/defenderprocinfo.cpp \
    window/modules/common/defenderprocinfolist.cpp \
    window/modules/common/trashcleanappinfo.cpp \
    window/modules/common/defenderlauncherinfo.cpp \
    window/modules/common/aes/aes.c \
    window/modules/common/aes/aesencrpyobj.cpp \
    window/modules/common/systemmessagehelper.cpp \
    window/modules/trashclean/trashcleanappinfofilter.cpp \
    window/modules/trashclean/trashcleanbrowserinfofilter.cpp \
    window/modules/authority/defenderauthority.cpp \
    window/modules/authority/defenderauthoritywrapper.cpp \
    ../../deepin-pc-manager/src/window/modules/common/invokers/invokerfactory.cpp \
    ../../deepin-pc-manager/src/window/modules/common/invokers/dbusinvoker.cpp \
    ../../deepin-pc-manager/src/window/modules/common/invokers/deepindefendersettingsInvoker.cpp \
    ../../deepin-pc-manager/src/window/modules/common/database/defenderdatabaseoperationbase.cpp \
    ../../deepin-pc-manager/src/window/modules/common/database/trashcleanuninstallappsql.cpp \
    ../../deepin-pc-manager/src/window/modules/authority/defendermoduleauthorizebase.cpp \
    ../../deepin-pc-manager/src/window/modules/common/systemsettings/systemsettings.cpp \
    ../../deepin-pc-manager/src/window/modules/common/common.cpp \
    accessible/appaccessiblebase.cpp \
    accessible/appaccessiblebutton.cpp \
    accessible/appaccessiblelabel.cpp \
    accessible/appaccessibleqabstractbutton.cpp \
    ../../deepin-pc-manager/src/window/modules/common/usbmanagercomm/usbmanagercomm.cpp \
    ../../deepin-pc-manager/src/window/modules/common/firewallcommon/firewallcommon.cpp \
    ../../deepin-pc-manager/src/window/modules/securitytools/defsecuritytoolinfo.cpp

HEADERS += \
    operatedbusdata.h \
    common.h \
    csingleteon.h \
    widgets/scorebar.h \
    widgets/fixitemwindow.h \
    widgets/scoreprogressbar.h \
    widgets/basiclistdelegate.h \
    widgets/dccslider.h \
    widgets/dccsliderannotated.h \
    widgets/titledslideritem.h \
    widgets/settingsitem.h \
    widgets/basiclistmodel.h \
    widgets/labels/normallabel.h \
    widgets/settingsgroup.h \
    widgets/settingsheaderitem.h \
    widgets/translucentframe.h \
    widgets/titlelabel.h \
    widgets/titlebuttonitem.h \
    widgets/labels/tipslabel.h \
    widgets/labels/smalllabel.h \
    widgets/labels/largelabel.h \
    widgets/switchwidget.h \
    widgets/defendertable.h \
    widgets/defendertableheaderview.h \
    widgets/cleaneritem.h \
    widgets/safetyprotectionitem.h \
    widgets/tipwidget.h \
    widgets/custompushbutton.h \
    widgets/updateaddressitem.h \
    widgets/multiselectlistview.h \
    widgets/menuitem.h \
    widgets/multicombox.h \
    widgets/viruswhitelistscan.h \
    widgets/dlistviewmulticol/dlistviewmulticoldelegate.h \
    widgets/dlistviewmulticol/dlistviewmulticolcommon.h \
    widgets/dlistviewmulticol/dlistviewmulticol.h \
    widgets/dlistviewmulticol/dlistviewmulticolframe.h \
    widgets/searchlineedit/searchlineedit.h \
    widgets/searchlineedit/animatedlineedit.h \
    widgets/passwordedit.h \
    widgets/selectediconwidget.h \
    window/namespace.h \
    window/modules/securitytooldialog/defsecuritytoolsmnd.h \
    window/modules/securitytooldialog/securitytooldialoginter.h \
    window/modules/securitytooldialog/startupdialog/autostartmodel.h \
    window/modules/securitytooldialog/startupdialog/startupwidget.h \
    window/modules/securitytooldialog/securitytoolbackend/defsecuritytoolsbuslinemgr.h \
    window/modules/securitytooldialog/securitytoolbackend/installer/defsecuritytoolsbaseinstaller.h \
    window/modules/securitytooldialog/securitytoolbackend/installer/defsecuritytoolsdbusinstaller.h \
    window/modules/securitytooldialog/securitytoolbackend/installer/defsecuritytoolswineinstaller.h \
    window/modules/common/defenderprocinfo.h \
    window/modules/common/defenderprocinfolist.h \
    window/modules/common/trashcleanappinfo.h \
    window/modules/common/defenderlauncherinfo.h \
    window/modules/common/aes/aes.h \
    window/modules/common/aes/aes.hpp \
    window/modules/common/aes/aesencrpyobj.h \
    window/modules/common/systemmessagehelper.h \
    window/modules/trashclean/trashcleanappinfofilter.h \
    window/modules/trashclean/trashcleanbrowserinfofilter.h \
    window/modules/authority/defenderauthority.h \
    window/modules/authority/defenderauthoritywrapper.h \
    ../../deepin-pc-manager/src/window/modules/common/invokers/dbusinvoker.h \
    ../../deepin-pc-manager/src/window/modules/common/invokers/invokerfactory.h  \
    ../../deepin-pc-manager/src/window/modules/common/invokers/invokerinterface.h \
    ../../deepin-pc-manager/src/window/modules/common/invokers/deepindefendersettingsInvoker.h \
    ../../deepin-pc-manager/src/window/modules/common/database/defenderdatabaseoperationbase.h \
    ../../deepin-pc-manager/src/window/modules/common/database/trashcleanuninstallappsql.h \
    ../../deepin-pc-manager/src/window/modules/authority/defendermoduleauthorizebase.h \
    ../../deepin-pc-manager/src/window/modules/common/systemsettings/systemsettings.h \
    ../../deepin-pc-manager/src/window/modules/common/common.h \
    accessible/appaccessiblelabel.h \
    accessible/appaccessiblebase.h \
    accessible/appaccessiblebutton.h \
    accessible/appaccessibleqabstrractbutton.h \
    accessible/appaccessible.h \
    ../../deepin-pc-manager/src/window/modules/common/usbmanagercomm/usbmanagercomm.h \
    ../../deepin-pc-manager/src/window/modules/common/firewallcommon/firewallcommon.h \
    ../../deepin-pc-manager/src/window/modules/securitytools/defsecuritytoolinfo.h

LIBS += -L"libprocps" -lprocps -lcrypt

# 数据处理dbus接口相关文件
datainterfacedbus.files += \
        com.deepin.pc.manager.session.daemon.xml \
        window/modules/config/securitytooldialog/com.deepin.pc.manager.securitytooldialog.xml
datainterfacedbus.header_flags += \
        -i window/modules/common/defenderprocinfolist.h \
        -i ../../deepin-pc-manager/src/window/modules/securitytools/defsecuritytoolinfo.h


DBUS_ADAPTORS += datainterfacedbus
DBUS_INTERFACES += datainterfacedbus

CONFIG(release, debug|release) {
    TRANSLATIONS = $$files($$PWD/translations/*.ts)
    #遍历目录中的ts文件，调用lrelease将其生成为qm文件
    for(tsfile, TRANSLATIONS) {
        qmfile = $$replace(tsfile, .ts$, .qm)
        system(lrelease $$tsfile -qm $$qmfile) | error("Failed to lrelease")
    }
    #将qm文件添加到安装包
    dtk_translations.path = /usr/share/$$TARGET/translations
    dtk_translations.files = $$PWD/translations/*.qm
    INSTALLS += dtk_translations
}

target.path = /usr/bin/

install_service.files += \
    $$PWD/com.deepin.pc.manager.session.daemon.service \
    $$PWD/window/modules/config/securitytooldialog/com.deepin.pc.manager.securitytooldialog.service
install_service.path = /usr/share/dbus-1/services

#install_autostart.files = ./deepin-pc-manager-session-daemon.desktop
#install_autostart.path = /etc/xdg/autostart/

INSTALLS += target install_service

DISTFILES += \
    com.deepin.pc.manager.session.daemon.xml

RESOURCES += \
    ../../deepin-pc-manager/src/window/icons/defender_icons.qrc

#DEFINES+=AES256
