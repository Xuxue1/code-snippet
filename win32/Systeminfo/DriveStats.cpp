//------------------------------------------------------------------------------
// DriveStats.cpp
//    
//   This class contains the DriveStats class, which is basically just 
//   a glorified structure with member accessors/mutators. 
// 
//   Copyright (c) 2001 Paul Wendt [p-wendt@wideopenwest.com]
// 
#include "DriveStats.h"
using namespace std;

DriveStats::DriveStats()
{
#if defined(SYSINFO_USEOLDINTERFACE)
   m_unType = DRIVE_UNKNOWN;
#endif
   m_strType = "Unknown";
}

DriveStats::DriveStats(const DriveStats& source)
{
   assign(source);
}

DriveStats& DriveStats::operator=(const DriveStats& right)
{
   if (this != &right)
   {
      assign(right);
   }

   return (*this);
}

DriveStats::~DriveStats()
{
   // nothing to do yet
}

void DriveStats::assign(const DriveStats& source)
{
#if defined(SYSINFO_USEOLDINTERFACE)
   m_unType = source.m_unType;
#endif
   m_strType = source.m_strType;
   m_strName = source.m_strName;
   m_strTotalSpace = source.m_strTotalSpace;
   m_strFreeSpace = source.m_strFreeSpace;
   m_strVolumeName = source.m_strVolumeName;
   m_strSerialNumber = source.m_strSerialNumber;
   m_strFileSystemType = source.m_strFileSystemType;
}
