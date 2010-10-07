#include<stdio.h>

//TODO: Change the path here if your Msxml.dll file is in a different location.

// for xml 4.0
#import "c:\winnt\system32\msxml4.dll"
using namespace MSXML2;

// for xml 2.0
// #import "c:\winnt\system32\msxml2.dll"
// using namespace MSXML;

int main(int argc, char* argv[])
{
   CoInitialize(NULL);
   try
   {
//TODO: Change the line below to reflect your server.
      bstr_t yourServerName = "myserver1";

      bstr_t sUrl = "http://" + yourServerName +
        "/public/testfolder/test.doc";
      bstr_t sMethod = "PROPPATCH";

//TODO: Change the 2 lines below to reflect your user name and password.
      _variant_t vUser = L"myserver1\\User1";
      _variant_t vPassword = L"password";

// for xml 4.0
      MSXML2::IXMLHTTPRequestPtr pXMLHttpReq=NULL;
      // for xml 2.0
      MSXML::IXMLHTTPRequestPtr pXMLHttpReq=NULL;

      HRESULT hr = ::CoCreateInstance(
            CLSID_XMLHTTPRequest,
                        NULL,
                        CLSCTX_INPROC_SERVER,
            IID_IXMLHttpRequest,
                       (LPVOID*)&pXMLHttpReq);
      if (S_OK != hr)
      {
         printf("XML Http Request pointer creation failed\n");
         return 0;
      }

      // Call open function.
      _variant_t vAsync = (bool)FALSE;
      pXMLHttpReq->open(sMethod,
        sUrl,
        vAsync,
        vUser,
        vPassword);

      pXMLHttpReq->setRequestHeader((bstr_t)"Content-Type",
         (bstr_t)"text/xml");
      bstr_t sReq;
      sReq =  "<?xml version='1.0'?>";
      sReq = sReq + "<a:propertyupdate xmlns:a='DAV:' xmlns:o=" +
         "'urn:schemas-microsoft-com:office:office'>";
      sReq = sReq + "<a:set><a:prop>";
      sReq = sReq + "<o:Author>someone else</o:Author>";
      sReq = sReq + "</a:prop></a:set></a:propertyupdate>";

      // Send the request to set the search criteria.
      pXMLHttpReq->send(sReq);

      // OK, get response.
      long lStatus;
      pXMLHttpReq->get_status(&lStatus);

      printf("\n~~~~~~~~\n%d\n", lStatus);
      BSTR bstrResp;
      pXMLHttpReq->get_statusText(&bstrResp);
      printf("\n~~~~~~~~\n%s\n", (char*)(bstr_t)bstrResp);

      _bstr_t bstrAllHeaders;
      bstrAllHeaders = pXMLHttpReq->getAllResponseHeaders();
      printf("\n~~~~~~~~\n%s\n", (char*)bstrAllHeaders);

      BSTR bstrResponseText;
      pXMLHttpReq->get_responseText(&bstrResponseText);
      printf("\n~~~~~~~~\n%s\n", (char*)(bstr_t)bstrResponseText);
   }
   catch(_com_error &e)
   {
      printf("Error\a\a\n\tCode = %08lx\n"
         "\tCode meaning = %s\tSource = %s\n\tDescription = %s\n",
         e.Error(),
         e.ErrorMessage(),
         (char*)e.Source(),
         (char*)e.Description());
   }

   CoUninitialize();

   return 0;
}

