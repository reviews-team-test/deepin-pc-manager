#include <QtGlobal>

#include "klogconfig.h"

int KLogConfig::m_slogLevel = -1;

void KLogConfig::qtLoggerMessageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
  Logger::LogLevel level;

  switch (type) {
  case QtDebugMsg:
      level = Logger::Debug;
      break;
#if QT_VERSION >= 0x050500
  case QtInfoMsg:
      level = Logger::Info;
      break;
#endif
  case QtWarningMsg:
      level = Logger::Warning;
      break;
  case QtCriticalMsg:
      level = Logger::Error;
      break;
  case QtFatalMsg:
      level = Logger::Fatal;
      break;
  default:
      level = Logger::Debug;
      break;
  }

  if (level >= m_slogLevel) {
      bool isDefaultCategory = QString::fromLatin1(context.category) == "default";
      Logger::globalInstance()->write(level, context.file, context.line, context.function, isDefaultCategory ? 0 : context.category, msg);
  }
}

KLogConfig::KLogConfig(QObject *parent) : QObject(parent)
{
    qInstallMessageHandler(qtLoggerMessageHandler);
}

//由于未定义
void KLogConfig::setFileLogLevel(int level)
{
    m_slogLevel = level;
}
