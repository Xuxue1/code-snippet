//------------------------------------------------------------------------------
// CpuInfo.h
//    
//   This file contains the class CpuInfo. It basically determines all 
//   pertinent information for the CPU. It currently gets in-depth 
//   information for both Intel and AMD CPUs. 
//   Known Problems:
//   1) algorithm for determining CPU speed is not great; it will be updated
// 
//   Copyright (c) 2001 Paul Wendt [p-wendt@wideopenwest.com]
// 
#ifndef CPUINFO_H_
#define CPUINFO_H_

#include "SysInfoClasses.h"
#include "CpuStats.h"
#include <windows.h>
#include <string>
#include <sstream>

// this gives us multimedia timer functions -- used for CPU benchmarking
#pragma comment(lib, "winmm.lib")

class DLL_CLASS CpuInfo
{
public:        // object creation/destruction
   CpuInfo(const bool fCpuSpeed = true, const bool fDebug = false);
   CpuInfo(const CpuInfo& source);
   CpuInfo& operator=(const CpuInfo& right);
   virtual ~CpuInfo();

public:        
   // operations
   virtual void determineCpuInfo();
   virtual void determineCpuSpeed();

   void setDebug(const bool& fDebug);
   bool getDebug() const;
   std::string getDebugResults() const;

   // CPU attributes
   std::string getCpuIdentification() const;
   std::string getCpuSpeed() const;
   void getCpuSpeed(DWORD* pdwCpuSpeed) const;
   std::string getNumProcessors() const;
   void getNumProcessors(DWORD* pdwNumProcessors) const;
   DWORD getFamily() const;
   DWORD getModel() const;
   DWORD getStepping() const;
   CpuStats getStats() const;

protected:     // protected members
   virtual void assign(const CpuInfo& source);

   virtual bool determineCpuId();
   virtual void determineCpuStats(WORD wProcessorArchitecture);
 
   // this function determines which of the below can be called
   virtual DWORD determineHighestCpuId();
   virtual void determineCpuIdentification(); // eax = 1
   virtual void determineIntelCacheInfo();    // eax = 2
   virtual void determineOldIntelName(); 
   virtual void determineCeleronAndXeon(DWORD dwRegisterCache, bool* pfIsCeleron, 
                                        bool* pfIsXeon, bool fIsEax = false);

   // this function determines which of the below can be called
   virtual DWORD determineLargestExtendedFeature();
   virtual void determineExtendedFeature();   // eax = 0x80000001
   virtual void determineNameString();        // eax = 0x80000002 - 0x80000004
   virtual void determineAmdL1CacheInfo();    // eax = 0x80000005
   virtual void determineAmdL2CacheInfo();    // eax = 0x80000006

   // cpu speed
   virtual DWORD calculateCpuSpeed() const;
   virtual DWORD calculateCpuSpeedMethod2() const;
   virtual DWORD getCpuSpeedFromRegistry() const;
   virtual DWORD determineTimeStamp() const;

   void setCpuIdentification(const std::string& cpuId);
   void setCpuSpeed(const std::string& speed);
   void setNumProcessors(const std::string& numProcessors);
   void setNumProcessors(DWORD numProcessors);
   void setStats(const CpuStats& cpuStats);

private:       // attributes
   CpuStats    m_cpuStats;
   std::string m_strCpuSpeed;
   std::string m_strNumProcessors;
   bool        m_fDebug;
   std::ostringstream m_osDebugResults;

   static const int BRANDTABLESIZE;
};


inline void CpuInfo::setDebug(const bool& fDebug) { m_fDebug = fDebug; }
inline bool CpuInfo::getDebug() const { return (m_fDebug); }
inline std::string CpuInfo::getDebugResults() const { return (m_osDebugResults.str()); }
inline std::string CpuInfo::getCpuIdentification() const { return (m_cpuStats.getName()); }
inline void CpuInfo::getCpuSpeed(DWORD* pdwCpuSpeed) const { *pdwCpuSpeed = atoi(m_strCpuSpeed.c_str()); }
inline void CpuInfo::getNumProcessors(DWORD* pdwNumProcessors) const { *pdwNumProcessors = atoi(m_strNumProcessors.c_str()); }
inline std::string CpuInfo::getNumProcessors() const { return (m_strNumProcessors); }
inline std::string CpuInfo::getCpuSpeed() const { return (m_strCpuSpeed); }
inline DWORD CpuInfo::getFamily() const { return (m_cpuStats.getFamily()); }
inline DWORD CpuInfo::getModel() const { return (m_cpuStats.getModel()); }
inline DWORD CpuInfo::getStepping() const { return (m_cpuStats.getStepping()); }
inline CpuStats CpuInfo::getStats() const { return (m_cpuStats); }

// for derived classes
inline void CpuInfo::setCpuIdentification(const std::string& cpuId) { m_cpuStats.setName(cpuId); }
inline void CpuInfo::setCpuSpeed(const std::string& speed) { m_strCpuSpeed = speed; }
inline void CpuInfo::setNumProcessors(const std::string& numProcessors) { m_strNumProcessors = numProcessors; }
inline void CpuInfo::setNumProcessors(DWORD numProcessors) { std::ostringstream os; os << numProcessors; setNumProcessors(os.str()); }
inline void CpuInfo::setStats(const CpuStats& cpuStats) { m_cpuStats = cpuStats; }


#endif