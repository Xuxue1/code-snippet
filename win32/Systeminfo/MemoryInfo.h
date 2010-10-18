//------------------------------------------------------------------------------
// MemoryInfo.h
//    
//   This file contains MemoryInfo, which is basically just determines 
//   the system memory information and then stortes the results. 
//   This class COULD provide member functions that would return the
//   number of bytes instead of strings. These would probably be overloaded
//   functions that take pointer arguments.
// 
//   Copyright (c) 2001 Paul Wendt [p-wendt@wideopenwest.com]
// 
#ifndef MEMORYINFO_H_
#define MEMORYINFO_H_

#include "SysInfoClasses.h"
#include <windows.h>
#include <string>

class DLL_CLASS MemoryInfo
{
public:        // object creation/destruction
   MemoryInfo();
   MemoryInfo(const MemoryInfo& source);
   MemoryInfo& operator=(const MemoryInfo& right);
   virtual ~MemoryInfo();

public:        
   // operations
   virtual void determineMemoryInfo();

   // attribute modification
   std::string getTotalRam() const;
   void getTotalRam(DWORD* pTotalRam) const;
   std::string getAvailRam() const;
   void getAvailRam(DWORD* pAvailRam) const;
   std::string getTotalPageFile() const;
   void getTotalPageFile(DWORD* pTotalPageFile) const;
   std::string getAvailPageFile() const;
   void getAvailPageFile(DWORD* pAvailPageFile) const;
   std::string getTotalVirtual() const;
   void getTotalVirtual(DWORD* pTotalVirtual) const;
   std::string getAvailVirtual() const;
   void getAvailVirtual(DWORD* pAvailVirtual) const;

protected:     // protected members
   void setMemoryStatus(const MEMORYSTATUS& memoryStatus);

   virtual void assign(const MemoryInfo& source);

private:       // attributes
   MEMORYSTATUS m_stMemStatus;
   static const int MEMORY_OFFSET;
};

inline void MemoryInfo::getTotalRam(DWORD* pTotalRam) const { *pTotalRam = m_stMemStatus.dwTotalPhys; }
inline void MemoryInfo::getAvailRam(DWORD* pAvailRam) const { *pAvailRam = m_stMemStatus.dwAvailPhys; }
inline void MemoryInfo::getTotalPageFile(DWORD* pTotalPageFile) const { *pTotalPageFile = m_stMemStatus.dwTotalPageFile; }
inline void MemoryInfo::getAvailPageFile(DWORD* pAvailPageFile) const { *pAvailPageFile = m_stMemStatus.dwAvailPageFile; }
inline void MemoryInfo::getTotalVirtual(DWORD* pTotalVirtual) const { *pTotalVirtual = m_stMemStatus.dwTotalVirtual; }
inline void MemoryInfo::getAvailVirtual(DWORD* pAvailVirtual) const { *pAvailVirtual = m_stMemStatus.dwAvailVirtual; }

// for derived classes
inline void MemoryInfo::setMemoryStatus(const MEMORYSTATUS& memoryStatus) { m_stMemStatus = memoryStatus; }

#endif