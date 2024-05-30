#pragma once
#pragma region qt_headers
#include <QDebug>
#include <QMetaType>
#include <QRegion>
#include <QWindow>
#pragma endregion qt_headers

#include <CefViewCoreGlobal.h>

#include <QCefView.h>

#define REGISTER_METATYPE(TYPE)                                                                                        \
  static struct TYPE##_MetaTypeRegister                                                                                \
  {                                                                                                                    \
    TYPE##_MetaTypeRegister()                                                                                          \
    {                                                                                                                  \
      qRegisterMetaType<TYPE>();                                                                                       \
    }                                                                                                                  \
  } TYPE##_MetaTypeRegister;

/// <summary>
///
/// </summary>
class FunctionLogger
{
public:
  FunctionLogger(const QString& fn)
    : functionName_(fn)
  {
    qDebug() << "+++" << functionName_;
  }

  ~FunctionLogger() { qDebug() << "---" << functionName_; }

  QString functionName_;
};

#if defined(QT_DEBUG)
#define FLog() FunctionLogger __fl__(__FUNCTION__);
#else
#define FLog()
#endif

/// <summary>
///
/// </summary>
/// <param name="id"></param>
/// <returns></returns>
QCefFrameId
FrameIdFromCefToQt(const CefFrameId& id);

/// <summary>
///
/// </summary>
/// <param name="id"></param>
/// <returns></returns>
CefFrameId
FrameIdFromQtToCef(const QCefFrameId& id);
