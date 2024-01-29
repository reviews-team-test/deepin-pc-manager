#ifndef DEFSECURITYTOOLSWINEINSTALLER_H
#define DEFSECURITYTOOLSWINEINSTALLER_H

#include "defsecuritytoolsbaseinstaller.h"

class DefSecurityToolsWineInstaller : public DefSecurityToolsBaseInstaller
{
    Q_OBJECT
public:
    explicit DefSecurityToolsWineInstaller(QObject *parent = nullptr);
    ~DefSecurityToolsWineInstaller() override;

public:
    virtual void showtool(const QStringList &strParams) override;
};

#endif // DEFSECURITYTOOLSWINEINSTALLER_H
