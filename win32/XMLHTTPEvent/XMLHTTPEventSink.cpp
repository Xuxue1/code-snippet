#include "XMLHTTPEvent.h"

// Create an event sink callback 
CXMLHTTPEventSink::CXMLHTTPEvent(MSXML::IXMLHTTPRequest* pRequest, HWND hwndPostWindow, CXMLHTTPEventCallBack* pCallBack) 
{
    m_dwAdviseCookie = NULL;
    m_spRequest      = pRequest;
    m_pCallBack      = pCallBack;
    m_hwndPostWindow = hwndPostWindow;

    // Hook into dispatch events
    DispEventAdvise(m_spRequest);
    // add sink to xml http request
    m_spRequest->put_onreadystatechange((IDispatch*)this);
}

CXMLHTTPEventSink::~CXMLHTTPEventSink() 
{
    // Remove sink from xml http request
    m_spRequest->put_onreadystatechange(NULL);

    // unhook from dispatch events
    DispEventUnadvise(m_spRequest);

    m_pCallBack       = NULL;
    m_hwndPostWindow  = NULL;
}

// State change call back handler
void __stdcall CXMLHTTPEventSink::OnReadyStateChange( )
{
    ATLTRACE(L"CXMLHTTPEvent: ReadyStateChange = %i \n", m_spRequest->readyState);

    if (m_pCallBack)
    {
        m_pCallBack->OnReadyStateChange(m_spRequest->GetreadyState());
    }
    
    if (m_hwndPostWindow)
    {
        ::PostMessage(m_hwndPostWindow, WM_XMLHTTP_READYSTATE_CHANGE, 0, MAKELPARAM(m_spRequest->GetreadyState(), 0));
    }
}
