#include "CCefClientDelegate.h"

#include "QCefViewPrivate.h"
#include "utils/CommonUtils.h"

void
CCefClientDelegate::loadingStateChanged(CefRefPtr<CefBrowser>& browser,
                                        bool isLoading,
                                        bool canGoBack,
                                        bool canGoForward)
{
  if (!IsValidBrowser(browser))
    return;

  emit pCefViewPrivate_->q_ptr->loadingStateChanged(browser->GetIdentifier(), isLoading, canGoBack, canGoForward);
}

void
CCefClientDelegate::loadStart(CefRefPtr<CefBrowser>& browser, CefRefPtr<CefFrame>& frame, int transitionType)
{
  if (!IsValidBrowser(browser))
    return;

  auto fid = FrameIdFromCefToQt(frame->GetIdentifier());

  emit pCefViewPrivate_->q_ptr->loadStart(browser->GetIdentifier(), fid, frame->IsMain(), transitionType);
}

void
CCefClientDelegate::loadEnd(CefRefPtr<CefBrowser>& browser, CefRefPtr<CefFrame>& frame, int httpStatusCode)
{
  if (!IsValidBrowser(browser))
    return;

  auto fid = FrameIdFromCefToQt(frame->GetIdentifier());

  emit pCefViewPrivate_->q_ptr->loadEnd(browser->GetIdentifier(), fid, frame->IsMain(), httpStatusCode);
}

void
CCefClientDelegate::loadError(CefRefPtr<CefBrowser>& browser,
                              CefRefPtr<CefFrame>& frame,
                              int errorCode,
                              const std::string& errorMsg,
                              const std::string& failedUrl,
                              bool& handled)
{
  if (!IsValidBrowser(browser))
    return;

  handled = pCefViewPrivate_->handleLoadError(browser, frame, errorCode, errorMsg, failedUrl);
}
