//------------------------------------------------------------------------------
// MemoryInfo.cpp
//    
//   This file contains MemoryInfo, which is basically just determines 
//   the system memory information and then stortes the results. 
//   This class COULD provide member functions that would return the
//   number of bytes instead of strings. These would probably be overloaded
//   functions that take pointer arguments.
// 
//   Copyright (c) 2001 Paul Wendt [p-wendt@wideopenwest.com]
// 
#include "MemoryInfo.h"
#include "SysUtils.h"

#include <sstream>
using namespace std;

const int MemoryInfo::MEMORY_OFFSET = 655360;

MemoryInfo::MemoryInfo()
{
   determineMemoryInfo();
}

MemoryInfo::MemoryInfo(const MemoryInfo& source)
{
   assign(source);
}

MemoryInfo& MemoryInfo::operator=(const MemoryInfo& right)
{
   if (this != &right)
   {
      assign(right);
   }

   return (*this);
}

MemoryInfo::~MemoryInfo()
{
   // nothing to do yet
}

void MemoryInfo::determineMemoryInfo()
{
   GlobalMemoryStatus(&m_stMemStatus);
}

string MemoryInfo::getTotalRam() const 
{ 
   ostringstream os;
   os << SysUtils::ByteToStr(m_stMemStatus.dwTotalPhys + MEMORY_OFFSET, 0);
   return os.str(); 
}

string MemoryInfo::getAvailRam() const 
{ 
   ostringstream os;
   os << SysUtils::ByteToStr(m_stMemStatus.dwAvailPhys + MEMORY_OFFSET);
   return os.str(); 
}

string MemoryInfo::getTotalPageFile() const 
{ 
   ostringstream os;
   os << SysUtils::ByteToStr(m_stMemStatus.dwTotalPageFile + MEMORY_OFFSET);
   return os.str(); 
}

string MemoryInfo::getAvailPageFile() const 
{ 
   ostringstream os;
   os << SysUtils::ByteToStr(m_stMemStatus.dwAvailPageFile + MEMORY_OFFSET);
   return os.str(); 
}

string MemoryInfo::getTotalVirtual() const 
{ 
   ostringstream os;
   os << SysUtils::ByteToStr(m_stMemStatus.dwTotalVirtual + MEMORY_OFFSET);
   return os.str(); 
}

string MemoryInfo::getAvailVirtual() const 
{ 
   ostringstream os;
   os << SysUtils::ByteToStr(m_stMemStatus.dwAvailVirtual + MEMORY_OFFSET);
   return os.str(); 
}

void MemoryInfo::assign(const MemoryInfo& source)
{
   m_stMemStatus = source.m_stMemStatus;
}
