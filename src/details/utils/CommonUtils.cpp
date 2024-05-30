#include "CommonUtils.h"

QCefFrameId
FrameIdFromCefToQt(const CefFrameId& id)
{
#if CEF_VERSION_MAJOR < 122
  return id;
#else
  return QCefFrameId::fromStdString(id.ToString());
#endif
}

CefFrameId
FrameIdFromQtToCef(const QCefFrameId& id)
{
#if CEF_VERSION_MAJOR < 122
  return id;
#else
  return CefFrameId(id.toStdString());
#endif
}
