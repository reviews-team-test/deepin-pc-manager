#include "defsecuritytoolsmnd.h"
#include "common/gsettingkey.h"

#include <DTitlebar>

#include <QHBoxLayout>
#include <QApplication>
#include <QShowEvent>
#include <QScreen>

DefSecurityToolsMnd::DefSecurityToolsMnd(QWidget *pWidget)
    : DMainWindow(pWidget)
{
    initUI();
}

DefSecurityToolsMnd::~DefSecurityToolsMnd()
{
}

void DefSecurityToolsMnd::addContent(QWidget *pWidget)
{
    QWidget *pCenterWidget = this->centralWidget();
    QHBoxLayout *pInnerLayout = qobject_cast<QHBoxLayout *>(pCenterWidget->layout());
    pInnerLayout->addWidget(pWidget);
}

void DefSecurityToolsMnd::initUI()
{
    DTitlebar *pToolBar = titlebar();
    pToolBar->setMenuVisible(false);
    QHBoxLayout *pInnerLayout = new QHBoxLayout;
    pInnerLayout->setContentsMargins(20, 20, 20, 20);
    QWidget *pWidget = new QWidget(this);
    pWidget->setAccessibleName("DefSecurityToolsMnd_centerWidget");
    pWidget->setLayout(pInnerLayout);
    setCentralWidget(pWidget);
    setWindowFlags(Qt::Dialog);
}

void DefSecurityToolsMnd::moveToCenter()
{
    QScreen *pScreen = QGuiApplication::primaryScreen();
    QPoint ptCenter = pScreen->geometry().center();
    QRect rc = geometry();
    rc.moveCenter(ptCenter);
    setGeometry(rc);
}

void DefSecurityToolsMnd::showEvent(QShowEvent *event)
{
    DMainWindow::showEvent(event);
    moveToCenter();
}
