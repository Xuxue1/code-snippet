#include "DisplayInfo.h"
#include <windows.h>

using namespace std;
/*

DisplayInfo::DisplayInfo()
{
   // nothing to do yet
}

DisplayInfo::DisplayInfo(const DisplayInfo& source)
{
   assign(source);
}

DisplayInfo& DisplayInfo::operator=(const DisplayInfo& right)
{
   if (this != &right)
   {
      assign(right);
   }

   return (*this);
}

DisplayInfo::~DisplayInfo()
{
   // nothing to do yet
}

void DisplayInfo::determineDisplayInfo()
{
   OSVERSIONINFO osVersion;
   HKEY hKeyEnum;
   HKEY hKeyGroup;
   HKEY hKeyObject;
   HKEY hKeyProperty;
   string strSubkey;
   TCHAR szAdapterName[255];
   TCHAR szAdapterChip[255];
   TCHAR szGroupName[255];
   TCHAR szDeviceName[255];
   TCHAR szPropertyName[255];
   TCHAR szClassName[255];
   TCHAR szServiceName[255];
   DWORD	dwLength;
   DWORD	dwType;
   DWORD	dwMemory;
   DWORD	dwIndexEnum = 0;
   DWORD	dwIndexGroup = 0;
   DWORD	dwIndexProperties = 0;
   long  lResult;
   long  lAdapterMemory;
   FILETIME MyFileTime;

	osVersion.dwOSVersionInfoSize = sizeof( OSVERSIONINFO);
	if (GetVersionEx( &osVersion) == 0)
	{
		// Add a unknown adapter to the list
	}

	// Try to get Display Adapter info from the registry
	switch( osVersion.dwPlatformId)
	{
	case VER_PLATFORM_WIN32_WINDOWS:
		// Windows 9X => Open the Display key from HKLM\System\CurrentControlSet\Services\Class\DISPLAY
		if (RegOpenKeyEx( HKEY_LOCAL_MACHINE, WIN_DISPLAY_KEY, 0, KEY_READ, &hKeyEnum) == ERROR_SUCCESS)
		{
			// Enum the devices subkeys to find active display (have an INFO value)
			dwLength = 255;
			while ((lResult = RegEnumKeyEx( hKeyEnum, dwIndexEnum, szDeviceName, &dwLength, 0, NULL, 0, &MyFileTime)) == ERROR_SUCCESS)
			{
				// For each object, Try to open the device key
				szDeviceName[dwLength] = 0;
				csSubKey.Format( _T( "%s\\%s"), WIN_DISPLAY_KEY, szDeviceName);
				if (RegOpenKeyEx( HKEY_LOCAL_MACHINE, csSubKey, 0, KEY_READ, &hKeyObject) == ERROR_SUCCESS)
				{
					strcpy( szAdapterName, NOT_AVAILABLE);
					strcpy( szAdapterChip, NOT_AVAILABLE); 
					lAdapterMemory = -1;
					// OK => Read the Graphic Adapter description
					dwLength = 255;
					if (RegQueryValueEx( hKeyObject, WIN_ADAPTER_NAME_VALUE, 0, &dwType, (LPBYTE) szAdapterName, &dwLength) == ERROR_SUCCESS)
					{
						szAdapterName[dwLength]=0;
					}
					else
						strcpy( szAdapterName, NOT_AVAILABLE);
					// Open the INFO key from Display Device
					csSubKey.Format( _T( "%s\\%s\\%s"), WIN_DISPLAY_KEY, szDeviceName, WIN_DEVICE_INFO_KEY);
					if (RegOpenKeyEx( HKEY_LOCAL_MACHINE, csSubKey, 0, KEY_READ, &hKeyProperty) == ERROR_SUCCESS)
					{
						// Read the Graphic Adapter Chipset
						dwLength = 255;
						if (RegQueryValueEx( hKeyProperty, WIN_ADAPTER_CHIP_VALUE, 0, &dwType, (LPBYTE) szAdapterChip, &dwLength) == ERROR_SUCCESS)
						{
							szAdapterChip[dwLength]=0;
						}
						else
							strcpy( szAdapterChip, NOT_AVAILABLE); 
						// Read the Graphic Adapter Memory size
						dwLength = sizeof( DWORD);
						dwType = REG_DWORD;
						if (RegQueryValueEx( hKeyProperty, WIN_ADAPTER_MEMORY_VALUE, 0, &dwType, (LPBYTE) &dwMemory, &dwLength) == ERROR_SUCCESS)
							lAdapterMemory = dwMemory/ONE_MEGABYTE;
						else
							lAdapterMemory = -1;
						RegCloseKey( hKeyProperty);
					}
					RegCloseKey( hKeyObject);
					cAdapter.Set( szAdapterName, szAdapterChip, lAdapterMemory);
				}
				// Add the device to the adapter list
				pList->AddTail( cAdapter);
				// Enum the next device
				dwIndexEnum++;
			}
			RegCloseKey( hKeyEnum);
		}
		break;
	case VER_PLATFORM_WIN32_NT:
		// Windows NT =>  Browse the active service keys to find the Display service
		// Enumerate service groups under HKLM\System\CurrentControlSet\Enum
		if (RegOpenKeyEx( HKEY_LOCAL_MACHINE, NT_ENUM_KEY, 0, KEY_READ, &hKeyEnum) == ERROR_SUCCESS)
		{
			dwLength = 255;
			while ((lResult = RegEnumKeyEx( hKeyEnum, dwIndexEnum, szGroupName, &dwLength, 0, NULL, 0, &MyFileTime)) == ERROR_SUCCESS)
			{
				// For each group, enumerate service keys
				szGroupName[dwLength] = 0;
				csSubKey.Format( _T( "%s\\%s"), NT_ENUM_KEY, szGroupName);
				if (RegOpenKeyEx( HKEY_LOCAL_MACHINE, csSubKey, 0, KEY_READ, &hKeyGroup) == ERROR_SUCCESS)
				{
					dwLength = 255;
					dwIndexGroup = 0;
					while ((lResult = RegEnumKeyEx( hKeyGroup, dwIndexGroup, szDeviceName, &dwLength, 0, NULL, 0, &MyFileTime)) == ERROR_SUCCESS)
					{
						// For each service, enumerate propertie keys
						szDeviceName[dwLength] = 0;
						csSubKey.Format( _T( "%s\\%s\\%s"), NT_ENUM_KEY, szGroupName, szDeviceName);
						if (RegOpenKeyEx( HKEY_LOCAL_MACHINE, csSubKey, 0, KEY_READ, &hKeyObject) == ERROR_SUCCESS)
						{
							dwLength = 255;
							dwIndexProperties = 0;
							while ((lResult = RegEnumKeyEx( hKeyObject, dwIndexProperties, szPropertyName, &dwLength, 0, NULL, 0, &MyFileTime)) == ERROR_SUCCESS)
							{
								// If a display class key, read the associated service
								szPropertyName[dwLength] = 0;
								csSubKey.Format( _T( "%s\\%s\\%s\\%s"), NT_ENUM_KEY, szGroupName, szDeviceName, szPropertyName);
								if (RegOpenKeyEx( HKEY_LOCAL_MACHINE, csSubKey, 0, KEY_READ, &hKeyProperty) == ERROR_SUCCESS)
								{
									// Read the class
									dwLength = 255;
									if (RegQueryValueEx( hKeyProperty, NT_ENUM_CLASS_VALUE, 0, &dwType, (LPBYTE) szClassName, &dwLength) != ERROR_SUCCESS)
									{
										// Cannot read the class name
										RegCloseKey( hKeyProperty);
										dwIndexProperties ++;
										dwLength = 255;
										continue;
									}
									szClassName[dwLength] = 0;
									if (strcmpi( szClassName, NT_ENUM_DISPLAY_VALUE) != 0)
									{
										// Not a display service
										dwIndexProperties ++;
										dwLength = 255;
										continue;
									}
									// We have found the display service => get the service name
									dwLength = 255;
									if (RegQueryValueEx( hKeyProperty, NT_ENUM_SERVICE_VALUE, 0, &dwType, (LPBYTE) szServiceName, &dwLength) != ERROR_SUCCESS)
									{
										// Cannot read the associated service name
										RegCloseKey( hKeyProperty);
										dwIndexProperties ++;
										dwLength = 255;
										continue;
									}
									// We know the service name => get the Graphic Adapter infos
									szServiceName[dwLength] = 0;
									RegCloseKey( hKeyProperty);
									csSubKey.Format( _T( "%s\\%s\\%s"), NT_SERVICES_KEY, szServiceName, NT_SERVICE_DEVICE_KEY);
									strcpy( szAdapterName, NOT_AVAILABLE);
									strcpy( szAdapterChip, NOT_AVAILABLE);
									lAdapterMemory = -1;
									if (RegOpenKeyEx( HKEY_LOCAL_MACHINE, csSubKey, 0, KEY_READ, &hKeyProperty) == ERROR_SUCCESS)
									{
										dwLength = 255;
										// Get the Graphic Adapter name
										if (RegQueryValueEx( hKeyProperty, NT_ADAPTER_NAME_VALUE, 0, &dwType, (LPBYTE) szAdapterName, &dwLength) == ERROR_SUCCESS)
										{
											szAdapterName[dwLength]=0;
											// The value is an array of string, each string only containing one character
											// Build a real string by copying each string to one
											CString csAdapter;
											DWORD dwCount = 0;
											while (dwCount < dwLength)
											{
												csAdapter += (szAdapterName+dwCount);
												dwCount += strlen( szAdapterName);
											}
											strcpy( szAdapterName, csAdapter);
										}
										else
											strcpy( szAdapterName, NOT_AVAILABLE);
										// Get the Graphic Adapter Chipset
										dwLength = 255;
										if (RegQueryValueEx( hKeyProperty, NT_ADAPTER_CHIP_VALUE, 0, &dwType, (LPBYTE) szAdapterChip, &dwLength) == ERROR_SUCCESS)
										{
											szAdapterChip[dwLength]=0;
											// The value is an array of string, each string only containing one character
											// Build a real string by copying each string to one
											CString csChip;
											DWORD dwCount = 0;
											while (dwCount < dwLength)
											{
												csChip += (szAdapterChip+dwCount);
												dwCount += strlen( szAdapterChip);
											}
											strcpy( szAdapterChip, csChip);
										}
										else
											strcpy( szAdapterName, NOT_AVAILABLE);
										// Get the Graphic Adapter Memory size
										dwLength = sizeof( DWORD);
										dwType = REG_DWORD;
										if (RegQueryValueEx( hKeyProperty, NT_ADAPTER_MEMORY_VALUE, 0, &dwType, (LPBYTE) &dwMemory, &dwLength) == ERROR_SUCCESS)
											lAdapterMemory = dwMemory/ONE_MEGABYTE;
										else
											lAdapterMemory = -1;
										cAdapter.Set( szAdapterName, szAdapterChip, lAdapterMemory);
										RegCloseKey( hKeyProperty);
									} // if RegOpenKey NT_SERVICE_KEY
									// Add the device to the adapter lis
									pList->AddTail( cAdapter);
								} // if RegOpenKey Property Key
								dwIndexProperties++;
								dwLength = 255;
							} // while RegEnumKey Properties
							RegCloseKey( hKeyObject);
						} // if RegOpenKey Object Key
						dwIndexGroup ++;
						dwLength = 255;
					} // while RegEnumKey Group
					RegCloseKey( hKeyGroup);
				} // if RegOpenKey Group Key
				dwIndexEnum++;
				dwLength = 255;
			} // while RegEnumKey Enum
			RegCloseKey( hKeyEnum);
		} // if RegOpenKey enum Key
		break;
	default:
		// Unknown
		return;
	}
	return;
}

void DisplayInfo::assign(const DisplayInfo& source)
{
   // assign all of source's members to this*
}
*/