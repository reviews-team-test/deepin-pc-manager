QT += core gui dbus sql dtkwidget svg concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = deepin-pc-manager
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
CONFIG += console
PKGCONFIG += gsettings-qt dframeworkdbus polkit-qt5-1 gio-unix-2.0

# 增加安全编译参数
QMAKE_LFLAGS += -z relro -z now -z noexecstack -pie
QMAKE_CFLAGS += -fstack-protector-all
QMAKE_CXXFLAGS += -fstack-protector-all

INCLUDEPATH += src \
    ../deepin-pc-manager-server/deepin-pc-manager-system-daemon/usbconnection \
    ../deepin-pc-manager-server/deepin-pc-manager-session-daemon/window/modules/common

include($$PWD/src/window/modules/modules.pri)

isEmpty(VERSION) {
    VERSION = 2.0.4
}
DEFINES += QMAKE_TARGET=\\\"$$TARGET\\\" QMAKE_VERSION=\\\"$$VERSION\\\"

SOURCES += \
        src/main.cpp \
        src/window/interface/moduleinterface.cpp \
        src/window/mainwindow.cpp \
        src/window/dialogmanage.cpp \
        src/window/restartdefenderdialog.cpp \
        src/widgets/scorebar.cpp \
        src/widgets/fixitemwindow.cpp \
        src/widgets/scoreprogressbar.cpp \
        src/csingleteon.cpp \
        settings_translation.cpp \
        src/widgets/basiclistdelegate.cpp \
        src/widgets/dccslider.cpp \
        src/widgets/dccsliderannotated.cpp \
        src/widgets/titledslideritem.cpp \
        src/widgets/settingsitem.cpp \
        src/widgets/basiclistmodel.cpp \
        src/widgets/settingsgroup.cpp \
        src/widgets/settingsheaderitem.cpp \
        src/widgets/translucentframe.cpp \
        src/widgets/titlelabel.cpp \
        src/widgets/titlebuttonitem.cpp \
        src/defenderdbusservice.cpp \
        src/widgets/switchwidget.cpp \
        src/widgets/defendertable.cpp \
        src/widgets/defendertableheaderview.cpp \
        src/widgets/cleaneritem.cpp \
        src/widgets/safetyprotectionitem.cpp \
        src/widgets/tipwidget.cpp \
        src/widgets/custompushbutton.cpp \
        src/widgets/updateaddressitem.cpp \
        src/widgets/multiselectlistview.cpp \
        src/widgets/menuitem.cpp \
        src/widgets/multicombox.cpp \
        src/widgets/viruswhitelistscan.cpp \
        src/widgets/dlistviewmulticol/dlistviewmulticoldelegate.cpp \
        src/widgets/dlistviewmulticol/dlistviewmulticol.cpp \
        src/widgets/dlistviewmulticol/dlistviewmulticolframe.cpp \
        src/widgets/searchlineedit/searchlineedit.cpp \
        src/widgets/searchlineedit/animatedlineedit.cpp \
        src/widgets/passwordedit.cpp \
        src/widgets/selectediconwidget.cpp \
        src/widgets/avcpulimitation.cpp \
        src/widgets/ddropdown.cpp \
        src/accessible/appaccessiblebase.cpp \
        src/accessible/appaccessiblebutton.cpp \
        src/accessible/appaccessiblelabel.cpp \
        src/accessible/appaccessibleqabstractbutton.cpp


HEADERS +=  \
        src/window/namespace.h \
        src/window/interface/frameproxyinterface.h \
        src/window/interface/moduleinterface.h \
        src/window/mainwindow.h \
        src/window/restartdefenderdialog.h \
        src/window/utils.h \
        src/window/dialogmanage.h \
        src/widgets/scorebar.h \
        src/widgets/fixitemwindow.h \
        src/widgets/scoreprogressbar.h \
        src/csingleteon.h \
        src/widgets/basiclistdelegate.h \
        src/widgets/dccslider.h \
        src/widgets/dccsliderannotated.h \
        src/widgets/titledslideritem.h \
        src/widgets/settingsitem.h \
        src/widgets/basiclistmodel.h \
        src/widgets/labels/normallabel.h \
        src/widgets/settingsgroup.h \
        src/widgets/settingsheaderitem.h \
        src/widgets/translucentframe.h \
        src/widgets/titlelabel.h \
        src/widgets/titlebuttonitem.h \
        src/widgets/labels/tipslabel.h \
        src/widgets/labels/smalllabel.h \
        src/widgets/labels/largelabel.h \
        src/defenderdbusservice.h \
        src/widgets/switchwidget.h \
        src/widgets/defendertable.h \
        src/widgets/defendertableheaderview.h \
        src/widgets/cleaneritem.h \
        src/widgets/safetyprotectionitem.h \
        src/widgets/tipwidget.h \
        src/widgets/custompushbutton.h \
        src/widgets/updateaddressitem.h \
        src/widgets/multiselectlistview.h \
        src/widgets/menuitem.h \
        src/widgets/multicombox.h \
        src/widgets/viruswhitelistscan.h \
        src/widgets/dlistviewmulticol/dlistviewmulticoldelegate.h \
        src/widgets/dlistviewmulticol/dlistviewmulticolcommon.h \
        src/widgets/dlistviewmulticol/dlistviewmulticol.h \
        src/widgets/dlistviewmulticol/dlistviewmulticolframe.h \
        src/widgets/searchlineedit/searchlineedit.h \
        src/widgets/searchlineedit/animatedlineedit.h \
        src/widgets/passwordedit.h \
        src/widgets/selectediconwidget.h \
        src/widgets/avcpulimitation.h \
        src/widgets/ddropdown.h \
        src/accessible/appaccessiblelabel.h \
        src/accessible/appaccessiblebase.h \
        src/accessible/appaccessiblebutton.h \
        src/accessible/appaccessibleqabstrractbutton.h \
        src/accessible/appaccessible.h


isEmpty(PREFIX){
    PREFIX = /usr
}

# 删除所有的生成的qm文件
system(rm $$PWD/translations/*.qm)
CONFIG(release, debug|release) {
    message("current dir:" + $$PWD)
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

# 界面dbus接口相关文件
hmiscreendbus.files = com.deepin.pc.manager.xml
DBUS_ADAPTORS += hmiscreendbus
DBUS_INTERFACES += hmiscreendbus

target.path = $${PREFIX}/bin/

install_gsettings.files = ./schemas/*.gschema.xml
install_gsettings.path = $${PREFIX}/share/glib-2.0/schemas/

install_desktop.files = ./deepin-pc-manager.desktop
install_desktop.path = $${PREFIX}/share/applications

install_service.files = ./com.deepin.pc.manager.service
install_service.path = $${PREFIX}/share/dbus-1/services

install_docs.files = ./docs/*
install_docs.path = $${PREFIX}/share/dman/deepin-denfender

icon.path = /usr/share/icons/hicolor/scalable/apps
icon.files = $$PWD/src/window/icons/icons/deepin-defender.svg

polkit.path = /usr/share/polkit-1/actions
polkit.files = $$PWD/com.deepin.pc-manager.policy

# 安装垃圾清理白名单配置文件
whitepaths.path = /usr/share/deepin-pc-manager
whitepaths.files = $$PWD/cleanerwhite.json

# 安装垃圾清理应用垃圾清单
appInfomation.path = /usr/share/deepin-pc-manager
appInfomation.files = $$PWD/appInfomation.json

# 帮助手册
manual_dir.files = $$PWD/assets/deepin-pc-manager
manual_dir.path = /usr/share/deepin-manual/manual-assets/application/

# 安装引三方应用清单
toolInfomation.path = /usr/share/deepin-pc-manager
toolInfomation.files = $$PWD/toolinfo.json

# 安装文件到某个路径
INSTALLS += target install_gsettings install_desktop install_service install_docs icon polkit  whitepaths appInfomation manual_dir toolInfomation

RESOURCES += \
    src/window/icons/defender_icons.qrc \
    defender.qrc

#设置配置文件
system($$DTK_SETTINGS -o settings_translation.cpp $$PWD/dt-settings.json)

#管理usb设备库
unix:!macx: LIBS += \
    -L$$PWD/../../../../lib/ -ludev \
    -L$$PWD/../../../../lib/ -lrt \
    -L$$PWD/../../../../lib -lcrypt

DISTFILES += \
    dt-settings.json
