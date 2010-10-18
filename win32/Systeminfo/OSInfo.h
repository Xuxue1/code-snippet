//------------------------------------------------------------------------------
// OSInfo.h
//    
//   This file contains OSInfo. Basically, this class just determines 
//   which windows operating system is running. It also figures out service 
//   pack or build information. 
// 
//   Copyright (c) 2001 Paul Wendt [p-wendt@wideopenwest.com]
// 
#ifndef OSINFO_H_
#define OSINFO_H_

#include "SysInfoClasses.h"
#include <string>

class DLL_CLASS OSInfo
{
public:        // object creation/destruction
   OSInfo();
   OSInfo(const OSInfo& source);
   OSInfo& operator=(const OSInfo& right);
   virtual ~OSInfo();

public:
   enum e_OS { WIN95 = 0, WIN98, WINME, WIN32S, WINNT351, WINNT40, WIN2000, WINXP };

public:        // attribute modification
   e_OS getVersion() const;
   std::string getDescription() const;
   std::string getOSBuildNumber() const;
   std::string getOSPlatform() const;
   std::string getOSMinorVersion() const;
   std::string getOSServicePack() const;

protected:     // protected members
   void setVersion(const e_OS& version);
   void setDescription(const std::string& description);
   void setOSBuildNumber(const std::string& osBuildNumber);
   void setOSPlatform(const std::string& osPlatform);
   void setOSMinorVersion(const std::string& osMinorVersion);
   void setOSServicePack(const std::string& osServicePack);

   virtual void assign(const OSInfo& source);
   virtual void determineOSInfo();

private:       // attributes
   e_OS m_eVersion;
   std::string m_strDescription;
   std::string m_strOSBuildNumber;
   std::string m_strOSPlatform;
   std::string m_strOSMinorVersion;
   std::string m_strOSServicePack;

};

inline OSInfo::e_OS OSInfo::getVersion() const { return (m_eVersion); }
inline std::string OSInfo::getDescription() const { return (m_strDescription); }
inline std::string OSInfo::getOSBuildNumber() const { return (m_strOSBuildNumber); };
inline std::string OSInfo::getOSPlatform() const { return (m_strOSPlatform); };
inline std::string OSInfo::getOSMinorVersion() const { return (m_strOSMinorVersion); };
inline std::string OSInfo::getOSServicePack() const { return (m_strOSServicePack); };

// for derived classes
inline void OSInfo::setVersion(const e_OS& version) { m_eVersion = version; }
inline void OSInfo::setDescription(const std::string& description) { m_strDescription = description; }
inline void OSInfo::setOSBuildNumber(const std::string& osBuildNumber) { m_strOSBuildNumber = osBuildNumber; }
inline void OSInfo::setOSPlatform(const std::string& osPlatform) { m_strOSPlatform = osPlatform; }
inline void OSInfo::setOSMinorVersion(const std::string& osMinorVersion) { m_strOSMinorVersion = osMinorVersion; }
inline void OSInfo::setOSServicePack(const std::string& osServicePack) { m_strOSServicePack = osServicePack; }

#endif