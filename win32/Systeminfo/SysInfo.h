//------------------------------------------------------------------------------
// SysInfo.h
//    
//   This is the SysInfo class. It gets different types of system 
//   information, including hard-drives, CPU information, total system 
//   RAM, etc.... 
// 
//   Copyright (c) 2001 Paul Wendt [p-wendt@wideopenwest.com.com]
// 
#ifndef SYSINFO_H_
#define SYSINFO_H_

#include "SysInfoClasses.h"
#include "CpuInfo.h"
#include "OSInfo.h"
#include "MemoryInfo.h"
#include "SocketInfo.h"
#include "DriveInfo.h"
#include "MouseInfo.h"
#include "KeyboardInfo.h"
#include "LocaleInfo.h"
#include "MultimediaInfo.h"
#include <windows.h>

#include <string>
#include <vector>

class DLL_CLASS SysInfo
{
public:        // object creation/destruction
   SysInfo(const bool& fCpuSpeed = true, const bool& fDebugInfo = false,
           const unsigned int& unDriveTypes = DriveInfo::HARDDRIVE | DriveInfo::NETWORK,
           const int& nSockMajor = 2, const int& nSockMinor = 0);

   SysInfo(const SysInfo& source);
   SysInfo& operator=(const SysInfo& right);
   virtual ~SysInfo();

public:        
   // find operations
   virtual void determineSysInfo(const bool& fCpuSpeed = true,
                                 const unsigned int& unDriveTypes = DriveInfo::HARDDRIVE | DriveInfo::NETWORK,
                                 const int& nSockMajor = 2, const int& nSockMinor = 0);

   // CPU information
   std::string getCpuIdentification() const;
   std::string getCpuVendor() const;
   std::string getCpuSpeed() const;
   void getCpuSpeed(DWORD* pdwCpuSpeed) const;
   std::string getNumProcessors() const;
   void getNumProcessors(DWORD* pdwNumProcessors) const;
   int getCpuFamily() const;
   int getCpuModel() const;
   int getCpuStepping() const;
   bool getFeature(const DWORD& dwFeatureMask) const;
   bool getExtFeature(const DWORD& dwExtFeatureMask) const;

   // OS information
   std::string getOSDescription() const;
   OSInfo::e_OS getOSVersion() const;
   std::string getOSBuildNumber() const;
   std::string getOSPlatform() const;
   std::string getOSMinorVersion() const;
   std::string getOSServicePack() const;

   // memory information
   std::string getTotalRam() const;
   std::string getAvailRam() const;
   std::string getTotalPageFile() const;
   std::string getAvailPageFile() const;
   std::string getTotalVirtual() const;
   std::string getAvailVirtual() const;

   // socket information
   std::string getSocketVersion() const;
   std::string getHighestSocketVersion() const;
   std::string getSocketDescription() const;
   std::string getSocketSystemStatus() const;
   std::string getSocketMax() const;
   std::string getIPAddress() const;
   std::string getDomainName() const;
   std::string getSocketUdpMax() const;
   std::string getComputerName() const;
   std::string getUserName() const;

   // drive information
#if defined(SYSINFO_USEOLDINTERFACE)
   std::vector<DriveStats> const * getDriveStats() const;
#else
   const std::vector<DriveStats>& getDriveStats() const;
#endif

   // mouse information
   bool getMousePresent() const;
   bool getMouseSwapped() const;
   int getMouseThresholdX() const;
   int getMouseThresholdY() const;
   int getMouseSpeed() const;

   // keyboard information
   long getKeyboardRepeat() const;
   long getKeyboardDelay() const;

   // locale information
   int         getCodePage() const;
   std::string getCalendarType() const;
   int         getOEMCodePage() const;
   std::string getLanguage() const;
   std::string getDateFormat() const;
   std::string getCountry() const;
   int         getCountryCode() const;
   std::string getTimeFormat() const;
   std::string getCurrency() const;
   std::string getTimeFormatSpecifier() const;
   std::string getLocaleLocalLanguage() const;
   std::string getLocaleTimeZone() const;

   // multimedia information
   bool getMMIsInstalled() const;
   bool getMMHasVolCtrl() const;
   bool getMMHasSeparateLRVolCtrl() const;
   std::string getMMCompanyName() const;
   std::string getMMProductName() const;

   // debugging information
   void setDebug(const bool& fDebug);
   bool getDebug() const;
   std::string getDebugInfo() const;

protected:     // protected members
   void setCpuInfo(const CpuInfo& cpuInfo);
   void setOSInfo(const OSInfo& osInfo);
   void setMemoryInfo(const MemoryInfo& memoryInfo);
   void setSocketInfo(const SocketInfo& socketInfo);
   void setDriveInfo(const DriveInfo& driveInfo);
   void setMouseInfo(const MouseInfo& mouseInfo);
   void setKeyboardInfo(const KeyboardInfo& keyboardInfo);
   void setLocaleInfo(const LocaleInfo& localeInfo);
   void setMultimediaInfo(const MultimediaInfo& multimediaInfo);

   virtual void assign(const SysInfo& source);

private:       // attributes
   CpuInfo    m_cpuInfo;
   OSInfo     m_osInfo;
   MemoryInfo m_memoryInfo;
   SocketInfo m_socketInfo;
   DriveInfo  m_driveInfo;
   MouseInfo  m_mouseInfo;
   KeyboardInfo  m_keyboardInfo;
   LocaleInfo m_localeInfo;
   MultimediaInfo m_multimediaInfo;
   bool m_fDebugInfo;
   std::string m_strDebugInfo;
};

inline std::string SysInfo::getCpuIdentification() const { return (m_cpuInfo.getCpuIdentification()); }
inline std::string SysInfo::getCpuVendor() const { return (m_cpuInfo.getStats().getVendorId()); }
inline std::string SysInfo::getCpuSpeed() const { return (m_cpuInfo.getCpuSpeed()); }
inline void SysInfo::getCpuSpeed(DWORD* pdwCpuSpeed) const { m_cpuInfo.getCpuSpeed(pdwCpuSpeed); }
inline std::string SysInfo::getNumProcessors() const { return (m_cpuInfo.getNumProcessors()); }
inline void SysInfo::getNumProcessors(DWORD* pdwNumProcessors) const { m_cpuInfo.getNumProcessors(pdwNumProcessors); }
inline int SysInfo::getCpuFamily() const { return (m_cpuInfo.getFamily()); }
inline int SysInfo::getCpuModel() const { return (m_cpuInfo.getModel()); }
inline int SysInfo::getCpuStepping() const { return (m_cpuInfo.getStepping()); }
inline bool SysInfo::getFeature(const DWORD& dwFeatureMask) const { return (m_cpuInfo.getStats().getFeature(dwFeatureMask)); }
inline bool SysInfo::getExtFeature(const DWORD& dwExtFeatureMask) const { return (m_cpuInfo.getStats().getExtendedFeature(dwExtFeatureMask)); }
inline std::string SysInfo::getOSDescription() const { return (m_osInfo.getDescription()); }
inline OSInfo::e_OS SysInfo::getOSVersion() const { return (m_osInfo.getVersion()); }
inline std::string SysInfo::getOSBuildNumber() const { return (m_osInfo.getOSBuildNumber()); }
inline std::string SysInfo::getOSPlatform() const { return (m_osInfo.getOSPlatform()); }
inline std::string SysInfo::getOSMinorVersion() const { return (m_osInfo.getOSMinorVersion()); }
inline std::string SysInfo::getOSServicePack() const { return (m_osInfo.getOSServicePack()); }
inline std::string SysInfo::getTotalRam() const { return (m_memoryInfo.getTotalRam()); }
inline std::string SysInfo::getAvailRam() const { return (m_memoryInfo.getAvailRam()); }
inline std::string SysInfo::getTotalPageFile() const { return (m_memoryInfo.getTotalPageFile()); }
inline std::string SysInfo::getAvailPageFile() const { return (m_memoryInfo.getAvailPageFile()); }
inline std::string SysInfo::getTotalVirtual() const { return (m_memoryInfo.getTotalVirtual()); }
inline std::string SysInfo::getAvailVirtual() const { return (m_memoryInfo.getAvailVirtual()); }
inline std::string SysInfo::getSocketVersion() const { return (m_socketInfo.getVersion()); }
inline std::string SysInfo::getHighestSocketVersion() const { return (m_socketInfo.getHighestVersion()); }
inline std::string SysInfo::getSocketDescription() const { return (m_socketInfo.getDescription()); }
inline std::string SysInfo::getSocketSystemStatus() const { return (m_socketInfo.getSystemStatus()); }
inline std::string SysInfo::getSocketMax() const { return (m_socketInfo.getMax()); }
inline std::string SysInfo::getIPAddress() const { return (m_socketInfo.getIPAddress()); }
inline std::string SysInfo::getDomainName() const { return (m_socketInfo.getDomainName()); }
inline std::string SysInfo::getSocketUdpMax() const { return (m_socketInfo.getUdpMax()); }
inline std::string SysInfo::getComputerName() const { return (m_socketInfo.getComputerName()); }
inline std::string SysInfo::getUserName() const { return (m_socketInfo.getUserName()); }
#if defined(SYSINFO_USEOLDINTERFACE)
inline std::vector<DriveStats> const * SysInfo::getDriveStats() const { return (m_driveInfo.getDriveStats()); }
#else
inline const std::vector<DriveStats>& SysInfo::getDriveStats() const { return (m_driveInfo.getDriveStats()); }
#endif
inline bool SysInfo::getMousePresent() const { return (m_mouseInfo.getMousePresent()); }
inline bool SysInfo::getMouseSwapped() const { return(m_mouseInfo.getMouseSwapped()); }
inline int SysInfo::getMouseThresholdX() const { return(m_mouseInfo.getMouseThresholdX()); }
inline int SysInfo::getMouseThresholdY() const { return(m_mouseInfo.getMouseThresholdY()); }
inline int SysInfo::getMouseSpeed() const { return(m_mouseInfo.getMouseSpeed()); }
inline long SysInfo::getKeyboardRepeat() const { return(m_keyboardInfo.getKeyboardRepeat()); }
inline long SysInfo::getKeyboardDelay() const { return(m_keyboardInfo.getKeyboardDelay()); }
inline int SysInfo::getCodePage() const { return(m_localeInfo.getCodePage()); }
inline std::string SysInfo::getCalendarType() const { return(m_localeInfo.getCalendarType()); }
inline int SysInfo::getOEMCodePage() const { return(m_localeInfo.getOEMCodePage()); }
inline std::string SysInfo::getLanguage() const { return(m_localeInfo.getLanguage()); }
inline std::string SysInfo::getDateFormat() const { return(m_localeInfo.getDateFormat()); }
inline std::string SysInfo::getCountry() const { return(m_localeInfo.getCountry()); }
inline int SysInfo::getCountryCode() const { return(m_localeInfo.getCountryCode()); }
inline std::string SysInfo::getTimeFormat() const { return(m_localeInfo.getTimeFormat()); }
inline std::string SysInfo::getCurrency() const { return(m_localeInfo.getCurrency()); }
inline std::string SysInfo::getTimeFormatSpecifier() const { return(m_localeInfo.getTimeFormatSpecifier()); }
inline std::string SysInfo::getLocaleLocalLanguage() const { return(m_localeInfo.getLocaleLocalLanguage()); }
inline std::string SysInfo::getLocaleTimeZone() const { return(m_localeInfo.getLocaleTimeZone()); }
inline bool SysInfo::getMMIsInstalled() const { return(m_multimediaInfo.getMMIsInstalled()); }
inline bool SysInfo::getMMHasVolCtrl() const { return(m_multimediaInfo.getMMHasVolCtrl()); }
inline bool SysInfo::getMMHasSeparateLRVolCtrl() const { return(m_multimediaInfo.getMMHasSeparateLRVolCtrl()); }
inline std::string SysInfo::getMMCompanyName() const { return(m_multimediaInfo.getMMCompanyName()); }
inline std::string SysInfo::getMMProductName() const { return(m_multimediaInfo.getMMProductName()); }
inline void SysInfo::setDebug(const bool& fDebug) { m_fDebugInfo = fDebug; }
inline bool SysInfo::getDebug() const { return (m_fDebugInfo); }
inline std::string SysInfo::getDebugInfo() const { return (m_strDebugInfo); }

// for derived clients
inline void SysInfo::setCpuInfo(const CpuInfo& cpuInfo) { m_cpuInfo = cpuInfo; }
inline void SysInfo::setOSInfo(const OSInfo& osInfo) { m_osInfo = osInfo; }
inline void SysInfo::setMemoryInfo(const MemoryInfo& memoryInfo) { m_memoryInfo = memoryInfo; }
inline void SysInfo::setSocketInfo(const SocketInfo& socketInfo) { m_socketInfo = socketInfo; }
inline void SysInfo::setDriveInfo(const DriveInfo& driveInfo) { m_driveInfo = driveInfo; }
inline void SysInfo::setMouseInfo(const MouseInfo& mouseInfo) { m_mouseInfo = mouseInfo; }
inline void SysInfo::setKeyboardInfo(const KeyboardInfo& keyboardInfo) { m_keyboardInfo = keyboardInfo; }
inline void SysInfo::setLocaleInfo(const LocaleInfo& localeInfo) { m_localeInfo = localeInfo; }
inline void SysInfo::setMultimediaInfo(const MultimediaInfo& multimediaInfo) { m_multimediaInfo = multimediaInfo; }

#endif