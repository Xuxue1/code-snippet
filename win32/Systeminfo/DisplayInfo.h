//------------------------------------------------------------------------------
// DisplayInfo.h
//    
//   This file contains the class DisplayInfo. It contains information
//   regarding all display adaptors on a system, such as memory and all
//   available display resolutions/refresh rates.
// 
//   Copyright (c) 2001 Paul Wendt [p-wendt@wideopenwest.com]
// 
#ifndef DISPLAYINFO_H_
#define DISPLAYINFO_H_

#include "SysInfoClasses.h"
#include <string>

class DLL_CLASS DisplayInfo
{
public:        // object creation/destruction
   DisplayInfo();
   DisplayInfo(const DisplayInfo& source);
   DisplayInfo& operator=(const DisplayInfo& right);
   virtual ~DisplayInfo();

public:        // attribute modification
   virtual void determineDisplayInfo();

protected:     // protected members
   void assign(const DisplayInfo& source);

private:       // attributes
};

#endif