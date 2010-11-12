#pragma once

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// Call Bacl Messages and Signtures
// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
#define WM_XMLHTTP_READYSTATE_CHANGE (WM_USER + 4)

static _ATL_FUNC_INFO OnEventInfo = {CC_STDCALL, VT_EMPTY, 0};

// CXMLHTTPEventCallBack is used for function call back
class CXMLHTTPEventCallBack
{
public:
    virtual void OnReadyStateChange(long lReadyState) { };
};
 
class CXMLHTTPEventSink : public IDispEventSimpleImpl</*nID =*/ 1, CXMLHTTPEvent, &__uuidof(MSXML::XMLDOMDocumentEvents)> 
{
public:
    CXMLHTTPEventSink(MSXML::IXMLHTTPRequest* pRequest, HWND hwndPostWindow, CXMLHTTPEventCallBack* pCallBack = NULL);
    ~CXMLHTTPEventSink();
    void __stdcall OnReadyStateChange ();

    BEGIN_SINK_MAP(CXMLHTTPEventSink)
        SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(MSXML::XMLDOMDocumentEvents), /*dispid =*/ 0, OnReadyStateChange, &OnEventInfo)
    END_SINK_MAP()

// XMLDOMDocumentEvents
private:
    MSXML::IXMLHTTPRequestPtr m_spRequest;
    CXMLHTTPEventCallBack*    m_pCallBack;
    HWND                      m_hwndPostWindow;
    DWORD                     m_dwAdviseCookie;
};
