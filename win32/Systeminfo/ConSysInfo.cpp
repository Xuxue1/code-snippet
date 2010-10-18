#include "SysInfo.h"

#include <string>
#include <iostream>

using namespace std;

void main(int argc, char* argv[])
{
   bool fShowDebugStatements = false;
   bool fPause = true;
   bool fCpuInfo = true;
   bool fCpuFeatures = true;
   bool fOsInfo = true;
   bool fMemoryInfo = true;
   bool fSocketInfo = true;
   bool fDriveInfo = true;
   bool fMouseInfo = true;
   bool fKeyboardInfo = true;
   bool fLocaleInfo = true;
   bool fMultimediaInfo = true;

   if (argc == 2)
   {
      string strOption = argv[1];
      if ((strOption == "-?") || (strOption == "?"))
      {
         cout << "-------------------------------------------------------------------------------" << endl;
         cout << "                       ConSysInfo.exe  (c)2001 Paul Wendt                      " << endl;
         cout << "-------------------------------------------------------------------------------" << endl;
         cout <<                                                                                      endl;
         cout << "  ConSysInfo may be run with the following options:                            " << endl;
         cout << "                                                                               " << endl;
         cout << "       -debug -nopause -nocpuinfo -nocpufeatures -noosinfo -nomemoryinfo       " << endl;
         cout << "       -nosocketinfo -nodriveinfo -nomouseinfo -nokeyboardinfo -nolocaleinfo   " << endl;
         cout << "       -nomultimediainfo -?                                                    " << endl;
         cout << "                                                                               " << endl;
         cout << "-------------------------------------------------------------------------------" << endl;
         cout << endl;
         return;
      }
   }

   for (int j = 1; j < argc; j++)
   {
      string strOption = argv[j];
      if (strOption == "-debug")
      {
         fShowDebugStatements = true;
      }
      else if (strOption == "-nopause")
      {
         fPause = false;
      }
      else if (strOption == "-nocpuinfo")
      {
         fCpuInfo = false;
      }
      else if (strOption == "-nocpufeatures")
      {
         fCpuFeatures = false;
      }
      else if (strOption == "-noosinfo")
      {
         fOsInfo = false;
      }
      else if (strOption == "-nomemoryinfo")
      {
         fMemoryInfo = false;
      }
      else if (strOption == "-nosocketinfo")
      {
         fSocketInfo = false;
      }
      else if (strOption == "-nodriveinfo")
      {
         fDriveInfo = false;
      }
      else if (strOption == "-nomouseinfo")
      {
         fMouseInfo = false;
      }
      else if (strOption == "-nokeyboardinfo")
      {
         fKeyboardInfo = false;
      }
      else if (strOption == "-nolocaleinfo")
      {
         fLocaleInfo = false;
      }
      else if (strOption == "-nomultimediainfo")
      {
         fMultimediaInfo = false;
      }
   }

   SysInfo sysInfo(true, fShowDebugStatements);

   if (fCpuInfo)
   {
      cout << "---------------------" << endl;
      cout << "PROCESSOR INFORMATION" << endl;
      cout << "---------------------" << endl;
      cout << "CPU String:     " << sysInfo.getCpuIdentification() << endl;
      cout << "CPU Speed:      " << sysInfo.getCpuSpeed() << endl;
      cout << "Number of CPUs: " << sysInfo.getNumProcessors() << endl;
      cout << "Family:         " << sysInfo.getCpuFamily() << endl;
      cout << "Model:          " << sysInfo.getCpuModel() << endl;
      cout << "Stepping:       " << sysInfo.getCpuStepping() << endl;
      cout << endl;

      if (fPause)
      {
         system("pause");
         system("cls");
      }
   }

   if (fCpuFeatures)
   {
      cout << "------------------" << endl;
      cout << "PROCESSOR FEATURES" << endl;
      cout << "------------------" << endl;
      cout << "FPU:     " << sysInfo.getFeature(FPU_FLAG)  << "              " << "CMOV:    " << sysInfo.getFeature(CMOV_FLAG) << endl;
      cout << "VME:     " << sysInfo.getFeature(VME_FLAG)  << "              " << "PAT:     " << sysInfo.getFeature(PAT_FLAG) << endl;
      cout << "DE:      " << sysInfo.getFeature(DE_FLAG)   << "              " << "PSE36:   " << sysInfo.getFeature(PSE36_FLAG) << endl;
      cout << "PSE:     " << sysInfo.getFeature(PSE_FLAG)  << "              " << "PSNUM:   " << sysInfo.getFeature(PSNUM_FLAG) << endl;
      cout << "TSC:     " << sysInfo.getFeature(TSC_FLAG)  << "              " << "CLFLUSH: " << sysInfo.getFeature(CLFLUSH_FLAG) << endl; 
      cout << "MSR:     " << sysInfo.getFeature(MSR_FLAG)  << "              " << "DTS:     " << sysInfo.getFeature(DTS_FLAG) << endl;
      cout << "PAE:     " << sysInfo.getFeature(PAE_FLAG)  << "              " << "ACPI:    " << sysInfo.getFeature(ACPI_FLAG) << endl;
      cout << "MCE:     " << sysInfo.getFeature(MCE_FLAG)  << "              " << "MMX:     " << sysInfo.getFeature(MMX_FLAG) << endl;
      cout << "CX8:     " << sysInfo.getFeature(CX8_FLAG)  << "              " << "FXSR:    " << sysInfo.getFeature(FXSR_FLAG) << endl;
      cout << "APIC:    " << sysInfo.getFeature(APIC_FLAG) << "              " << "SSE:     " << sysInfo.getFeature(SSE_FLAG) << endl;
      cout << "SEP:     " << sysInfo.getFeature(SEP_FLAG)  << "              " << "SSE2:    " << sysInfo.getFeature(SSE2_FLAG) << endl;
      cout << "MTRR:    " << sysInfo.getFeature(MTRR_FLAG) << "              " << "SS:      " << sysInfo.getFeature(SS_FLAG) << endl;
      cout << "PGE:     " << sysInfo.getFeature(PGE_FLAG)  << "              " << "TM:      " << sysInfo.getFeature(TM_FLAG) << endl;
      cout << "MCA:     " << sysInfo.getFeature(MCA_FLAG) << endl;
      cout << "3dNow!:  " << sysInfo.getExtFeature(HAS3DNOW_FLAG) << "              " << "3dNow!Ex:" << sysInfo.getExtFeature(EXT3DNOW_FLAG) << endl;
      cout << "SSE MMX: " << sysInfo.getExtFeature(SSEMMX_FLAG) << endl;
      cout << endl;

      if (fPause)
      {
         system("pause");
         system("cls");
      }
   }
   
   if (fOsInfo)
   {
      cout << "--------------" << endl;
      cout << "OS INFORMATION" << endl;
      cout << "--------------" << endl;
      cout << "OS:            " << sysInfo.getOSDescription() << endl;
      cout << "BuildNumber:   " << sysInfo.getOSBuildNumber() << endl;
      cout << "Platform:      " << sysInfo.getOSPlatform() << endl;
      cout << "MinorVersion:  " << sysInfo.getOSMinorVersion() << endl;
      cout << "ServicePack:   " << sysInfo.getOSServicePack() << endl;
      cout << endl;
   }

   if (fMemoryInfo)
   {
      cout << "------------------" << endl;
      cout << "MEMORY INFORMATION" << endl;
      cout << "------------------" << endl;
      cout << "Total:         " << sysInfo.getTotalRam() << endl;
      cout << "Available:     " << sysInfo.getAvailRam() << endl;
      cout << "Total Page:    " << sysInfo.getTotalPageFile() << endl;
      cout << "Avail Page:    " << sysInfo.getAvailPageFile() << endl;
      cout << "Total Virtual: " << sysInfo.getTotalVirtual() << endl;
      cout << "Avail Virtual: " << sysInfo.getAvailVirtual() << endl;
      cout << endl;
   }

   if (fPause && (fMemoryInfo || fOsInfo))
   {
      system("pause");
      system("cls");
   }

   if (fSocketInfo)
   {
      cout << "------------------" << endl;
      cout << "SOCKET INFORMATION" << endl;
      cout << "------------------" << endl;
      cout << "Version:       " << sysInfo.getSocketVersion() << endl;
      cout << "Highest Ver:   " << sysInfo.getHighestSocketVersion() << endl;
      cout << "Description:   " << sysInfo.getSocketDescription() << endl;
      cout << "System Status: " << sysInfo.getSocketSystemStatus() << endl;
      cout << "Max:           " << sysInfo.getSocketMax() << endl;
      cout << "IP Address:    " << sysInfo.getIPAddress() << endl;
      cout << "Domain Name:   " << sysInfo.getDomainName() << endl;
      cout << "UDP Max:       " << sysInfo.getSocketUdpMax() << endl; 
      cout << "Computer Name: " << sysInfo.getComputerName() << endl;
      cout << "User Name:     " << sysInfo.getUserName() << endl;
      cout << endl;
   }

   if (fDriveInfo)
   {
      cout << "-----------------" << endl;
      cout << "DRIVE INFORMATION" << endl;
      cout << "-----------------" << endl;
#if defined(SYSINFO_USEOLDINTERFACE)
      vector<DriveStats> const* pvDriveStats = sysInfo.getDriveStats();
      vector<DriveStats>::const_iterator i;
      for (i = pvDriveStats->begin(); i != pvDriveStats->end(); i++)
#else
      const vector<DriveStats>& rvDriveStats = sysInfo.getDriveStats();
      for (vector<DriveStats>::const_iterator i = rvDriveStats.begin();
           i != rvDriveStats.end();
           ++i)
#endif
      {
         cout << "Name: " << i->getName() << " Type: " << i->getType() 
              << " Total: " << i->getTotalSpace() << " Free: " << i->getFreeSpace() 
              << " File System: " << i->getFileSystemType() << endl;
      }
      cout << endl;
   }

   if (fPause && (fSocketInfo || fDriveInfo))
   {
      system("pause");
      system("cls");
   }

   if (fMouseInfo)
   {
      cout << "-----------------" << endl;
      cout << "MOUSE INFORMATION" << endl;
      cout << "-----------------" << endl;
      cout << "Present:       " << sysInfo.getMousePresent() << endl;
      cout << "Btn swapped:   " << sysInfo.getMouseSwapped() << endl;
      cout << "Threshold X:   " << sysInfo.getMouseThresholdX() << endl;
      cout << "Threshold Y:   " << sysInfo.getMouseThresholdY() << endl;
      cout << "Speed:         " << sysInfo.getMouseSpeed() << endl;
      cout << endl;
   }

   if (fKeyboardInfo)
   {
      cout << "--------------------" << endl;
      cout << "KEYBOARD INFORMATION" << endl;
      cout << "--------------------" << endl;
      cout << "Repeat:        " << sysInfo.getKeyboardRepeat() << endl;
      cout << "Delay:         " << sysInfo.getKeyboardDelay() << endl;
      cout << endl;
   }

   if (fPause && (fMouseInfo || fKeyboardInfo))
   {
      system("pause");
      system("cls");
   }

   if (fLocaleInfo)
   {
      cout << "------------------" << endl;
      cout << "LOCALE INFORMATION" << endl;
      cout << "------------------" << endl;
      cout << "CodePage:            " << sysInfo.getCodePage() << endl;
      cout << "CalendarType:        " << sysInfo.getCalendarType() << endl;
      cout << "OEMCodePage:         " << sysInfo.getOEMCodePage() << endl;
      cout << "Language:            " << sysInfo.getLanguage() << endl;
      cout << "DateFormat:          " << sysInfo.getDateFormat() << endl;
      cout << "Country:             " << sysInfo.getCountry() << endl;
      cout << "CountryCode:         " << sysInfo.getCountryCode() << endl;
      cout << "TimeFormat:          " << sysInfo.getTimeFormat() << endl;
      cout << "Currency:            " << sysInfo.getCurrency() << endl;
      cout << "TimeFormatSpecifier: " << sysInfo.getTimeFormatSpecifier() << endl;
      cout << "LocalLanguage:       " << sysInfo.getLocaleLocalLanguage() << endl;
      cout << "TimeZone:            " << sysInfo.getLocaleTimeZone() << endl;
      cout << endl;

      if (fPause)
      {
         system("pause");
         system("cls");
      }
   }

   if (fMultimediaInfo)
   {
      cout << "----------------------" << endl;
      cout << "MULTIMEDIA INFORMATION" << endl;
      cout << "----------------------" << endl;
      cout << "IsInstalled:            " << sysInfo.getMMIsInstalled() << endl;
      cout << "HasVolumeControl:       " << sysInfo.getMMHasVolCtrl() << endl;
      cout << "HasSeparateRLVolCtrl:   " << sysInfo.getMMHasSeparateLRVolCtrl() << endl;
      cout << "Companyname:            " << sysInfo.getMMCompanyName() << endl;
      cout << "Productname:            " << sysInfo.getMMProductName() << endl;
      cout << endl;

      if (fPause)
      {
         system("pause");
         system("cls");
      }
   }

   if (fShowDebugStatements)
   {
      cout << "---------------------" << endl;
      cout << "DEBUGGING INFORMATION" << endl;
      cout << "---------------------" << endl;
      cout << sysInfo.getDebugInfo();
      cout << endl;
      
      if (fPause)
      {
         system("pause");
         system("cls");
      }
   }
}  
