/*==========================================================================;
 *
 *  Copyright (C) Microsoft Corporation.  All Rights Reserved.
 *
 *  File:       ddraw.h
 *  Content:    DirectDraw include file
 *
 ***************************************************************************/

#ifndef __DDRAW_INCLUDED__
#define __DDRAW_INCLUDED__

//Disable the nameless union warning when building internally
#undef ENABLE_NAMELESS_UNION_PRAGMA
#ifdef DIRECTX_REDIST
#define ENABLE_NAMELESS_UNION_PRAGMA
#endif

#ifdef ENABLE_NAMELESS_UNION_PRAGMA
#pragma warning(disable:4201)
#endif

/*
 * If you wish an application built against the newest version of DirectDraw
 * to run against an older DirectDraw run time then define DIRECTDRAW_VERSION
 * to be the earlies version of DirectDraw you wish to run against. For,
 * example if you wish an application to run against a DX 3 runtime define
 * DIRECTDRAW_VERSION to be 0x0300.
 */
#ifndef   DIRECTDRAW_VERSION
#define   DIRECTDRAW_VERSION 0x0700
#endif /* DIRECTDRAW_VERSION */

#if defined( _WIN32 )  && !defined( _NO_COM )
#define COM_NO_WINDOWS_H
#include <objbase.h>
#else
#define IUnknown            void
#if !defined( NT_BUILD_ENVIRONMENT ) && !defined(WINNT)
        #define CO_E_NOTINITIALIZED 0x800401F0L
#endif
#endif

#define _FACDD  0x876
#define MAKE_DDHRESULT( code )  MAKE_HRESULT( 1, _FACDD, code )

#ifdef __cplusplus
extern "C" {
#endif

//
// For compilers that don't support nameless unions, do a
//
// #define NONAMELESSUNION
//
// before #include <ddraw.h>
//
#ifndef DUMMYUNIONNAMEN
#if defined(__cplusplus) || !defined(NONAMELESSUNION)
#define DUMMYUNIONNAMEN(n)
#else
#define DUMMYUNIONNAMEN(n)      u##n
#endif
#endif

#ifndef MAKEFOURCC
    #define MAKEFOURCC(ch0, ch1, ch2, ch3)                              \
                ((DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8) |   \
                ((DWORD)(BYTE)(ch2) << 16) | ((DWORD)(BYTE)(ch3) << 24 ))
#endif //defined(MAKEFOURCC)

/*
 * FOURCC codes for DX compressed-texture pixel formats
 */
#define FOURCC_DXT1  (MAKEFOURCC('D','X','T','1'))
#define FOURCC_DXT2  (MAKEFOURCC('D','X','T','2'))
#define FOURCC_DXT3  (MAKEFOURCC('D','X','T','3'))
#define FOURCC_DXT4  (MAKEFOURCC('D','X','T','4'))
#define FOURCC_DXT5  (MAKEFOURCC('D','X','T','5'))

/*
 * GUIDS used by DirectDraw objects
 */
#if defined( _WIN32 ) && !defined( _NO_COM )

DEFINE_GUID( CLSID_DirectDraw,                  0xD7B70EE0,0x4340,0x11CF,0xB0,0x63,0x00,0x20,0xAF,0xC2,0xCD,0x35 );
DEFINE_GUID( CLSID_DirectDraw7,                 0x3c305196,0x50db,0x11d3,0x9c,0xfe,0x00,0xc0,0x4f,0xd9,0x30,0xc5 );
DEFINE_GUID( CLSID_DirectDrawClipper,           0x593817A0,0x7DB3,0x11CF,0xA2,0xDE,0x00,0xAA,0x00,0xb9,0x33,0x56 );
DEFINE_GUID( IID_IDirectDraw,                   0x6C14DB80,0xA733,0x11CE,0xA5,0x21,0x00,0x20,0xAF,0x0B,0xE5,0x60 );
DEFINE_GUID( IID_IDirectDraw2,                  0xB3A6F3E0,0x2B43,0x11CF,0xA2,0xDE,0x00,0xAA,0x00,0xB9,0x33,0x56 );
DEFINE_GUID( IID_IDirectDraw4,                  0x9c59509a,0x39bd,0x11d1,0x8c,0x4a,0x00,0xc0,0x4f,0xd9,0x30,0xc5 );
DEFINE_GUID( IID_IDirectDraw7,                  0x15e65ec0,0x3b9c,0x11d2,0xb9,0x2f,0x00,0x60,0x97,0x97,0xea,0x5b );
DEFINE_GUID( IID_IDirectDrawSurface,            0x6C14DB81,0xA733,0x11CE,0xA5,0x21,0x00,0x20,0xAF,0x0B,0xE5,0x60 );
DEFINE_GUID( IID_IDirectDrawSurface2,           0x57805885,0x6eec,0x11cf,0x94,0x41,0xa8,0x23,0x03,0xc1,0x0e,0x27 );
DEFINE_GUID( IID_IDirectDrawSurface3,           0xDA044E00,0x69B2,0x11D0,0xA1,0xD5,0x00,0xAA,0x00,0xB8,0xDF,0xBB );
DEFINE_GUID( IID_IDirectDrawSurface4,           0x0B2B8630,0xAD35,0x11D0,0x8E,0xA6,0x00,0x60,0x97,0x97,0xEA,0x5B );
DEFINE_GUID( IID_IDirectDrawSurface7,           0x06675a80,0x3b9b,0x11d2,0xb9,0x2f,0x00,0x60,0x97,0x97,0xea,0x5b );
DEFINE_GUID( IID_IDirectDrawPalette,            0x6C14DB84,0xA733,0x11CE,0xA5,0x21,0x00,0x20,0xAF,0x0B,0xE5,0x60 );
DEFINE_GUID( IID_IDirectDrawClipper,            0x6C14DB85,0xA733,0x11CE,0xA5,0x21,0x00,0x20,0xAF,0x0B,0xE5,0x60 );
DEFINE_GUID( IID_IDirectDrawColorControl,       0x4B9F0EE0,0x0D7E,0x11D0,0x9B,0x06,0x00,0xA0,0xC9,0x03,0xA3,0xB8 );
DEFINE_GUID( IID_IDirectDrawGammaControl,       0x69C11C3E,0xB46B,0x11D1,0xAD,0x7A,0x00,0xC0,0x4F,0xC2,0x9B,0x4E );

#endif

/*============================================================================
 *
 * DirectDraw Structures
 *
 * Various structures used to invoke DirectDraw.
 *
 *==========================================================================*/

struct IDirectDraw;
struct IDirectDrawSurface;
struct IDirectDrawPalette;
struct IDirectDrawClipper;

typedef struct IDirectDraw              FAR *LPDIRECTDRAW;
typedef struct IDirectDraw2             FAR *LPDIRECTDRAW2;
typedef struct IDirectDraw4             FAR *LPDIRECTDRAW4;
typedef struct IDirectDraw7             FAR *LPDIRECTDRAW7;
typedef struct IDirectDrawSurface       FAR *LPDIRECTDRAWSURFACE;
typedef struct IDirectDrawSurface2      FAR *LPDIRECTDRAWSURFACE2;
typedef struct IDirectDrawSurface3      FAR *LPDIRECTDRAWSURFACE3;
typedef struct IDirectDrawSurface4      FAR *LPDIRECTDRAWSURFACE4;
typedef struct IDirectDrawSurface7      FAR *LPDIRECTDRAWSURFACE7;
typedef struct IDirectDrawPalette               FAR *LPDIRECTDRAWPALETTE;
typedef struct IDirectDrawClipper               FAR *LPDIRECTDRAWCLIPPER;
typedef struct IDirectDrawColorControl          FAR *LPDIRECTDRAWCOLORCONTROL;
typedef struct IDirectDrawGammaControl          FAR *LPDIRECTDRAWGAMMACONTROL;

typedef struct _DDFXROP                 FAR *LPDDFXROP;
typedef struct _DDSURFACEDESC           FAR *LPDDSURFACEDESC;
typedef struct _DDSURFACEDESC2          FAR *LPDDSURFACEDESC2;
typedef struct _DDCOLORCONTROL          FAR *LPDDCOLORCONTROL;

/*
 * API's
 */
#if (defined (WIN32) || defined( _WIN32 ) ) && !defined( _NO_COM )
//#if defined( _WIN32 ) && !defined( _NO_ENUM )
    typedef BOOL (FAR PASCAL * LPDDENUMCALLBACKA)(GUID FAR *, LPSTR, LPSTR, LPVOID);
    typedef BOOL (FAR PASCAL * LPDDENUMCALLBACKW)(GUID FAR *, LPWSTR, LPWSTR, LPVOID);
    extern HRESULT WINAPI DirectDrawEnumerateW( LPDDENUMCALLBACKW lpCallback, LPVOID lpContext );
    extern HRESULT WINAPI DirectDrawEnumerateA( LPDDENUMCALLBACKA lpCallback, LPVOID lpContext );
    /*
     * Protect against old SDKs
     */
    #if !defined(HMONITOR_DECLARED) && (WINVER < 0x0500)
        #define HMONITOR_DECLARED
        DECLARE_HANDLE(HMONITOR);
    #endif
    typedef BOOL (FAR PASCAL * LPDDENUMCALLBACKEXA)(GUID FAR *, LPSTR, LPSTR, LPVOID, HMONITOR);
    typedef BOOL (FAR PASCAL * LPDDENUMCALLBACKEXW)(GUID FAR *, LPWSTR, LPWSTR, LPVOID, HMONITOR);
    extern HRESULT WINAPI DirectDrawEnumerateExW( LPDDENUMCALLBACKEXW lpCallback, LPVOID lpContext, DWORD dwFlags);
    extern HRESULT WINAPI DirectDrawEnumerateExA( LPDDENUMCALLBACKEXA lpCallback, LPVOID lpContext, DWORD dwFlags);
    typedef HRESULT (WINAPI * LPDIRECTDRAWENUMERATEEXA)( LPDDENUMCALLBACKEXA lpCallback, LPVOID lpContext, DWORD dwFlags);
    typedef HRESULT (WINAPI * LPDIRECTDRAWENUMERATEEXW)( LPDDENUMCALLBACKEXW lpCallback, LPVOID lpContext, DWORD dwFlags);

    #ifdef UNICODE
        typedef LPDDENUMCALLBACKW           LPDDENUMCALLBACK;
        #define DirectDrawEnumerate         DirectDrawEnumerateW
        typedef LPDDENUMCALLBACKEXW         LPDDENUMCALLBACKEX;
        typedef LPDIRECTDRAWENUMERATEEXW        LPDIRECTDRAWENUMERATEEX;
        #define DirectDrawEnumerateEx       DirectDrawEnumerateExW
    #else
        typedef LPDDENUMCALLBACKA           LPDDENUMCALLBACK;
        #define DirectDrawEnumerate         DirectDrawEnumerateA
        typedef LPDDENUMCALLBACKEXA         LPDDENUMCALLBACKEX;
        typedef LPDIRECTDRAWENUMERATEEXA        LPDIRECTDRAWENUMERATEEX;
        #define DirectDrawEnumerateEx       DirectDrawEnumerateExA
    #endif
    extern HRESULT WINAPI DirectDrawCreate( GUID FAR *lpGUID, LPDIRECTDRAW FAR *lplpDD, IUnknown FAR *pUnkOuter );
    extern HRESULT WINAPI DirectDrawCreateEx( GUID FAR * lpGuid, LPVOID  *lplpDD, REFIID  iid,IUnknown FAR *pUnkOuter );
    extern HRESULT WINAPI DirectDrawCreateClipper( DWORD dwFlags, LPDIRECTDRAWCLIPPER FAR *lplpDDClipper, IUnknown FAR *pUnkOuter );
#endif
/*
 * Flags for DirectDrawEnumerateEx
 * DirectDrawEnumerateEx supercedes DirectDrawEnumerate. You must use GetProcAddress to
 * obtain a function pointer (of type LPDIRECTDRAWENUMERATEEX) to DirectDrawEnumerateEx.
 * By default, only the primary display device is enumerated.
 * DirectDrawEnumerate is equivalent to DirectDrawEnumerate(,,DDENUM_NONDISPLAYDEVICES)
 */

/*
 * This flag causes enumeration of any GDI display devices which are part of
 * the Windows Desktop
 */
#define DDENUM_ATTACHEDSECONDARYDEVICES     0x00000001L

/*
 * This flag causes enumeration of any GDI display devices which are not
 * part of the Windows Desktop
 */
#define DDENUM_DETACHEDSECONDARYDEVICES     0x00000002L

/*
 * This flag causes enumeration of non-display devices
 */
#define DDENUM_NONDISPLAYDEVICES            0x00000004L


#define REGSTR_KEY_DDHW_DESCRIPTION     "Description"
#define REGSTR_KEY_DDHW_DRIVERNAME      "DriverName"
#define REGSTR_PATH_DDHW                "Hardware\\DirectDrawDrivers"

#define DDCREATE_HARDWAREONLY           0x00000001l
#define DDCREATE_EMULATIONONLY          0x00000002l

#if defined(WINNT) || !defined(WIN32)
typedef long HRESULT;
#endif

//#ifndef WINNT
typedef HRESULT (FAR PASCAL * LPDDENUMMODESCALLBACK)(LPDDSURFACEDESC, LPVOID);
typedef HRESULT (FAR PASCAL * LPDDENUMMODESCALLBACK2)(LPDDSURFACEDESC2, LPVOID);
typedef HRESULT (FAR PASCAL * LPDDENUMSURFACESCALLBACK)(LPDIRECTDRAWSURFACE, LPDDSURFACEDESC, LPVOID);
typedef HRESULT (FAR PASCAL * LPDDENUMSURFACESCALLBACK2)(LPDIRECTDRAWSURFACE4, LPDDSURFACEDESC2, LPVOID);
typedef HRESULT (FAR PASCAL * LPDDENUMSURFACESCALLBACK7)(LPDIRECTDRAWSURFACE7, LPDDSURFACEDESC2, LPVOID);
//#endif

/*
 * Generic pixel format with 8-bit RGB and alpha components
 */
typedef struct _DDARGB
{
    BYTE blue;
    BYTE green;
    BYTE red;
    BYTE alpha;
} DDARGB;

typedef DDARGB FAR *LPDDARGB;

/*
 * This version of the structure remains for backwards source compatibility.
 * The DDARGB structure is the one that should be used for all DirectDraw APIs.
 */
typedef struct _DDRGBA
{
    BYTE red;
    BYTE green;
    BYTE blue;
    BYTE alpha;
} DDRGBA;

typedef DDRGBA FAR *LPDDRGBA;


/*
 * DDCOLORKEY
 */
typedef struct _DDCOLORKEY
{
    DWORD       dwColorSpaceLowValue;   // low boundary of color space that is to
                                        // be treated as Color Key, inclusive
    DWORD       dwColorSpaceHighValue;  // high boundary of color space that is
                                        // to be treated as Color Key, inclusive
} DDCOLORKEY;

typedef DDCOLORKEY FAR* LPDDCOLORKEY;

/*
 * DDBLTFX
 * Used to pass override information to the DIRECTDRAWSURFACE callback Blt.
 */
typedef struct _DDBLTFX
{
    DWORD       dwSize;                         // size of structure
    DWORD       dwDDFX;                         // FX operations
    DWORD       dwROP;                          // Win32 raster operations
    DWORD       dwDDROP;                        // Raster operations new for DirectDraw
    DWORD       dwRotationAngle;                // Rotation angle for blt
    DWORD       dwZBufferOpCode;                // ZBuffer compares
    DWORD       dwZBufferLow;                   // Low limit of Z buffer
    DWORD       dwZBufferHigh;                  // High limit of Z buffer
    DWORD       dwZBufferBaseDest;              // Destination base value
    DWORD       dwZDestConstBitDepth;           // Bit depth used to specify Z constant for destination
    union
    {
        DWORD   dwZDestConst;                   // Constant to use as Z buffer for dest
        LPDIRECTDRAWSURFACE lpDDSZBufferDest;   // Surface to use as Z buffer for dest
    } DUMMYUNIONNAMEN(1);
    DWORD       dwZSrcConstBitDepth;            // Bit depth used to specify Z constant for source
    union
    {
        DWORD   dwZSrcConst;                    // Constant to use as Z buffer for src
        LPDIRECTDRAWSURFACE lpDDSZBufferSrc;    // Surface to use as Z buffer for src
    } DUMMYUNIONNAMEN(2);
    DWORD       dwAlphaEdgeBlendBitDepth;       // Bit depth used to specify constant for alpha edge blend
    DWORD       dwAlphaEdgeBlend;               // Alpha for edge blending
    DWORD       dwReserved;
    DWORD       dwAlphaDestConstBitDepth;       // Bit depth used to specify alpha constant for destination
    union
    {
        DWORD   dwAlphaDestConst;               // Constant to use as Alpha Channel
        LPDIRECTDRAWSURFACE lpDDSAlphaDest;     // Surface to use as Alpha Channel
    } DUMMYUNIONNAMEN(3);
    DWORD       dwAlphaSrcConstBitDepth;        // Bit depth used to specify alpha constant for source
    union
    {
        DWORD   dwAlphaSrcConst;                // Constant to use as Alpha Channel
        LPDIRECTDRAWSURFACE lpDDSAlphaSrc;      // Surface to use as Alpha Channel
    } DUMMYUNIONNAMEN(4);
    union
    {
        DWORD   dwFillColor;                    // color in RGB or Palettized
        DWORD   dwFillDepth;                    // depth value for z-buffer
        DWORD   dwFillPixel;                    // pixel value for RGBA or RGBZ
        LPDIRECTDRAWSURFACE lpDDSPattern;       // Surface to use as pattern
    } DUMMYUNIONNAMEN(5);
    DDCOLORKEY  ddckDestColorkey;               // DestColorkey override
    DDCOLORKEY  ddckSrcColorkey;                // SrcColorkey override
} DDBLTFX;

typedef DDBLTFX FAR* LPDDBLTFX;



/*
 * DDSCAPS
 */
typedef struct _DDSCAPS
{
    DWORD       dwCaps;         // capabilities of surface wanted
} DDSCAPS;

typedef DDSCAPS FAR* LPDDSCAPS;


/*
 * DDOSCAPS
 */
typedef struct _DDOSCAPS
{
    DWORD       dwCaps;         // capabilities of surface wanted
} DDOSCAPS;

typedef DDOSCAPS FAR* LPDDOSCAPS;

/*
 * This structure is used internally by DirectDraw.
 */
typedef struct _DDSCAPSEX
{
    DWORD       dwCaps2;
    DWORD       dwCaps3;
    union
    {
        DWORD       dwCaps4;
        DWORD       dwVolumeDepth;
    } DUMMYUNIONNAMEN(1);
} DDSCAPSEX, FAR * LPDDSCAPSEX;

/*
 * DDSCAPS2
 */
typedef struct _DDSCAPS2
{
    DWORD       dwCaps;         // capabilities of surface wanted
    DWORD       dwCaps2;
    DWORD       dwCaps3;
    union
    {
        DWORD       dwCaps4;
        DWORD       dwVolumeDepth;
    } DUMMYUNIONNAMEN(1);
} DDSCAPS2;

typedef DDSCAPS2 FAR* LPDDSCAPS2;

/*
 * DDCAPS
 */
#define DD_ROP_SPACE            (256/32)        // space required to store ROP array
/*
 * NOTE: Our choosen structure number scheme is to append a single digit to
 * the end of the structure giving the version that structure is associated
 * with.
 */

/*
 * This structure represents the DDCAPS structure released in DirectDraw 1.0.  It is used internally
 * by DirectDraw to interpret caps passed into ddraw by drivers written prior to the release of DirectDraw 2.0.
 * New applications should use the DDCAPS structure defined below.
 */
typedef struct _DDCAPS_DX1
{
    DWORD       dwSize;                 // size of the DDDRIVERCAPS structure
    DWORD       dwCaps;                 // driver specific capabilities
    DWORD       dwCaps2;                // more driver specific capabilites
    DWORD       dwCKeyCaps;             // color key capabilities of the surface
    DWORD       dwFXCaps;               // driver specific stretching and effects capabilites
    DWORD       dwFXAlphaCaps;          // alpha driver specific capabilities
    DWORD       dwPalCaps;              // palette capabilities
    DWORD       dwSVCaps;               // stereo vision capabilities
    DWORD       dwAlphaBltConstBitDepths;       // DDBD_2,4,8
    DWORD       dwAlphaBltPixelBitDepths;       // DDBD_1,2,4,8
    DWORD       dwAlphaBltSurfaceBitDepths;     // DDBD_1,2,4,8
    DWORD       dwAlphaOverlayConstBitDepths;   // DDBD_2,4,8
    DWORD       dwAlphaOverlayPixelBitDepths;   // DDBD_1,2,4,8
    DWORD       dwAlphaOverlaySurfaceBitDepths; // DDBD_1,2,4,8
    DWORD       dwZBufferBitDepths;             // DDBD_8,16,24,32
    DWORD       dwVidMemTotal;          // total amount of video memory
    DWORD       dwVidMemFree;           // amount of free video memory
    DWORD       dwMaxVisibleOverlays;   // maximum number of visible overlays
    DWORD       dwCurrVisibleOverlays;  // current number of visible overlays
    DWORD       dwNumFourCCCodes;       // number of four cc codes
    DWORD       dwAlignBoundarySrc;     // source rectangle alignment
    DWORD       dwAlignSizeSrc;         // source rectangle byte size
    DWORD       dwAlignBoundaryDest;    // dest rectangle alignment
    DWORD       dwAlignSizeDest;        // dest rectangle byte size
    DWORD       dwAlignStrideAlign;     // stride alignment
    DWORD       dwRops[DD_ROP_SPACE];   // ROPS supported
    DDSCAPS     ddsCaps;                // DDSCAPS structure has all the general capabilities
    DWORD       dwMinOverlayStretch;    // minimum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
    DWORD       dwMaxOverlayStretch;    // maximum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
    DWORD       dwMinLiveVideoStretch;  // OBSOLETE! This field remains for compatability reasons only
    DWORD       dwMaxLiveVideoStretch;  // OBSOLETE! This field remains for compatability reasons only
    DWORD       dwMinHwCodecStretch;    // OBSOLETE! This field remains for compatability reasons only
    DWORD       dwMaxHwCodecStretch;    // OBSOLETE! This field remains for compatability reasons only
    DWORD       dwReserved1;            // reserved
    DWORD       dwReserved2;            // reserved
    DWORD       dwReserved3;            // reserved
} DDCAPS_DX1;

typedef DDCAPS_DX1 FAR* LPDDCAPS_DX1;

/*
 * This structure is the DDCAPS structure as it was in version 2 and 3 of Direct X.
 * It is present for back compatability.
 */
typedef struct _DDCAPS_DX3
{
    DWORD       dwSize;                 // size of the DDDRIVERCAPS structure
    DWORD       dwCaps;                 // driver specific capabilities
    DWORD       dwCaps2;                // more driver specific capabilites
    DWORD       dwCKeyCaps;             // color key capabilities of the surface
    DWORD       dwFXCaps;               // driver specific stretching and effects capabilites
    DWORD       dwFXAlphaCaps;          // alpha driver specific capabilities
    DWORD       dwPalCaps;              // palette capabilities
    DWORD       dwSVCaps;               // stereo vision capabilities
    DWORD       dwAlphaBltConstBitDepths;       // DDBD_2,4,8
    DWORD       dwAlphaBltPixelBitDepths;       // DDBD_1,2,4,8
    DWORD       dwAlphaBltSurfaceBitDepths;     // DDBD_1,2,4,8
    DWORD       dwAlphaOverlayConstBitDepths;   // DDBD_2,4,8
    DWORD       dwAlphaOverlayPixelBitDepths;   // DDBD_1,2,4,8
    DWORD       dwAlphaOverlaySurfaceBitDepths; // DDBD_1,2,4,8
    DWORD       dwZBufferBitDepths;             // DDBD_8,16,24,32
    DWORD       dwVidMemTotal;          // total amount of video memory
    DWORD       dwVidMemFree;           // amount of free video memory
    DWORD       dwMaxVisibleOverlays;   // maximum number of visible overlays
    DWORD       dwCurrVisibleOverlays;  // current number of visible overlays
    DWORD       dwNumFourCCCodes;       // number of four cc codes
    DWORD       dwAlignBoundarySrc;     // source rectangle alignment
    DWORD       dwAlignSizeSrc;         // source rectangle byte size
    DWORD       dwAlignBoundaryDest;    // dest rectangle alignment
    DWORD       dwAlignSizeDest;        // dest rectangle byte size
    DWORD       dwAlignStrideAlign;     // stride alignment
    DWORD       dwRops[DD_ROP_SPACE];   // ROPS supported
    DDSCAPS     ddsCaps;                // DDSCAPS structure has all the general capabilities
    DWORD       dwMinOverlayStretch;    // minimum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
    DWORD       dwMaxOverlayStretch;    // maximum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
    DWORD       dwMinLiveVideoStretch;  // minimum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
    DWORD       dwMaxLiveVideoStretch;  // maximum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
    DWORD       dwMinHwCodecStretch;    // minimum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
    DWORD       dwMaxHwCodecStretch;    // maximum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
    DWORD       dwReserved1;            // reserved
    DWORD       dwReserved2;            // reserved
    DWORD       dwReserved3;            // reserved
    DWORD       dwSVBCaps;              // driver specific capabilities for System->Vmem blts
    DWORD       dwSVBCKeyCaps;          // driver color key capabilities for System->Vmem blts
    DWORD       dwSVBFXCaps;            // driver FX capabilities for System->Vmem blts
    DWORD       dwSVBRops[DD_ROP_SPACE];// ROPS supported for System->Vmem blts
    DWORD       dwVSBCaps;              // driver specific capabilities for Vmem->System blts
    DWORD       dwVSBCKeyCaps;          // driver color key capabilities for Vmem->System blts
    DWORD       dwVSBFXCaps;            // driver FX capabilities for Vmem->System blts
    DWORD       dwVSBRops[DD_ROP_SPACE];// ROPS supported for Vmem->System blts
    DWORD       dwSSBCaps;              // driver specific capabilities for System->System blts
    DWORD       dwSSBCKeyCaps;          // driver color key capabilities for System->System blts
    DWORD       dwSSBFXCaps;            // driver FX capabilities for System->System blts
    DWORD       dwSSBRops[DD_ROP_SPACE];// ROPS supported for System->System blts
    DWORD       dwReserved4;            // reserved
    DWORD       dwReserved5;            // reserved
    DWORD       dwReserved6;            // reserved
} DDCAPS_DX3;
typedef DDCAPS_DX3 FAR* LPDDCAPS_DX3;

/*
 * This structure is the DDCAPS structure as it was in version 5 of Direct X.
 * It is present for back compatability.
 */
typedef struct _DDCAPS_DX5
{
/*  0*/ DWORD   dwSize;                 // size of the DDDRIVERCAPS structure
/*  4*/ DWORD   dwCaps;                 // driver specific capabilities
/*  8*/ DWORD   dwCaps2;                // more driver specific capabilites
/*  c*/ DWORD   dwCKeyCaps;             // color key capabilities of the surface
/* 10*/ DWORD   dwFXCaps;               // driver specific stretching and effects capabilites
/* 14*/ DWORD   dwFXAlphaCaps;          // alpha driver specific capabilities
/* 18*/ DWORD   dwPalCaps;              // palette capabilities
/* 1c*/ DWORD   dwSVCaps;               // stereo vision capabilities
/* 20*/ DWORD   dwAlphaBltConstBitDepths;       // DDBD_2,4,8
/* 24*/ DWORD   dwAlphaBltPixelBitDepths;       // DDBD_1,2,4,8
/* 28*/ DWORD   dwAlphaBltSurfaceBitDepths;     // DDBD_1,2,4,8
/* 2c*/ DWORD   dwAlphaOverlayConstBitDepths;   // DDBD_2,4,8
/* 30*/ DWORD   dwAlphaOverlayPixelBitDepths;   // DDBD_1,2,4,8
/* 34*/ DWORD   dwAlphaOverlaySurfaceBitDepths; // DDBD_1,2,4,8
/* 38*/ DWORD   dwZBufferBitDepths;             // DDBD_8,16,24,32
/* 3c*/ DWORD   dwVidMemTotal;          // total amount of video memory
/* 40*/ DWORD   dwVidMemFree;           // amount of free video memory
/* 44*/ DWORD   dwMaxVisibleOverlays;   // maximum number of visible overlays
/* 48*/ DWORD   dwCurrVisibleOverlays;  // current number of visible overlays
/* 4c*/ DWORD   dwNumFourCCCodes;       // number of four cc codes
/* 50*/ DWORD   dwAlignBoundarySrc;     // source rectangle alignment
/* 54*/ DWORD   dwAlignSizeSrc;         // source rectangle byte size
/* 58*/ DWORD   dwAlignBoundaryDest;    // dest rectangle alignment
/* 5c*/ DWORD   dwAlignSizeDest;        // dest rectangle byte size
/* 60*/ DWORD   dwAlignStrideAlign;     // stride alignment
/* 64*/ DWORD   dwRops[DD_ROP_SPACE];   // ROPS supported
/* 84*/ DDSCAPS ddsCaps;                // DDSCAPS structure has all the general capabilities
/* 88*/ DWORD   dwMinOverlayStretch;    // minimum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
/* 8c*/ DWORD   dwMaxOverlayStretch;    // maximum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
/* 90*/ DWORD   dwMinLiveVideoStretch;  // minimum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
/* 94*/ DWORD   dwMaxLiveVideoStretch;  // maximum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
/* 98*/ DWORD   dwMinHwCodecStretch;    // minimum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
/* 9c*/ DWORD   dwMaxHwCodecStretch;    // maximum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
/* a0*/ DWORD   dwReserved1;            // reserved
/* a4*/ DWORD   dwReserved2;            // reserved
/* a8*/ DWORD   dwReserved3;            // reserved
/* ac*/ DWORD   dwSVBCaps;              // driver specific capabilities for System->Vmem blts
/* b0*/ DWORD   dwSVBCKeyCaps;          // driver color key capabilities for System->Vmem blts
/* b4*/ DWORD   dwSVBFXCaps;            // driver FX capabilities for System->Vmem blts
/* b8*/ DWORD   dwSVBRops[DD_ROP_SPACE];// ROPS supported for System->Vmem blts
/* d8*/ DWORD   dwVSBCaps;              // driver specific capabilities for Vmem->System blts
/* dc*/ DWORD   dwVSBCKeyCaps;          // driver color key capabilities for Vmem->System blts
/* e0*/ DWORD   dwVSBFXCaps;            // driver FX capabilities for Vmem->System blts
/* e4*/ DWORD   dwVSBRops[DD_ROP_SPACE];// ROPS supported for Vmem->System blts
/*104*/ DWORD   dwSSBCaps;              // driver specific capabilities for System->System blts
/*108*/ DWORD   dwSSBCKeyCaps;          // driver color key capabilities for System->System blts
/*10c*/ DWORD   dwSSBFXCaps;            // driver FX capabilities for System->System blts
/*110*/ DWORD   dwSSBRops[DD_ROP_SPACE];// ROPS supported for System->System blts
// Members added for DX5:
/*130*/ DWORD   dwMaxVideoPorts;        // maximum number of usable video ports
/*134*/ DWORD   dwCurrVideoPorts;       // current number of video ports used
/*138*/ DWORD   dwSVBCaps2;             // more driver specific capabilities for System->Vmem blts
/*13c*/ DWORD   dwNLVBCaps;               // driver specific capabilities for non-local->local vidmem blts
/*140*/ DWORD   dwNLVBCaps2;              // more driver specific capabilities non-local->local vidmem blts
/*144*/ DWORD   dwNLVBCKeyCaps;           // driver color key capabilities for non-local->local vidmem blts
/*148*/ DWORD   dwNLVBFXCaps;             // driver FX capabilities for non-local->local blts
/*14c*/ DWORD   dwNLVBRops[DD_ROP_SPACE]; // ROPS supported for non-local->local blts
} DDCAPS_DX5;
typedef DDCAPS_DX5 FAR* LPDDCAPS_DX5;

typedef struct _DDCAPS_DX6
{
/*  0*/ DWORD   dwSize;                 // size of the DDDRIVERCAPS structure
/*  4*/ DWORD   dwCaps;                 // driver specific capabilities
/*  8*/ DWORD   dwCaps2;                // more driver specific capabilites
/*  c*/ DWORD   dwCKeyCaps;             // color key capabilities of the surface
/* 10*/ DWORD   dwFXCaps;               // driver specific stretching and effects capabilites
/* 14*/ DWORD   dwFXAlphaCaps;          // alpha caps
/* 18*/ DWORD   dwPalCaps;              // palette capabilities
/* 1c*/ DWORD   dwSVCaps;               // stereo vision capabilities
/* 20*/ DWORD   dwAlphaBltConstBitDepths;       // DDBD_2,4,8
/* 24*/ DWORD   dwAlphaBltPixelBitDepths;       // DDBD_1,2,4,8
/* 28*/ DWORD   dwAlphaBltSurfaceBitDepths;     // DDBD_1,2,4,8
/* 2c*/ DWORD   dwAlphaOverlayConstBitDepths;   // DDBD_2,4,8
/* 30*/ DWORD   dwAlphaOverlayPixelBitDepths;   // DDBD_1,2,4,8
/* 34*/ DWORD   dwAlphaOverlaySurfaceBitDepths; // DDBD_1,2,4,8
/* 38*/ DWORD   dwZBufferBitDepths;             // DDBD_8,16,24,32
/* 3c*/ DWORD   dwVidMemTotal;          // total amount of video memory
/* 40*/ DWORD   dwVidMemFree;           // amount of free video memory
/* 44*/ DWORD   dwMaxVisibleOverlays;   // maximum number of visible overlays
/* 48*/ DWORD   dwCurrVisibleOverlays;  // current number of visible overlays
/* 4c*/ DWORD   dwNumFourCCCodes;       // number of four cc codes
/* 50*/ DWORD   dwAlignBoundarySrc;     // source rectangle alignment
/* 54*/ DWORD   dwAlignSizeSrc;         // source rectangle byte size
/* 58*/ DWORD   dwAlignBoundaryDest;    // dest rectangle alignment
/* 5c*/ DWORD   dwAlignSizeDest;        // dest rectangle byte size
/* 60*/ DWORD   dwAlignStrideAlign;     // stride alignment
/* 64*/ DWORD   dwRops[DD_ROP_SPACE];   // ROPS supported
/* 84*/ DDSCAPS ddsOldCaps;             // Was DDSCAPS  ddsCaps. ddsCaps is of type DDSCAPS2 for DX6
/* 88*/ DWORD   dwMinOverlayStretch;    // minimum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
/* 8c*/ DWORD   dwMaxOverlayStretch;    // maximum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
/* 90*/ DWORD   dwMinLiveVideoStretch;  // minimum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
/* 94*/ DWORD   dwMaxLiveVideoStretch;  // maximum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
/* 98*/ DWORD   dwMinHwCodecStretch;    // minimum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
/* 9c*/ DWORD   dwMaxHwCodecStretch;    // maximum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
/* a0*/ DWORD   dwReserved1;            // reserved
/* a4*/ DWORD   dwReserved2;            // reserved
/* a8*/ DWORD   dwReserved3;            // reserved
/* ac*/ DWORD   dwSVBCaps;              // driver specific capabilities for System->Vmem blts
/* b0*/ DWORD   dwSVBCKeyCaps;          // driver color key capabilities for System->Vmem blts
/* b4*/ DWORD   dwSVBFXCaps;            // driver FX capabilities for System->Vmem blts
/* b8*/ DWORD   dwSVBRops[DD_ROP_SPACE];// ROPS supported for System->Vmem blts
/* d8*/ DWORD   dwVSBCaps;              // driver specific capabilities for Vmem->System blts
/* dc*/ DWORD   dwVSBCKeyCaps;          // driver color key capabilities for Vmem->System blts
/* e0*/ DWORD   dwVSBFXCaps;            // driver FX capabilities for Vmem->System blts
/* e4*/ DWORD   dwVSBRops[DD_ROP_SPACE];// ROPS supported for Vmem->System blts
/*104*/ DWORD   dwSSBCaps;              // driver specific capabilities for System->System blts
/*108*/ DWORD   dwSSBCKeyCaps;          // driver color key capabilities for System->System blts
/*10c*/ DWORD   dwSSBFXCaps;            // driver FX capabilities for System->System blts
/*110*/ DWORD   dwSSBRops[DD_ROP_SPACE];// ROPS supported for System->System blts
/*130*/ DWORD   dwMaxVideoPorts;        // maximum number of usable video ports
/*134*/ DWORD   dwCurrVideoPorts;       // current number of video ports used
/*138*/ DWORD   dwSVBCaps2;             // more driver specific capabilities for System->Vmem blts
/*13c*/ DWORD   dwNLVBCaps;               // driver specific capabilities for non-local->local vidmem blts
/*140*/ DWORD   dwNLVBCaps2;              // more driver specific capabilities non-local->local vidmem blts
/*144*/ DWORD   dwNLVBCKeyCaps;           // driver color key capabilities for non-local->local vidmem blts
/*148*/ DWORD   dwNLVBFXCaps;             // driver FX capabilities for non-local->local blts
/*14c*/ DWORD   dwNLVBRops[DD_ROP_SPACE]; // ROPS supported for non-local->local blts
// Members added for DX6 release
/*16c*/ DDSCAPS2 ddsCaps;               // Surface Caps
} DDCAPS_DX6;
typedef DDCAPS_DX6 FAR* LPDDCAPS_DX6;

typedef struct _DDCAPS_DX7
{
/*  0*/ DWORD   dwSize;                 // size of the DDDRIVERCAPS structure
/*  4*/ DWORD   dwCaps;                 // driver specific capabilities
/*  8*/ DWORD   dwCaps2;                // more driver specific capabilites
/*  c*/ DWORD   dwCKeyCaps;             // color key capabilities of the surface
/* 10*/ DWORD   dwFXCaps;               // driver specific stretching and effects capabilites
/* 14*/ DWORD   dwFXAlphaCaps;          // alpha driver specific capabilities
/* 18*/ DWORD   dwPalCaps;              // palette capabilities
/* 1c*/ DWORD   dwSVCaps;               // stereo vision capabilities
/* 20*/ DWORD   dwAlphaBltConstBitDepths;       // DDBD_2,4,8
/* 24*/ DWORD   dwAlphaBltPixelBitDepths;       // DDBD_1,2,4,8
/* 28*/ DWORD   dwAlphaBltSurfaceBitDepths;     // DDBD_1,2,4,8
/* 2c*/ DWORD   dwAlphaOverlayConstBitDepths;   // DDBD_2,4,8
/* 30*/ DWORD   dwAlphaOverlayPixelBitDepths;   // DDBD_1,2,4,8
/* 34*/ DWORD   dwAlphaOverlaySurfaceBitDepths; // DDBD_1,2,4,8
/* 38*/ DWORD   dwZBufferBitDepths;             // DDBD_8,16,24,32
/* 3c*/ DWORD   dwVidMemTotal;          // total amount of video memory
/* 40*/ DWORD   dwVidMemFree;           // amount of free video memory
/* 44*/ DWORD   dwMaxVisibleOverlays;   // maximum number of visible overlays
/* 48*/ DWORD   dwCurrVisibleOverlays;  // current number of visible overlays
/* 4c*/ DWORD   dwNumFourCCCodes;       // number of four cc codes
/* 50*/ DWORD   dwAlignBoundarySrc;     // source rectangle alignment
/* 54*/ DWORD   dwAlignSizeSrc;         // source rectangle byte size
/* 58*/ DWORD   dwAlignBoundaryDest;    // dest rectangle alignment
/* 5c*/ DWORD   dwAlignSizeDest;        // dest rectangle byte size
/* 60*/ DWORD   dwAlignStrideAlign;     // stride alignment
/* 64*/ DWORD   dwRops[DD_ROP_SPACE];   // ROPS supported
/* 84*/ DDSCAPS ddsOldCaps;             // Was DDSCAPS  ddsCaps. ddsCaps is of type DDSCAPS2 for DX6
/* 88*/ DWORD   dwMinOverlayStretch;    // minimum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
/* 8c*/ DWORD   dwMaxOverlayStretch;    // maximum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
/* 90*/ DWORD   dwMinLiveVideoStretch;  // minimum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
/* 94*/ DWORD   dwMaxLiveVideoStretch;  // maximum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
/* 98*/ DWORD   dwMinHwCodecStretch;    // minimum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
/* 9c*/ DWORD   dwMaxHwCodecStretch;    // maximum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
/* a0*/ DWORD   dwReserved1;            // reserved
/* a4*/ DWORD   dwReserved2;            // reserved
/* a8*/ DWORD   dwReserved3;            // reserved
/* ac*/ DWORD   dwSVBCaps;              // driver specific capabilities for System->Vmem blts
/* b0*/ DWORD   dwSVBCKeyCaps;          // driver color key capabilities for System->Vmem blts
/* b4*/ DWORD   dwSVBFXCaps;            // driver FX capabilities for System->Vmem blts
/* b8*/ DWORD   dwSVBRops[DD_ROP_SPACE];// ROPS supported for System->Vmem blts
/* d8*/ DWORD   dwVSBCaps;              // driver specific capabilities for Vmem->System blts
/* dc*/ DWORD   dwVSBCKeyCaps;          // driver color key capabilities for Vmem->System blts
/* e0*/ DWORD   dwVSBFXCaps;            // driver FX capabilities for Vmem->System blts
/* e4*/ DWORD   dwVSBRops[DD_ROP_SPACE];// ROPS supported for Vmem->System blts
/*104*/ DWORD   dwSSBCaps;              // driver specific capabilities for System->System blts
/*108*/ DWORD   dwSSBCKeyCaps;          // driver color key capabilities for System->System blts
/*10c*/ DWORD   dwSSBFXCaps;            // driver FX capabilities for System->System blts
/*110*/ DWORD   dwSSBRops[DD_ROP_SPACE];// ROPS supported for System->System blts
/*130*/ DWORD   dwMaxVideoPorts;        // maximum number of usable video ports
/*134*/ DWORD   dwCurrVideoPorts;       // current number of video ports used
/*138*/ DWORD   dwSVBCaps2;             // more driver specific capabilities for System->Vmem blts
/*13c*/ DWORD   dwNLVBCaps;               // driver specific capabilities for non-local->local vidmem blts
/*140*/ DWORD   dwNLVBCaps2;              // more driver specific capabilities non-local->local vidmem blts
/*144*/ DWORD   dwNLVBCKeyCaps;           // driver color key capabilities for non-local->local vidmem blts
/*148*/ DWORD   dwNLVBFXCaps;             // driver FX capabilities for non-local->local blts
/*14c*/ DWORD   dwNLVBRops[DD_ROP_SPACE]; // ROPS supported for non-local->local blts
// Members added for DX6 release
/*16c*/ DDSCAPS2 ddsCaps;               // Surface Caps
} DDCAPS_DX7;
typedef DDCAPS_DX7 FAR* LPDDCAPS_DX7;


#if DIRECTDRAW_VERSION <= 0x300
    typedef DDCAPS_DX3 DDCAPS;
#elif DIRECTDRAW_VERSION <= 0x500
    typedef DDCAPS_DX5 DDCAPS;
#elif DIRECTDRAW_VERSION <= 0x600
    typedef DDCAPS_DX6 DDCAPS;
#else
    typedef DDCAPS_DX7 DDCAPS;
#endif

typedef DDCAPS FAR* LPDDCAPS;



/*
 * DDPIXELFORMAT
 */
typedef struct _DDPIXELFORMAT
{
    DWORD       dwSize;                 // size of structure
    DWORD       dwFlags;                // pixel format flags
    DWORD       dwFourCC;               // (FOURCC code)
    union
    {
        DWORD   dwRGBBitCount;          // how many bits per pixel
        DWORD   dwYUVBitCount;          // how many bits per pixel
        DWORD   dwZBufferBitDepth;      // how many total bits/pixel in z buffer (including any stencil bits)
        DWORD   dwAlphaBitDepth;        // how many bits for alpha channels
        DWORD   dwLuminanceBitCount;    // how many bits per pixel
        DWORD   dwBumpBitCount;         // how many bits per "buxel", total
        DWORD   dwPrivateFormatBitCount;// Bits per pixel of private driver formats. Only valid in texture
                                        // format list and if DDPF_D3DFORMAT is set
    } DUMMYUNIONNAMEN(1);
    union
    {
        DWORD   dwRBitMask;             // mask for red bit
        DWORD   dwYBitMask;             // mask for Y bits
        DWORD   dwStencilBitDepth;      // how many stencil bits (note: dwZBufferBitDepth-dwStencilBitDepth is total Z-only bits)
        DWORD   dwLuminanceBitMask;     // mask for luminance bits
        DWORD   dwBumpDuBitMask;        // mask for bump map U delta bits
        DWORD   dwOperations;           // DDPF_D3DFORMAT Operations
    } DUMMYUNIONNAMEN(2);
    union
    {
        DWORD   dwGBitMask;             // mask for green bits
        DWORD   dwUBitMask;             // mask for U bits
        DWORD   dwZBitMask;             // mask for Z bits
        DWORD   dwBumpDvBitMask;        // mask for bump map V delta bits
        struct
        {
            WORD    wFlipMSTypes;       // Multisample methods supported via flip for this D3DFORMAT
            WORD    wBltMSTypes;        // Multisample methods supported via blt for this D3DFORMAT
        } MultiSampleCaps;

    } DUMMYUNIONNAMEN(3);
    union
    {
        DWORD   dwBBitMask;             // mask for blue bits
        DWORD   dwVBitMask;             // mask for V bits
        DWORD   dwStencilBitMask;       // mask for stencil bits
        DWORD   dwBumpLuminanceBitMask; // mask for luminance in bump map
    } DUMMYUNIONNAMEN(4);
    union
    {
        DWORD   dwRGBAlphaBitMask;      // mask for alpha channel
        DWORD   dwYUVAlphaBitMask;      // mask for alpha channel
        DWORD   dwLuminanceAlphaBitMask;// mask for alpha channel
        DWORD   dwRGBZBitMask;          // mask for Z channel
        DWORD   dwYUVZBitMask;          // mask for Z channel
    } DUMMYUNIONNAMEN(5);
} DDPIXELFORMAT;

typedef DDPIXELFORMAT FAR* LPDDPIXELFORMAT;

/*
 * DDOVERLAYFX
 */
typedef struct _DDOVERLAYFX
{
    DWORD       dwSize;                         // size of structure
    DWORD       dwAlphaEdgeBlendBitDepth;       // Bit depth used to specify constant for alpha edge blend
    DWORD       dwAlphaEdgeBlend;               // Constant to use as alpha for edge blend
    DWORD       dwReserved;
    DWORD       dwAlphaDestConstBitDepth;       // Bit depth used to specify alpha constant for destination
    union
    {
        DWORD   dwAlphaDestConst;               // Constant to use as alpha channel for dest
        LPDIRECTDRAWSURFACE lpDDSAlphaDest;     // Surface to use as alpha channel for dest
    } DUMMYUNIONNAMEN(1);
    DWORD       dwAlphaSrcConstBitDepth;        // Bit depth used to specify alpha constant for source
    union
    {
        DWORD   dwAlphaSrcConst;                // Constant to use as alpha channel for src
        LPDIRECTDRAWSURFACE lpDDSAlphaSrc;      // Surface to use as alpha channel for src
    } DUMMYUNIONNAMEN(2);
    DDCOLORKEY  dckDestColorkey;                // DestColorkey override
    DDCOLORKEY  dckSrcColorkey;                 // DestColorkey override
    DWORD       dwDDFX;                         // Overlay FX
    DWORD       dwFlags;                        // flags
} DDOVERLAYFX;

typedef DDOVERLAYFX FAR *LPDDOVERLAYFX;


/*
 * DDBLTBATCH: BltBatch entry structure
 */
typedef struct _DDBLTBATCH
{
    LPRECT              lprDest;
    LPDIRECTDRAWSURFACE lpDDSSrc;
    LPRECT              lprSrc;
    DWORD               dwFlags;
    LPDDBLTFX           lpDDBltFx;
} DDBLTBATCH;

typedef DDBLTBATCH FAR * LPDDBLTBATCH;


/*
 * DDGAMMARAMP
 */
typedef struct _DDGAMMARAMP
{
    WORD                red[256];
    WORD                green[256];
    WORD                blue[256];
} DDGAMMARAMP;
typedef DDGAMMARAMP FAR * LPDDGAMMARAMP;

/*
 *  This is the structure within which DirectDraw returns data about the current graphics driver and chipset
 */

#define MAX_DDDEVICEID_STRING           512

typedef struct tagDDDEVICEIDENTIFIER
{
    /*
     * These elements are for presentation to the user only. They should not be used to identify particular
     * drivers, since this is unreliable and many different strings may be associated with the same
     * device, and the same driver from different vendors.
     */
    char    szDriver[MAX_DDDEVICEID_STRING];
    char    szDescription[MAX_DDDEVICEID_STRING];

    /*
     * This element is the version of the DirectDraw/3D driver. It is legal to do <, > comparisons
     * on the whole 64 bits. Caution should be exercised if you use this element to identify problematic
     * drivers. It is recommended that guidDeviceIdentifier is used for this purpose.
     *
     * This version has the form:
     *  wProduct = HIWORD(liDriverVersion.HighPart)
     *  wVersion = LOWORD(liDriverVersion.HighPart)
     *  wSubVersion = HIWORD(liDriverVersion.LowPart)
     *  wBuild = LOWORD(liDriverVersion.LowPart)
     */
#ifdef _WIN32
    LARGE_INTEGER liDriverVersion;      /* Defined for applications and other 32 bit components */
#else
    DWORD   dwDriverVersionLowPart;     /* Defined for 16 bit driver components */
    DWORD   dwDriverVersionHighPart;
#endif


    /*
     * These elements can be used to identify particular chipsets. Use with extreme caution.
     *   dwVendorId     Identifies the manufacturer. May be zero if unknown.
     *   dwDeviceId     Identifies the type of chipset. May be zero if unknown.
     *   dwSubSysId     Identifies the subsystem, typically this means the particular board. May be zero if unknown.
     *   dwRevision     Identifies the revision level of the chipset. May be zero if unknown.
     */
    DWORD   dwVendorId;
    DWORD   dwDeviceId;
    DWORD   dwSubSysId;
    DWORD   dwRevision;

    /*
     * This element can be used to check changes in driver/chipset. This GUID is a unique identifier for the
     * driver/chipset pair. Use this element if you wish to track changes to the driver/chipset in order to
     * reprofile the graphics subsystem.
     * This element can also be used to identify particular problematic drivers.
     */
    GUID    guidDeviceIdentifier;
} DDDEVICEIDENTIFIER, * LPDDDEVICEIDENTIFIER;

typedef struct tagDDDEVICEIDENTIFIER2
{
    /*
     * These elements are for presentation to the user only. They should not be used to identify particular
     * drivers, since this is unreliable and many different strings may be associated with the same
     * device, and the same driver from different vendors.
     */
    char    szDriver[MAX_DDDEVICEID_STRING];
    char    szDescription[MAX_DDDEVICEID_STRING];

    /*
     * This element is the version of the DirectDraw/3D driver. It is legal to do <, > comparisons
     * on the whole 64 bits. Caution should be exercised if you use this element to identify problematic
     * drivers. It is recommended that guidDeviceIdentifier is used for this purpose.
     *
     * This version has the form:
     *  wProduct = HIWORD(liDriverVersion.HighPart)
     *  wVersion = LOWORD(liDriverVersion.HighPart)
     *  wSubVersion = HIWORD(liDriverVersion.LowPart)
     *  wBuild = LOWORD(liDriverVersion.LowPart)
     */
#ifdef _WIN32
    LARGE_INTEGER liDriverVersion;      /* Defined for applications and other 32 bit components */
#else
    DWORD   dwDriverVersionLowPart;     /* Defined for 16 bit driver components */
    DWORD   dwDriverVersionHighPart;
#endif


    /*
     * These elements can be used to identify particular chipsets. Use with extreme caution.
     *   dwVendorId     Identifies the manufacturer. May be zero if unknown.
     *   dwDeviceId     Identifies the type of chipset. May be zero if unknown.
     *   dwSubSysId     Identifies the subsystem, typically this means the particular board. May be zero if unknown.
     *   dwRevision     Identifies the revision level of the chipset. May be zero if unknown.
     */
    DWORD   dwVendorId;
    DWORD   dwDeviceId;
    DWORD   dwSubSysId;
    DWORD   dwRevision;

    /*
     * This element can be used to check changes in driver/chipset. This GUID is a unique identifier for the
     * driver/chipset pair. Use this element if you wish to track changes to the driver/chipset in order to
     * reprofile the graphics subsystem.
     * This element can also be used to identify particular problematic drivers.
     */
    GUID    guidDeviceIdentifier;

    /*
     * This element is used to determine the Windows Hardware Quality Lab (WHQL)
     * certification level for this driver/device pair.
     */
    DWORD   dwWHQLLevel;

} DDDEVICEIDENTIFIER2, * LPDDDEVICEIDENTIFIER2;

/*
 * Flags for the IDirectDraw4::GetDeviceIdentifier method
 */

/*
 * This flag causes GetDeviceIdentifier to return information about the host (typically 2D) adapter in a system equipped
 * with a stacked secondary 3D adapter. Such an adapter appears to the application as if it were part of the
 * host adapter, but is typically physcially located on a separate card. The stacked secondary's information is
 * returned when GetDeviceIdentifier's dwFlags field is zero, since this most accurately reflects the qualities
 * of the DirectDraw object involved.
 */
#define DDGDI_GETHOSTIDENTIFIER         0x00000001L

/*
 * Macros for interpretting DDEVICEIDENTIFIER2.dwWHQLLevel
 */
#define GET_WHQL_YEAR( dwWHQLLevel ) \
    ( (dwWHQLLevel) / 0x10000 )
#define GET_WHQL_MONTH( dwWHQLLevel ) \
    ( ( (dwWHQLLevel) / 0x100 ) & 0x00ff )
#define GET_WHQL_DAY( dwWHQLLevel ) \
    ( (dwWHQLLevel) & 0xff )


/*
 * callbacks
 */
typedef DWORD   (FAR PASCAL *LPCLIPPERCALLBACK)(LPDIRECTDRAWCLIPPER lpDDClipper, HWND hWnd, DWORD code, LPVOID lpContext );
#ifdef STREAMING
typedef DWORD   (FAR PASCAL *LPSURFACESTREAMINGCALLBACK)(DWORD);
#endif


/*
 * INTERACES FOLLOW:
 *      IDirectDraw
 *      IDirectDrawClipper
 *      IDirectDrawPalette
 *      IDirectDrawSurface
 */

/*
 * IDirectDraw
 */
#if defined( _WIN32 ) && !defined( _NO_COM )
#undef INTERFACE
#define INTERFACE IDirectDraw
DECLARE_INTERFACE_( IDirectDraw, IUnknown )
{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    /*** IDirectDraw methods ***/
    STDMETHOD(Compact)(THIS) PURE;
    STDMETHOD(CreateClipper)(THIS_ DWORD, LPDIRECTDRAWCLIPPER FAR*, IUnknown FAR * ) PURE;
    STDMETHOD(CreatePalette)(THIS_ DWORD, LPPALETTEENTRY, LPDIRECTDRAWPALETTE FAR*, IUnknown FAR * ) PURE;
    STDMETHOD(CreateSurface)(THIS_  LPDDSURFACEDESC, LPDIRECTDRAWSURFACE FAR *, IUnknown FAR *) PURE;
    STDMETHOD(DuplicateSurface)( THIS_ LPDIRECTDRAWSURFACE, LPDIRECTDRAWSURFACE FAR * ) PURE;
    STDMETHOD(EnumDisplayModes)( THIS_ DWORD, LPDDSURFACEDESC, LPVOID, LPDDENUMMODESCALLBACK ) PURE;
    STDMETHOD(EnumSurfaces)(THIS_ DWORD, LPDDSURFACEDESC, LPVOID,LPDDENUMSURFACESCALLBACK ) PURE;
    STDMETHOD(FlipToGDISurface)(THIS) PURE;
    STDMETHOD(GetCaps)( THIS_ LPDDCAPS, LPDDCAPS) PURE;
    STDMETHOD(GetDisplayMode)( THIS_ LPDDSURFACEDESC) PURE;
    STDMETHOD(GetFourCCCodes)(THIS_  LPDWORD, LPDWORD ) PURE;
    STDMETHOD(GetGDISurface)(THIS_ LPDIRECTDRAWSURFACE FAR *) PURE;
    STDMETHOD(GetMonitorFrequency)(THIS_ LPDWORD) PURE;
    STDMETHOD(GetScanLine)(THIS_ LPDWORD) PURE;
    STDMETHOD(GetVerticalBlankStatus)(THIS_ LPBOOL ) PURE;
    STDMETHOD(Initialize)(THIS_ GUID FAR *) PURE;
    STDMETHOD(RestoreDisplayMode)(THIS) PURE;
    STDMETHOD(SetCooperativeLevel)(THIS_ HWND, DWORD) PURE;
    STDMETHOD(SetDisplayMode)(THIS_ DWORD, DWORD,DWORD) PURE;
    STDMETHOD(WaitForVerticalBlank)(THIS_ DWORD, HANDLE ) PURE;
};

#if !defined(__cplusplus) || defined(CINTERFACE)
#define IDirectDraw_QueryInterface(p, a, b)         (p)->lpVtbl->QueryInterface(p, a, b)
#define IDirectDraw_AddRef(p)                       (p)->lpVtbl->AddRef(p)
#define IDirectDraw_Release(p)                      (p)->lpVtbl->Release(p)
#define IDirectDraw_Compact(p)                      (p)->lpVtbl->Compact(p)
#define IDirectDraw_CreateClipper(p, a, b, c)       (p)->lpVtbl->CreateClipper(p, a, b, c)
#define IDirectDraw_CreatePalette(p, a, b, c, d)    (p)->lpVtbl->CreatePalette(p, a, b, c, d)
#define IDirectDraw_CreateSurface(p, a, b, c)       (p)->lpVtbl->CreateSurface(p, a, b, c)
#define IDirectDraw_DuplicateSurface(p, a, b)       (p)->lpVtbl->DuplicateSurface(p, a, b)
#define IDirectDraw_EnumDisplayModes(p, a, b, c, d) (p)->lpVtbl->EnumDisplayModes(p, a, b, c, d)
#define IDirectDraw_EnumSurfaces(p, a, b, c, d)     (p)->lpVtbl->EnumSurfaces(p, a, b, c, d)
#define IDirectDraw_FlipToGDISurface(p)             (p)->lpVtbl->FlipToGDISurface(p)
#define IDirectDraw_GetCaps(p, a, b)                (p)->lpVtbl->GetCaps(p, a, b)
#define IDirectDraw_GetDisplayMode(p, a)            (p)->lpVtbl->GetDisplayMode(p, a)
#define IDirectDraw_GetFourCCCodes(p, a, b)         (p)->lpVtbl->GetFourCCCodes(p, a, b)
#define IDirectDraw_GetGDISurface(p, a)             (p)->lpVtbl->GetGDISurface(p, a)
#define IDirectDraw_GetMonitorFrequency(p, a)       (p)->lpVtbl->GetMonitorFrequency(p, a)
#define IDirectDraw_GetScanLine(p, a)               (p)->lpVtbl->GetScanLine(p, a)
#define IDirectDraw_GetVerticalBlankStatus(p, a)    (p)->lpVtbl->GetVerticalBlankStatus(p, a)
#define IDirectDraw_Initialize(p, a)                (p)->lpVtbl->Initialize(p, a)
#define IDirectDraw_RestoreDisplayMode(p)           (p)->lpVtbl->RestoreDisplayMode(p)
#define IDirectDraw_SetCooperativeLevel(p, a, b)    (p)->lpVtbl->SetCooperativeLevel(p, a, b)
#define IDirectDraw_SetDisplayMode(p, a, b, c)      (p)->lpVtbl->SetDisplayMode(p, a, b, c)
#define IDirectDraw_WaitForVerticalBlank(p, a, b)   (p)->lpVtbl->WaitForVerticalBlank(p, a, b)
#else
#define IDirectDraw_QueryInterface(p, a, b)         (p)->QueryInterface(a, b)
#define IDirectDraw_AddRef(p)                       (p)->AddRef()
#define IDirectDraw_Release(p)                      (p)->Release()
#define IDirectDraw_Compact(p)                      (p)->Compact()
#define IDirectDraw_CreateClipper(p, a, b, c)       (p)->CreateClipper(a, b, c)
#define IDirectDraw_CreatePalette(p, a, b, c, d)    (p)->CreatePalette(a, b, c, d)
#define IDirectDraw_CreateSurface(p, a, b, c)       (p)->CreateSurface(a, b, c)
#define IDirectDraw_DuplicateSurface(p, a, b)       (p)->DuplicateSurface(a, b)
#define IDirectDraw_EnumDisplayModes(p, a, b, c, d) (p)->EnumDisplayModes(a, b, c, d)
#define IDirectDraw_EnumSurfaces(p, a, b, c, d)     (p)->EnumSurfaces(a, b, c, d)
#define IDirectDraw_FlipToGDISurface(p)             (p)->FlipToGDISurface()
#define IDirectDraw_GetCaps(p, a, b)                (p)->GetCaps(a, b)
#define IDirectDraw_GetDisplayMode(p, a)            (p)->GetDisplayMode(a)
#define IDirectDraw_GetFourCCCodes(p, a, b)         (p)->GetFourCCCodes(a, b)
#define IDirectDraw_GetGDISurface(p, a)             (p)->GetGDISurface(a)
#define IDirectDraw_GetMonitorFrequency(p, a)       (p)->GetMonitorFrequency(a)
#define IDirectDraw_GetScanLine(p, a)               (p)->GetScanLine(a)
#define IDirectDraw_GetVerticalBlankStatus(p, a)    (p)->GetVerticalBlankStatus(a)
#define IDirectDraw_Initialize(p, a)                (p)->Initialize(a)
#define IDirectDraw_RestoreDisplayMode(p)           (p)->RestoreDisplayMode()
#define IDirectDraw_SetCooperativeLevel(p, a, b)    (p)->SetCooperativeLevel(a, b)
#define IDirectDraw_SetDisplayMode(p, a, b, c)      (p)->SetDisplayMode(a, b, c)
#define IDirectDraw_WaitForVerticalBlank(p, a, b)   (p)->WaitForVerticalBlank(a, b)
#endif

#endif

#if defined( _WIN32 ) && !defined( _NO_COM )
#undef INTERFACE
#define INTERFACE IDirectDraw2
DECLARE_INTERFACE_( IDirectDraw2, IUnknown )
{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    /*** IDirectDraw methods ***/
    STDMETHOD(Compact)(THIS) PURE;
    STDMETHOD(CreateClipper)(THIS_ DWORD, LPDIRECTDRAWCLIPPER FAR*, IUnknown FAR * ) PURE;
    STDMETHOD(CreatePalette)(THIS_ DWORD, LPPALETTEENTRY, LPDIRECTDRAWPALETTE FAR*, IUnknown FAR * ) PURE;
    STDMETHOD(CreateSurface)(THIS_  LPDDSURFACEDESC, LPDIRECTDRAWSURFACE FAR *, IUnknown FAR *) PURE;
    STDMETHOD(DuplicateSurface)( THIS_ LPDIRECTDRAWSURFACE, LPDIRECTDRAWSURFACE FAR * ) PURE;
    STDMETHOD(EnumDisplayModes)( THIS_ DWORD, LPDDSURFACEDESC, LPVOID, LPDDENUMMODESCALLBACK ) PURE;
    STDMETHOD(EnumSurfaces)(THIS_ DWORD, LPDDSURFACEDESC, LPVOID,LPDDENUMSURFACESCALLBACK ) PURE;
    STDMETHOD(FlipToGDISurface)(THIS) PURE;
    STDMETHOD(GetCaps)( THIS_ LPDDCAPS, LPDDCAPS) PURE;
    STDMETHOD(GetDisplayMode)( THIS_ LPDDSURFACEDESC) PURE;
    STDMETHOD(GetFourCCCodes)(THIS_  LPDWORD, LPDWORD ) PURE;
    STDMETHOD(GetGDISurface)(THIS_ LPDIRECTDRAWSURFACE FAR *) PURE;
    STDMETHOD(GetMonitorFrequency)(THIS_ LPDWORD) PURE;
    STDMETHOD(GetScanLine)(THIS_ LPDWORD) PURE;
    STDMETHOD(GetVerticalBlankStatus)(THIS_ LPBOOL ) PURE;
    STDMETHOD(Initialize)(THIS_ GUID FAR *) PURE;
    STDMETHOD(RestoreDisplayMode)(THIS) PURE;
    STDMETHOD(SetCooperativeLevel)(THIS_ HWND, DWORD) PURE;
    STDMETHOD(SetDisplayMode)(THIS_ DWORD, DWORD,DWORD, DWORD, DWORD) PURE;
    STDMETHOD(WaitForVerticalBlank)(THIS_ DWORD, HANDLE ) PURE;
    /*** Added in the v2 interface ***/
    STDMETHOD(GetAvailableVidMem)(THIS_ LPDDSCAPS, LPDWORD, LPDWORD) PURE;
};
#if !defined(__cplusplus) || defined(CINTERFACE)
#define IDirectDraw2_QueryInterface(p, a, b)         (p)->lpVtbl->QueryInterface(p, a, b)
#define IDirectDraw2_AddRef(p)                       (p)->lpVtbl->AddRef(p)
#define IDirectDraw2_Release(p)                      (p)->lpVtbl->Release(p)
#define IDirectDraw2_Compact(p)                      (p)->lpVtbl->Compact(p)
#define IDirectDraw2_CreateClipper(p, a, b, c)       (p)->lpVtbl->CreateClipper(p, a, b, c)
#define IDirectDraw2_CreatePalette(p, a, b, c, d)    (p)->lpVtbl->CreatePalette(p, a, b, c, d)
#define IDirectDraw2_CreateSurface(p, a, b, c)       (p)->lpVtbl->CreateSurface(p, a, b, c)
#define IDirectDraw2_DuplicateSurface(p, a, b)       (p)->lpVtbl->DuplicateSurface(p, a, b)
#define IDirectDraw2_EnumDisplayModes(p, a, b, c, d) (p)->lpVtbl->EnumDisplayModes(p, a, b, c, d)
#define IDirectDraw2_EnumSurfaces(p, a, b, c, d)     (p)->lpVtbl->EnumSurfaces(p, a, b, c, d)
#define IDirectDraw2_FlipToGDISurface(p)             (p)->lpVtbl->FlipToGDISurface(p)
#define IDirectDraw2_GetCaps(p, a, b)                (p)->lpVtbl->GetCaps(p, a, b)
#define IDirectDraw2_GetDisplayMode(p, a)            (p)->lpVtbl->GetDisplayMode(p, a)
#define IDirectDraw2_GetFourCCCodes(p, a, b)         (p)->lpVtbl->GetFourCCCodes(p, a, b)
#define IDirectDraw2_GetGDISurface(p, a)             (p)->lpVtbl->GetGDISurface(p, a)
#define IDirectDraw2_GetMonitorFrequency(p, a)       (p)->lpVtbl->GetMonitorFrequency(p, a)
#define IDirectDraw2_GetScanLine(p, a)               (p)->lpVtbl->GetScanLine(p, a)
#define IDirectDraw2_GetVerticalBlankStatus(p, a)    (p)->lpVtbl->GetVerticalBlankStatus(p, a)
#define IDirectDraw2_Initialize(p, a)                (p)->lpVtbl->Initialize(p, a)
#define IDirectDraw2_RestoreDisplayMode(p)           (p)->lpVtbl->RestoreDisplayMode(p)
#define IDirectDraw2_SetCooperativeLevel(p, a, b)    (p)->lpVtbl->SetCooperativeLevel(p, a, b)
#define IDirectDraw2_SetDisplayMode(p, a, b, c, d, e) (p)->lpVtbl->SetDisplayMode(p, a, b, c, d, e)
#define IDirectDraw2_WaitForVerticalBlank(p, a, b)   (p)->lpVtbl->WaitForVerticalBlank(p, a, b)
#define IDirectDraw2_GetAvailableVidMem(p, a, b, c)  (p)->lpVtbl->GetAvailableVidMem(p, a, b, c)
#else
#define IDirectDraw2_QueryInterface(p, a, b)         (p)->QueryInterface(a, b)
#define IDirectDraw2_AddRef(p)                       (p)->AddRef()
#define IDirectDraw2_Release(p)                      (p)->Release()
#define IDirectDraw2_Compact(p)                      (p)->Compact()
#define IDirectDraw2_CreateClipper(p, a, b, c)       (p)->CreateClipper(a, b, c)
#define IDirectDraw2_CreatePalette(p, a, b, c, d)    (p)->CreatePalette(a, b, c, d)
#define IDirectDraw2_CreateSurface(p, a, b, c)       (p)->CreateSurface(a, b, c)
#define IDirectDraw2_DuplicateSurface(p, a, b)       (p)->DuplicateSurface(a, b)
#define IDirectDraw2_EnumDisplayModes(p, a, b, c, d) (p)->EnumDisplayModes(a, b, c, d)
#define IDirectDraw2_EnumSurfaces(p, a, b, c, d)     (p)->EnumSurfaces(a, b, c, d)
#define IDirectDraw2_FlipToGDISurface(p)             (p)->FlipToGDISurface()
#define IDirectDraw2_GetCaps(p, a, b)                (p)->GetCaps(a, b)
#define IDirectDraw2_GetDisplayMode(p, a)            (p)->GetDisplayMode(a)
#define IDirectDraw2_GetFourCCCodes(p, a, b)         (p)->GetFourCCCodes(a, b)
#define IDirectDraw2_GetGDISurface(p, a)             (p)->GetGDISurface(a)
#define IDirectDraw2_GetMonitorFrequency(p, a)       (p)->GetMonitorFrequency(a)
#define IDirectDraw2_GetScanLine(p, a)               (p)->GetScanLine(a)
#define IDirectDraw2_GetVerticalBlankStatus(p, a)    (p)->GetVerticalBlankStatus(a)
#define IDirectDraw2_Initialize(p, a)                (p)->Initialize(a)
#define IDirectDraw2_RestoreDisplayMode(p)           (p)->RestoreDisplayMode()
#define IDirectDraw2_SetCooperativeLevel(p, a, b)    (p)->SetCooperativeLevel(a, b)
#define IDirectDraw2_SetDisplayMode(p, a, b, c, d, e) (p)->SetDisplayMode(a, b, c, d, e)
#define IDirectDraw2_WaitForVerticalBlank(p, a, b)   (p)->WaitForVerticalBlank(a, b)
#define IDirectDraw2_GetAvailableVidMem(p, a, b, c)  (p)->GetAvailableVidMem(a, b, c)
#endif

#endif

#if defined( _WIN32 ) && !defined( _NO_COM )
#undef INTERFACE
#define INTERFACE IDirectDraw4
DECLARE_INTERFACE_( IDirectDraw4, IUnknown )
{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    /*** IDirectDraw methods ***/
    STDMETHOD(Compact)(THIS) PURE;
    STDMETHOD(CreateClipper)(THIS_ DWORD, LPDIRECTDRAWCLIPPER FAR*, IUnknown FAR * ) PURE;
    STDMETHOD(CreatePalette)(THIS_ DWORD, LPPALETTEENTRY, LPDIRECTDRAWPALETTE FAR*, IUnknown FAR * ) PURE;
    STDMETHOD(CreateSurface)(THIS_  LPDDSURFACEDESC2, LPDIRECTDRAWSURFACE4 FAR *, IUnknown FAR *) PURE;
    STDMETHOD(DuplicateSurface)( THIS_ LPDIRECTDRAWSURFACE4, LPDIRECTDRAWSURFACE4 FAR * ) PURE;
    STDMETHOD(EnumDisplayModes)( THIS_ DWORD, LPDDSURFACEDESC2, LPVOID, LPDDENUMMODESCALLBACK2 ) PURE;
    STDMETHOD(EnumSurfaces)(THIS_ DWORD, LPDDSURFACEDESC2, LPVOID,LPDDENUMSURFACESCALLBACK2 ) PURE;
    STDMETHOD(FlipToGDISurface)(THIS) PURE;
    STDMETHOD(GetCaps)( THIS_ LPDDCAPS, LPDDCAPS) PURE;
    STDMETHOD(GetDisplayMode)( THIS_ LPDDSURFACEDESC2) PURE;
    STDMETHOD(GetFourCCCodes)(THIS_  LPDWORD, LPDWORD ) PURE;
    STDMETHOD(GetGDISurface)(THIS_ LPDIRECTDRAWSURFACE4 FAR *) PURE;
    STDMETHOD(GetMonitorFrequency)(THIS_ LPDWORD) PURE;
    STDMETHOD(GetScanLine)(THIS_ LPDWORD) PURE;
    STDMETHOD(GetVerticalBlankStatus)(THIS_ LPBOOL ) PURE;
    STDMETHOD(Initialize)(THIS_ GUID FAR *) PURE;
    STDMETHOD(RestoreDisplayMode)(THIS) PURE;
    STDMETHOD(SetCooperativeLevel)(THIS_ HWND, DWORD) PURE;
    STDMETHOD(SetDisplayMode)(THIS_ DWORD, DWORD,DWORD, DWORD, DWORD) PURE;
    STDMETHOD(WaitForVerticalBlank)(THIS_ DWORD, HANDLE ) PURE;
    /*** Added in the v2 interface ***/
    STDMETHOD(GetAvailableVidMem)(THIS_ LPDDSCAPS2, LPDWORD, LPDWORD) PURE;
    /*** Added in the V4 Interface ***/
    STDMETHOD(GetSurfaceFromDC) (THIS_ HDC, LPDIRECTDRAWSURFACE4 *) PURE;
    STDMETHOD(RestoreAllSurfaces)(THIS) PURE;
    STDMETHOD(TestCooperativeLevel)(THIS) PURE;
    STDMETHOD(GetDeviceIdentifier)(THIS_ LPDDDEVICEIDENTIFIER, DWORD ) PURE;
};
#if !defined(__cplusplus) || defined(CINTERFACE)
#define IDirectDraw4_QueryInterface(p, a, b)         (p)->lpVtbl->QueryInterface(p, a, b)
#define IDirectDraw4_AddRef(p)                       (p)->lpVtbl->AddRef(p)
#define IDirectDraw4_Release(p)                      (p)->lpVtbl->Release(p)
#define IDirectDraw4_Compact(p)                      (p)->lpVtbl->Compact(p)
#define IDirectDraw4_CreateClipper(p, a, b, c)       (p)->lpVtbl->CreateClipper(p, a, b, c)
#define IDirectDraw4_CreatePalette(p, a, b, c, d)    (p)->lpVtbl->CreatePalette(p, a, b, c, d)
#define IDirectDraw4_CreateSurface(p, a, b, c)       (p)->lpVtbl->CreateSurface(p, a, b, c)
#define IDirectDraw4_DuplicateSurface(p, a, b)       (p)->lpVtbl->DuplicateSurface(p, a, b)
#define IDirectDraw4_EnumDisplayModes(p, a, b, c, d) (p)->lpVtbl->EnumDisplayModes(p, a, b, c, d)
#define IDirectDraw4_EnumSurfaces(p, a, b, c, d)     (p)->lpVtbl->EnumSurfaces(p, a, b, c, d)
#define IDirectDraw4_FlipToGDISurface(p)             (p)->lpVtbl->FlipToGDISurface(p)
#define IDirectDraw4_GetCaps(p, a, b)                (p)->lpVtbl->GetCaps(p, a, b)
#define IDirectDraw4_GetDisplayMode(p, a)            (p)->lpVtbl->GetDisplayMode(p, a)
#define IDirectDraw4_GetFourCCCodes(p, a, b)         (p)->lpVtbl->GetFourCCCodes(p, a, b)
#define IDirectDraw4_GetGDISurface(p, a)             (p)->lpVtbl->GetGDISurface(p, a)
#define IDirectDraw4_GetMonitorFrequency(p, a)       (p)->lpVtbl->GetMonitorFrequency(p, a)
#define IDirectDraw4_GetScanLine(p, a)               (p)->lpVtbl->GetScanLine(p, a)
#define IDirectDraw4_GetVerticalBlankStatus(p, a)    (p)->lpVtbl->GetVerticalBlankStatus(p, a)
#define IDirectDraw4_Initialize(p, a)                (p)->lpVtbl->Initialize(p, a)
#define IDirectDraw4_RestoreDisplayMode(p)           (p)->lpVtbl->RestoreDisplayMode(p)
#define IDirectDraw4_SetCooperativeLevel(p, a, b)    (p)->lpVtbl->SetCooperativeLevel(p, a, b)
#define IDirectDraw4_SetDisplayMode(p, a, b, c, d, e) (p)->lpVtbl->SetDisplayMode(p, a, b, c, d, e)
#define IDirectDraw4_WaitForVerticalBlank(p, a, b)   (p)->lpVtbl->WaitForVerticalBlank(p, a, b)
#define IDirectDraw4_GetAvailableVidMem(p, a, b, c)  (p)->lpVtbl->GetAvailableVidMem(p, a, b, c)
#define IDirectDraw4_GetSurfaceFromDC(p, a, b)       (p)->lpVtbl->GetSurfaceFromDC(p, a, b)
#define IDirectDraw4_RestoreAllSurfaces(p)           (p)->lpVtbl->RestoreAllSurfaces(p)
#define IDirectDraw4_TestCooperativeLevel(p)         (p)->lpVtbl->TestCooperativeLevel(p)
#define IDirectDraw4_GetDeviceIdentifier(p,a,b)      (p)->lpVtbl->GetDeviceIdentifier(p,a,b)
#else
#define IDirectDraw4_QueryInterface(p, a, b)         (p)->QueryInterface(a, b)
#define IDirectDraw4_AddRef(p)                       (p)->AddRef()
#define IDirectDraw4_Release(p)                      (p)->Release()
#define IDirectDraw4_Compact(p)                      (p)->Compact()
#define IDirectDraw4_CreateClipper(p, a, b, c)       (p)->CreateClipper(a, b, c)
#define IDirectDraw4_CreatePalette(p, a, b, c, d)    (p)->CreatePalette(a, b, c, d)
#define IDirectDraw4_CreateSurface(p, a, b, c)       (p)->CreateSurface(a, b, c)
#define IDirectDraw4_DuplicateSurface(p, a, b)       (p)->DuplicateSurface(a, b)
#define IDirectDraw4_EnumDisplayModes(p, a, b, c, d) (p)->EnumDisplayModes(a, b, c, d)
#define IDirectDraw4_EnumSurfaces(p, a, b, c, d)     (p)->EnumSurfaces(a, b, c, d)
#define IDirectDraw4_FlipToGDISurface(p)             (p)->FlipToGDISurface()
#define IDirectDraw4_GetCaps(p, a, b)                (p)->GetCaps(a, b)
#define IDirectDraw4_GetDisplayMode(p, a)            (p)->GetDisplayMode(a)
#define IDirectDraw4_GetFourCCCodes(p, a, b)         (p)->GetFourCCCodes(a, b)
#define IDirectDraw4_GetGDISurface(p, a)             (p)->GetGDISurface(a)
#define IDirectDraw4_GetMonitorFrequency(p, a)       (p)->GetMonitorFrequency(a)
#define IDirectDraw4_GetScanLine(p, a)               (p)->GetScanLine(a)
#define IDirectDraw4_GetVerticalBlankStatus(p, a)    (p)->GetVerticalBlankStatus(a)
#define IDirectDraw4_Initialize(p, a)                (p)->Initialize(a)
#define IDirectDraw4_RestoreDisplayMode(p)           (p)->RestoreDisplayMode()
#define IDirectDraw4_SetCooperativeLevel(p, a, b)    (p)->SetCooperativeLevel(a, b)
#define IDirectDraw4_SetDisplayMode(p, a, b, c, d, e) (p)->SetDisplayMode(a, b, c, d, e)
#define IDirectDraw4_WaitForVerticalBlank(p, a, b)   (p)->WaitForVerticalBlank(a, b)
#define IDirectDraw4_GetAvailableVidMem(p, a, b, c)  (p)->GetAvailableVidMem(a, b, c)
#define IDirectDraw4_GetSurfaceFromDC(p, a, b)       (p)->GetSurfaceFromDC(a, b)
#define IDirectDraw4_RestoreAllSurfaces(p)           (p)->RestoreAllSurfaces()
#define IDirectDraw4_TestCooperativeLevel(p)         (p)->TestCooperativeLevel()
#define IDirectDraw4_GetDeviceIdentifier(p,a,b)      (p)->GetDeviceIdentifier(a,b)
#endif

#endif

#if defined( _WIN32 ) && !defined( _NO_COM )
#undef INTERFACE
#define INTERFACE IDirectDraw7
DECLARE_INTERFACE_( IDirectDraw7, IUnknown )
{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    /*** IDirectDraw methods ***/
    STDMETHOD(Compact)(THIS) PURE;
    STDMETHOD(CreateClipper)(THIS_ DWORD, LPDIRECTDRAWCLIPPER FAR*, IUnknown FAR * ) PURE;
    STDMETHOD(CreatePalette)(THIS_ DWORD, LPPALETTEENTRY, LPDIRECTDRAWPALETTE FAR*, IUnknown FAR * ) PURE;
    STDMETHOD(CreateSurface)(THIS_  LPDDSURFACEDESC2, LPDIRECTDRAWSURFACE7 FAR *, IUnknown FAR *) PURE;
    STDMETHOD(DuplicateSurface)( THIS_ LPDIRECTDRAWSURFACE7, LPDIRECTDRAWSURFACE7 FAR * ) PURE;
    STDMETHOD(EnumDisplayModes)( THIS_ DWORD, LPDDSURFACEDESC2, LPVOID, LPDDENUMMODESCALLBACK2 ) PURE;
    STDMETHOD(EnumSurfaces)(THIS_ DWORD, LPDDSURFACEDESC2, LPVOID,LPDDENUMSURFACESCALLBACK7 ) PURE;
    STDMETHOD(FlipToGDISurface)(THIS) PURE;
    STDMETHOD(GetCaps)( THIS_ LPDDCAPS, LPDDCAPS) PURE;
    STDMETHOD(GetDisplayMode)( THIS_ LPDDSURFACEDESC2) PURE;
    STDMETHOD(GetFourCCCodes)(THIS_  LPDWORD, LPDWORD ) PURE;
    STDMETHOD(GetGDISurface)(THIS_ LPDIRECTDRAWSURFACE7 FAR *) PURE;
    STDMETHOD(GetMonitorFrequency)(THIS_ LPDWORD) PURE;
    STDMETHOD(GetScanLine)(THIS_ LPDWORD) PURE;
    STDMETHOD(GetVerticalBlankStatus)(THIS_ LPBOOL ) PURE;
    STDMETHOD(Initialize)(THIS_ GUID FAR *) PURE;
    STDMETHOD(RestoreDisplayMode)(THIS) PURE;
    STDMETHOD(SetCooperativeLevel)(THIS_ HWND, DWORD) PURE;
    STDMETHOD(SetDisplayMode)(THIS_ DWORD, DWORD,DWORD, DWORD, DWORD) PURE;
    STDMETHOD(WaitForVerticalBlank)(THIS_ DWORD, HANDLE ) PURE;
    /*** Added in the v2 interface ***/
    STDMETHOD(GetAvailableVidMem)(THIS_ LPDDSCAPS2, LPDWORD, LPDWORD) PURE;
    /*** Added in the V4 Interface ***/
    STDMETHOD(GetSurfaceFromDC) (THIS_ HDC, LPDIRECTDRAWSURFACE7 *) PURE;
    STDMETHOD(RestoreAllSurfaces)(THIS) PURE;
    STDMETHOD(TestCooperativeLevel)(THIS) PURE;
    STDMETHOD(GetDeviceIdentifier)(THIS_ LPDDDEVICEIDENTIFIER2, DWORD ) PURE;
    STDMETHOD(StartModeTest)(THIS_ LPSIZE, DWORD, DWORD ) PURE;
    STDMETHOD(EvaluateMode)(THIS_ DWORD, DWORD * ) PURE;
};
#if !defined(__cplusplus) || defined(CINTERFACE)
#define IDirectDraw7_QueryInterface(p, a, b)         (p)->lpVtbl->QueryInterface(p, a, b)
#define IDirectDraw7_AddRef(p)                       (p)->lpVtbl->AddRef(p)
#define IDirectDraw7_Release(p)                      (p)->lpVtbl->Release(p)
#define IDirectDraw7_Compact(p)                      (p)->lpVtbl->Compact(p)
#define IDirectDraw7_CreateClipper(p, a, b, c)       (p)->lpVtbl->CreateClipper(p, a, b, c)
#define IDirectDraw7_CreatePalette(p, a, b, c, d)    (p)->lpVtbl->CreatePalette(p, a, b, c, d)
#define IDirectDraw7_CreateSurface(p, a, b, c)       (p)->lpVtbl->CreateSurface(p, a, b, c)
#define IDirectDraw7_DuplicateSurface(p, a, b)       (p)->lpVtbl->DuplicateSurface(p, a, b)
#define IDirectDraw7_EnumDisplayModes(p, a, b, c, d) (p)->lpVtbl->EnumDisplayModes(p, a, b, c, d)
#define IDirectDraw7_EnumSurfaces(p, a, b, c, d)     (p)->lpVtbl->EnumSurfaces(p, a, b, c, d)
#define IDirectDraw7_FlipToGDISurface(p)             (p)->lpVtbl->FlipToGDISurface(p)
#define IDirectDraw7_GetCaps(p, a, b)                (p)->lpVtbl->GetCaps(p, a, b)
#define IDirectDraw7_GetDisplayMode(p, a)            (p)->lpVtbl->GetDisplayMode(p, a)
#define IDirectDraw7_GetFourCCCodes(p, a, b)         (p)->lpVtbl->GetFourCCCodes(p, a, b)
#define IDirectDraw7_GetGDISurface(p, a)             (p)->lpVtbl->GetGDISurface(p, a)
#define IDirectDraw7_GetMonitorFrequency(p, a)       (p)->lpVtbl->GetMonitorFrequency(p, a)
#define IDirectDraw7_GetScanLine(p, a)               (p)->lpVtbl->GetScanLine(p, a)
#define IDirectDraw7_GetVerticalBlankStatus(p, a)    (p)->lpVtbl->GetVerticalBlankStatus(p, a)
#define IDirectDraw7_Initialize(p, a)                (p)->lpVtbl->Initialize(p, a)
#define IDirectDraw7_RestoreDisplayMode(p)           (p)->lpVtbl->RestoreDisplayMode(p)
#define IDirectDraw7_SetCooperativeLevel(p, a, b)    (p)->lpVtbl->SetCooperativeLevel(p, a, b)
#define IDirectDraw7_SetDisplayMode(p, a, b, c, d, e) (p)->lpVtbl->SetDisplayMode(p, a, b, c, d, e)
#define IDirectDraw7_WaitForVerticalBlank(p, a, b)   (p)->lpVtbl->WaitForVerticalBlank(p, a, b)
#define IDirectDraw7_GetAvailableVidMem(p, a, b, c)  (p)->lpVtbl->GetAvailableVidMem(p, a, b, c)
#define IDirectDraw7_GetSurfaceFromDC(p, a, b)       (p)->lpVtbl->GetSurfaceFromDC(p, a, b)
#define IDirectDraw7_RestoreAllSurfaces(p)           (p)->lpVtbl->RestoreAllSurfaces(p)
#define IDirectDraw7_TestCooperativeLevel(p)         (p)->lpVtbl->TestCooperativeLevel(p)
#define IDirectDraw7_GetDeviceIdentifier(p,a,b)      (p)->lpVtbl->GetDeviceIdentifier(p,a,b)
#define IDirectDraw7_StartModeTest(p,a,b,c)        (p)->lpVtbl->StartModeTest(p,a,b,c)
#define IDirectDraw7_EvaluateMode(p,a,b)           (p)->lpVtbl->EvaluateMode(p,a,b)
#else
#define IDirectDraw7_QueryInterface(p, a, b)         (p)->QueryInterface(a, b)
#define IDirectDraw7_AddRef(p)                       (p)->AddRef()
#define IDirectDraw7_Release(p)                      (p)->Release()
#define IDirectDraw7_Compact(p)                      (p)->Compact()
#define IDirectDraw7_CreateClipper(p, a, b, c)       (p)->CreateClipper(a, b, c)
#define IDirectDraw7_CreatePalette(p, a, b, c, d)    (p)->CreatePalette(a, b, c, d)
#define IDirectDraw7_CreateSurface(p, a, b, c)       (p)->CreateSurface(a, b, c)
#define IDirectDraw7_DuplicateSurface(p, a, b)       (p)->DuplicateSurface(a, b)
#define IDirectDraw7_EnumDisplayModes(p, a, b, c, d) (p)->EnumDisplayModes(a, b, c, d)
#define IDirectDraw7_EnumSurfaces(p, a, b, c, d)     (p)->EnumSurfaces(a, b, c, d)
#define IDirectDraw7_FlipToGDISurface(p)             (p)->FlipToGDISurface()
#define IDirectDraw7_GetCaps(p, a, b)                (p)->GetCaps(a, b)
#define IDirectDraw7_GetDisplayMode(p, a)            (p)->GetDisplayMode(a)
#define IDirectDraw7_GetFourCCCodes(p, a, b)         (p)->GetFourCCCodes(a, b)
#define IDirectDraw7_GetGDISurface(p, a)             (p)->GetGDISurface(a)
#define IDirectDraw7_GetMonitorFrequency(p, a)       (p)->GetMonitorFrequency(a)
#define IDirectDraw7_GetScanLine(p, a)               (p)->GetScanLine(a)
#define IDirectDraw7_GetVerticalBlankStatus(p, a)    (p)->GetVerticalBlankStatus(a)
#define IDirectDraw7_Initialize(p, a)                (p)->Initialize(a)
#define IDirectDraw7_RestoreDisplayMode(p)           (p)->RestoreDisplayMode()
#define IDirectDraw7_SetCooperativeLevel(p, a, b)    (p)->SetCooperativeLevel(a, b)
#define IDirectDraw7_SetDisplayMode(p, a, b, c, d, e) (p)->SetDisplayMode(a, b, c, d, e)
#define IDirectDraw7_WaitForVerticalBlank(p, a, b)   (p)->WaitForVerticalBlank(a, b)
#define IDirectDraw7_GetAvailableVidMem(p, a, b, c)  (p)->GetAvailableVidMem(a, b, c)
#define IDirectDraw7_GetSurfaceFromDC(p, a, b)       (p)->GetSurfaceFromDC(a, b)
#define IDirectDraw7_RestoreAllSurfaces(p)           (p)->RestoreAllSurfaces()
#define IDirectDraw7_TestCooperativeLevel(p)         (p)->TestCooperativeLevel()
#define IDirectDraw7_GetDeviceIdentifier(p,a,b)      (p)->GetDeviceIdentifier(a,b)
#define IDirectDraw7_StartModeTest(p,a,b,c)        (p)->lpVtbl->StartModeTest(a,b,c)
#define IDirectDraw7_EvaluateMode(p,a,b)           (p)->lpVtbl->EvaluateMode(a,b)
#endif

#endif


/*
 * IDirectDrawPalette
 */
#if defined( _WIN32 ) && !defined( _NO_COM )
#undef INTERFACE
#define INTERFACE IDirectDrawPalette
DECLARE_INTERFACE_( IDirectDrawPalette, IUnknown )
{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    /*** IDirectDrawPalette methods ***/
    STDMETHOD(GetCaps)(THIS_ LPDWORD) PURE;
    STDMETHOD(GetEntries)(THIS_ DWORD,DWORD,DWORD,LPPALETTEENTRY) PURE;
    STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, DWORD, LPPALETTEENTRY) PURE;
    STDMETHOD(SetEntries)(THIS_ DWORD,DWORD,DWORD,LPPALETTEENTRY) PURE;
};

#if !defined(__cplusplus) || defined(CINTERFACE)
#define IDirectDrawPalette_QueryInterface(p, a, b)      (p)->lpVtbl->QueryInterface(p, a, b)
#define IDirectDrawPalette_AddRef(p)                    (p)->lpVtbl->AddRef(p)
#define IDirectDrawPalette_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawPalette_GetCaps(p, a)                (p)->lpVtbl->GetCaps(p, a)
#define IDirectDrawPalette_GetEntries(p, a, b, c, d)    (p)->lpVtbl->GetEntries(p, a, b, c, d)
#define IDirectDrawPalette_Initialize(p, a, b, c)       (p)->lpVtbl->Initialize(p, a, b, c)
#define IDirectDrawPalette_SetEntries(p, a, b, c, d)    (p)->lpVtbl->SetEntries(p, a, b, c, d)
#else
#define IDirectDrawPalette_QueryInterface(p, a, b)      (p)->QueryInterface(a, b)
#define IDirectDrawPalette_AddRef(p)                    (p)->AddRef()
#define IDirectDrawPalette_Release(p)                   (p)->Release()
#define IDirectDrawPalette_GetCaps(p, a)                (p)->GetCaps(a)
#define IDirectDrawPalette_GetEntries(p, a, b, c, d)    (p)->GetEntries(a, b, c, d)
#define IDirectDrawPalette_Initialize(p, a, b, c)       (p)->Initialize(a, b, c)
#define IDirectDrawPalette_SetEntries(p, a, b, c, d)    (p)->SetEntries(a, b, c, d)
#endif

#endif


/*
 * IDirectDrawClipper
 */
#if defined( _WIN32 ) && !defined( _NO_COM )
#undef INTERFACE
#define INTERFACE IDirectDrawClipper
DECLARE_INTERFACE_( IDirectDrawClipper, IUnknown )
{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    /*** IDirectDrawClipper methods ***/
    STDMETHOD(GetClipList)(THIS_ LPRECT, LPRGNDATA, LPDWORD) PURE;
    STDMETHOD(GetHWnd)(THIS_ HWND FAR *) PURE;
    STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, DWORD) PURE;
    STDMETHOD(IsClipListChanged)(THIS_ BOOL FAR *) PURE;
    STDMETHOD(SetClipList)(THIS_ LPRGNDATA,DWORD) PURE;
    STDMETHOD(SetHWnd)(THIS_ DWORD, HWND ) PURE;
};

#if !defined(__cplusplus) || defined(CINTERFACE)
#define IDirectDrawClipper_QueryInterface(p, a, b)  (p)->lpVtbl->QueryInterface(p, a, b)
#define IDirectDrawClipper_AddRef(p)                (p)->lpVtbl->AddRef(p)
#define IDirectDrawClipper_Release(p)               (p)->lpVtbl->Release(p)
#define IDirectDrawClipper_GetClipList(p, a, b, c)  (p)->lpVtbl->GetClipList(p, a, b, c)
#define IDirectDrawClipper_GetHWnd(p, a)            (p)->lpVtbl->GetHWnd(p, a)
#define IDirectDrawClipper_Initialize(p, a, b)      (p)->lpVtbl->Initialize(p, a, b)
#define IDirectDrawClipper_IsClipListChanged(p, a)  (p)->lpVtbl->IsClipListChanged(p, a)
#define IDirectDrawClipper_SetClipList(p, a, b)     (p)->lpVtbl->SetClipList(p, a, b)
#define IDirectDrawClipper_SetHWnd(p, a, b)         (p)->lpVtbl->SetHWnd(p, a, b)
#else
#define IDirectDrawClipper_QueryInterface(p, a, b)  (p)->QueryInterface(a, b)
#define IDirectDrawClipper_AddRef(p)                (p)->AddRef()
#define IDirectDrawClipper_Release(p)               (p)->Release()
#define IDirectDrawClipper_GetClipList(p, a, b, c)  (p)->GetClipList(a, b, c)
#define IDirectDrawClipper_GetHWnd(p, a)            (p)->GetHWnd(a)
#define IDirectDrawClipper_Initialize(p, a, b)      (p)->Initialize(a, b)
#define IDirectDrawClipper_IsClipListChanged(p, a)  (p)->IsClipListChanged(a)
#define IDirectDrawClipper_SetClipList(p, a, b)     (p)->SetClipList(a, b)
#define IDirectDrawClipper_SetHWnd(p, a, b)         (p)->SetHWnd(a, b)
#endif

#endif

/*
 * IDirectDrawSurface and related interfaces
 */
#if defined( _WIN32 ) && !defined( _NO_COM )
#undef INTERFACE
#define INTERFACE IDirectDrawSurface
DECLARE_INTERFACE_( IDirectDrawSurface, IUnknown )
{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    /*** IDirectDrawSurface methods ***/
    STDMETHOD(AddAttachedSurface)(THIS_ LPDIRECTDRAWSURFACE) PURE;
    STDMETHOD(AddOverlayDirtyRect)(THIS_ LPRECT) PURE;
    STDMETHOD(Blt)(THIS_ LPRECT,LPDIRECTDRAWSURFACE, LPRECT,DWORD, LPDDBLTFX) PURE;
    STDMETHOD(BltBatch)(THIS_ LPDDBLTBATCH, DWORD, DWORD ) PURE;
    STDMETHOD(BltFast)(THIS_ DWORD,DWORD,LPDIRECTDRAWSURFACE, LPRECT,DWORD) PURE;
    STDMETHOD(DeleteAttachedSurface)(THIS_ DWORD,LPDIRECTDRAWSURFACE) PURE;
    STDMETHOD(EnumAttachedSurfaces)(THIS_ LPVOID,LPDDENUMSURFACESCALLBACK) PURE;
    STDMETHOD(EnumOverlayZOrders)(THIS_ DWORD,LPVOID,LPDDENUMSURFACESCALLBACK) PURE;
    STDMETHOD(Flip)(THIS_ LPDIRECTDRAWSURFACE, DWORD) PURE;
    STDMETHOD(GetAttachedSurface)(THIS_ LPDDSCAPS, LPDIRECTDRAWSURFACE FAR *) PURE;
    STDMETHOD(GetBltStatus)(THIS_ DWORD) PURE;
    STDMETHOD(GetCaps)(THIS_ LPDDSCAPS) PURE;
    STDMETHOD(GetClipper)(THIS_ LPDIRECTDRAWCLIPPER FAR*) PURE;
    STDMETHOD(GetColorKey)(THIS_ DWORD, LPDDCOLORKEY) PURE;
    STDMETHOD(GetDC)(THIS_ HDC FAR *) PURE;
    STDMETHOD(GetFlipStatus)(THIS_ DWORD) PURE;
    STDMETHOD(GetOverlayPosition)(THIS_ LPLONG, LPLONG ) PURE;
    STDMETHOD(GetPalette)(THIS_ LPDIRECTDRAWPALETTE FAR*) PURE;
    STDMETHOD(GetPixelFormat)(THIS_ LPDDPIXELFORMAT) PURE;
    STDMETHOD(GetSurfaceDesc)(THIS_ LPDDSURFACEDESC) PURE;
    STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, LPDDSURFACEDESC) PURE;
    STDMETHOD(IsLost)(THIS) PURE;
    STDMETHOD(Lock)(THIS_ LPRECT,LPDDSURFACEDESC,DWORD,HANDLE) PURE;
    STDMETHOD(ReleaseDC)(THIS_ HDC) PURE;
    STDMETHOD(Restore)(THIS) PURE;
    STDMETHOD(SetClipper)(THIS_ LPDIRECTDRAWCLIPPER) PURE;
    STDMETHOD(SetColorKey)(THIS_ DWORD, LPDDCOLORKEY) PURE;
    STDMETHOD(SetOverlayPosition)(THIS_ LONG, LONG ) PURE;
    STDMETHOD(SetPalette)(THIS_ LPDIRECTDRAWPALETTE) PURE;
    STDMETHOD(Unlock)(THIS_ LPVOID) PURE;
    STDMETHOD(UpdateOverlay)(THIS_ LPRECT, LPDIRECTDRAWSURFACE,LPRECT,DWORD, LPDDOVERLAYFX) PURE;
    STDMETHOD(UpdateOverlayDisplay)(THIS_ DWORD) PURE;
    STDMETHOD(UpdateOverlayZOrder)(THIS_ DWORD, LPDIRECTDRAWSURFACE) PURE;
};

#if !defined(__cplusplus) || defined(CINTERFACE)
#define IDirectDrawSurface_QueryInterface(p,a,b)        (p)->lpVtbl->QueryInterface(p,a,b)
#define IDirectDrawSurface_AddRef(p)                    (p)->lpVtbl->AddRef(p)
#define IDirectDrawSurface_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawSurface_AddAttachedSurface(p,a)      (p)->lpVtbl->AddAttachedSurface(p,a)
#define IDirectDrawSurface_AddOverlayDirtyRect(p,a)     (p)->lpVtbl->AddOverlayDirtyRect(p,a)
#define IDirectDrawSurface_Blt(p,a,b,c,d,e)             (p)->lpVtbl->Blt(p,a,b,c,d,e)
#define IDirectDrawSurface_BltBatch(p,a,b,c)            (p)->lpVtbl->BltBatch(p,a,b,c)
#define IDirectDrawSurface_BltFast(p,a,b,c,d,e)         (p)->lpVtbl->BltFast(p,a,b,c,d,e)
#define IDirectDrawSurface_DeleteAttachedSurface(p,a,b) (p)->lpVtbl->DeleteAttachedSurface(p,a,b)
#define IDirectDrawSurface_EnumAttachedSurfaces(p,a,b)  (p)->lpVtbl->EnumAttachedSurfaces(p,a,b)
#define IDirectDrawSurface_EnumOverlayZOrders(p,a,b,c)  (p)->lpVtbl->EnumOverlayZOrders(p,a,b,c)
#define IDirectDrawSurface_Flip(p,a,b)                  (p)->lpVtbl->Flip(p,a,b)
#define IDirectDrawSurface_GetAttachedSurface(p,a,b)    (p)->lpVtbl->GetAttachedSurface(p,a,b)
#define IDirectDrawSurface_GetBltStatus(p,a)            (p)->lpVtbl->GetBltStatus(p,a)
#define IDirectDrawSurface_GetCaps(p,b)                 (p)->lpVtbl->GetCaps(p,b)
#define IDirectDrawSurface_GetClipper(p,a)              (p)->lpVtbl->GetClipper(p,a)
#define IDirectDrawSurface_GetColorKey(p,a,b)           (p)->lpVtbl->GetColorKey(p,a,b)
#define IDirectDrawSurface_GetDC(p,a)                   (p)->lpVtbl->GetDC(p,a)
#define IDirectDrawSurface_GetFlipStatus(p,a)           (p)->lpVtbl->GetFlipStatus(p,a)
#define IDirectDrawSurface_GetOverlayPosition(p,a,b)    (p)->lpVtbl->GetOverlayPosition(p,a,b)
#define IDirectDrawSurface_GetPalette(p,a)              (p)->lpVtbl->GetPalette(p,a)
#define IDirectDrawSurface_GetPixelFormat(p,a)          (p)->lpVtbl->GetPixelFormat(p,a)
#define IDirectDrawSurface_GetSurfaceDesc(p,a)          (p)->lpVtbl->GetSurfaceDesc(p,a)
#define IDirectDrawSurface_Initialize(p,a,b)            (p)->lpVtbl->Initialize(p,a,b)
#define IDirectDrawSurface_IsLost(p)                    (p)->lpVtbl->IsLost(p)
#define IDirectDrawSurface_Lock(p,a,b,c,d)              (p)->lpVtbl->Lock(p,a,b,c,d)
#define IDirectDrawSurface_ReleaseDC(p,a)               (p)->lpVtbl->ReleaseDC(p,a)
#define IDirectDrawSurface_Restore(p)                   (p)->lpVtbl->Restore(p)
#define IDirectDrawSurface_SetClipper(p,a)              (p)->lpVtbl->SetClipper(p,a)
#define IDirectDrawSurface_SetColorKey(p,a,b)           (p)->lpVtbl->SetColorKey(p,a,b)
#define IDirectDrawSurface_SetOverlayPosition(p,a,b)    (p)->lpVtbl->SetOverlayPosition(p,a,b)
#define IDirectDrawSurface_SetPalette(p,a)              (p)->lpVtbl->SetPalette(p,a)
#define IDirectDrawSurface_Unlock(p,b)                  (p)->lpVtbl->Unlock(p,b)
#define IDirectDrawSurface_UpdateOverlay(p,a,b,c,d,e)   (p)->lpVtbl->UpdateOverlay(p,a,b,c,d,e)
#define IDirectDrawSurface_UpdateOverlayDisplay(p,a)    (p)->lpVtbl->UpdateOverlayDisplay(p,a)
#define IDirectDrawSurface_UpdateOverlayZOrder(p,a,b)   (p)->lpVtbl->UpdateOverlayZOrder(p,a,b)
#else
#define IDirectDrawSurface_QueryInterface(p,a,b)        (p)->QueryInterface(a,b)
#define IDirectDrawSurface_AddRef(p)                    (p)->AddRef()
#define IDirectDrawSurface_Release(p)                   (p)->Release()
#define IDirectDrawSurface_AddAttachedSurface(p,a)      (p)->AddAttachedSurface(a)
#define IDirectDrawSurface_AddOverlayDirtyRect(p,a)     (p)->AddOverlayDirtyRect(a)
#define IDirectDrawSurface_Blt(p,a,b,c,d,e)             (p)->Blt(a,b,c,d,e)
#define IDirectDrawSurface_BltBatch(p,a,b,c)            (p)->BltBatch(a,b,c)
#define IDirectDrawSurface_BltFast(p,a,b,c,d,e)         (p)->BltFast(a,b,c,d,e)
#define IDirectDrawSurface_DeleteAttachedSurface(p,a,b) (p)->DeleteAttachedSurface(a,b)
#define IDirectDrawSurface_EnumAttachedSurfaces(p,a,b)  (p)->EnumAttachedSurfaces(a,b)
#define IDirectDrawSurface_EnumOverlayZOrders(p,a,b,c)  (p)->EnumOverlayZOrders(a,b,c)
#define IDirectDrawSurface_Flip(p,a,b)                  (p)->Flip(a,b)
#define IDirectDrawSurface_GetAttachedSurface(p,a,b)    (p)->GetAttachedSurface(a,b)
#define IDirectDrawSurface_GetBltStatus(p,a)            (p)->GetBltStatus(a)
#define IDirectDrawSurface_GetCaps(p,b)                 (p)->GetCaps(b)
#define IDirectDrawSurface_GetClipper(p,a)              (p)->GetClipper(a)
#define IDirectDrawSurface_GetColorKey(p,a,b)           (p)->GetColorKey(a,b)
#define IDirectDrawSurface_GetDC(p,a)                   (p)->GetDC(a)
#define IDirectDrawSurface_GetFlipStatus(p,a)           (p)->GetFlipStatus(a)
#define IDirectDrawSurface_GetOverlayPosition(p,a,b)    (p)->GetOverlayPosition(a,b)
#define IDirectDrawSurface_GetPalette(p,a)              (p)->GetPalette(a)
#define IDirectDrawSurface_GetPixelFormat(p,a)          (p)->GetPixelFormat(a)
#define IDirectDrawSurface_GetSurfaceDesc(p,a)          (p)->GetSurfaceDesc(a)
#define IDirectDrawSurface_Initialize(p,a,b)            (p)->Initialize(a,b)
#define IDirectDrawSurface_IsLost(p)                    (p)->IsLost()
#define IDirectDrawSurface_Lock(p,a,b,c,d)              (p)->Lock(a,b,c,d)
#define IDirectDrawSurface_ReleaseDC(p,a)               (p)->ReleaseDC(a)
#define IDirectDrawSurface_Restore(p)                   (p)->Restore()
#define IDirectDrawSurface_SetClipper(p,a)              (p)->SetClipper(a)
#define IDirectDrawSurface_SetColorKey(p,a,b)           (p)->SetColorKey(a,b)
#define IDirectDrawSurface_SetOverlayPosition(p,a,b)    (p)->SetOverlayPosition(a,b)
#define IDirectDrawSurface_SetPalette(p,a)              (p)->SetPalette(a)
#define IDirectDrawSurface_Unlock(p,b)                  (p)->Unlock(b)
#define IDirectDrawSurface_UpdateOverlay(p,a,b,c,d,e)   (p)->UpdateOverlay(a,b,c,d,e)
#define IDirectDrawSurface_UpdateOverlayDisplay(p,a)    (p)->UpdateOverlayDisplay(a)
#define IDirectDrawSurface_UpdateOverlayZOrder(p,a,b)   (p)->UpdateOverlayZOrder(a,b)
#endif

/*
 * IDirectDrawSurface2 and related interfaces
 */
#undef INTERFACE
#define INTERFACE IDirectDrawSurface2
DECLARE_INTERFACE_( IDirectDrawSurface2, IUnknown )
{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    /*** IDirectDrawSurface methods ***/
    STDMETHOD(AddAttachedSurface)(THIS_ LPDIRECTDRAWSURFACE2) PURE;
    STDMETHOD(AddOverlayDirtyRect)(THIS_ LPRECT) PURE;
    STDMETHOD(Blt)(THIS_ LPRECT,LPDIRECTDRAWSURFACE2, LPRECT,DWORD, LPDDBLTFX) PURE;
    STDMETHOD(BltBatch)(THIS_ LPDDBLTBATCH, DWORD, DWORD ) PURE;
    STDMETHOD(BltFast)(THIS_ DWORD,DWORD,LPDIRECTDRAWSURFACE2, LPRECT,DWORD) PURE;
    STDMETHOD(DeleteAttachedSurface)(THIS_ DWORD,LPDIRECTDRAWSURFACE2) PURE;
    STDMETHOD(EnumAttachedSurfaces)(THIS_ LPVOID,LPDDENUMSURFACESCALLBACK) PURE;
    STDMETHOD(EnumOverlayZOrders)(THIS_ DWORD,LPVOID,LPDDENUMSURFACESCALLBACK) PURE;
    STDMETHOD(Flip)(THIS_ LPDIRECTDRAWSURFACE2, DWORD) PURE;
    STDMETHOD(GetAttachedSurface)(THIS_ LPDDSCAPS, LPDIRECTDRAWSURFACE2 FAR *) PURE;
    STDMETHOD(GetBltStatus)(THIS_ DWORD) PURE;
    STDMETHOD(GetCaps)(THIS_ LPDDSCAPS) PURE;
    STDMETHOD(GetClipper)(THIS_ LPDIRECTDRAWCLIPPER FAR*) PURE;
    STDMETHOD(GetColorKey)(THIS_ DWORD, LPDDCOLORKEY) PURE;
    STDMETHOD(GetDC)(THIS_ HDC FAR *) PURE;
    STDMETHOD(GetFlipStatus)(THIS_ DWORD) PURE;
    STDMETHOD(GetOverlayPosition)(THIS_ LPLONG, LPLONG ) PURE;
    STDMETHOD(GetPalette)(THIS_ LPDIRECTDRAWPALETTE FAR*) PURE;
    STDMETHOD(GetPixelFormat)(THIS_ LPDDPIXELFORMAT) PURE;
    STDMETHOD(GetSurfaceDesc)(THIS_ LPDDSURFACEDESC) PURE;
    STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, LPDDSURFACEDESC) PURE;
    STDMETHOD(IsLost)(THIS) PURE;
    STDMETHOD(Lock)(THIS_ LPRECT,LPDDSURFACEDESC,DWORD,HANDLE) PURE;
    STDMETHOD(ReleaseDC)(THIS_ HDC) PURE;
    STDMETHOD(Restore)(THIS) PURE;
    STDMETHOD(SetClipper)(THIS_ LPDIRECTDRAWCLIPPER) PURE;
    STDMETHOD(SetColorKey)(THIS_ DWORD, LPDDCOLORKEY) PURE;
    STDMETHOD(SetOverlayPosition)(THIS_ LONG, LONG ) PURE;
    STDMETHOD(SetPalette)(THIS_ LPDIRECTDRAWPALETTE) PURE;
    STDMETHOD(Unlock)(THIS_ LPVOID) PURE;
    STDMETHOD(UpdateOverlay)(THIS_ LPRECT, LPDIRECTDRAWSURFACE2,LPRECT,DWORD, LPDDOVERLAYFX) PURE;
    STDMETHOD(UpdateOverlayDisplay)(THIS_ DWORD) PURE;
    STDMETHOD(UpdateOverlayZOrder)(THIS_ DWORD, LPDIRECTDRAWSURFACE2) PURE;
    /*** Added in the v2 interface ***/
    STDMETHOD(GetDDInterface)(THIS_ LPVOID FAR *) PURE;
    STDMETHOD(PageLock)(THIS_ DWORD) PURE;
    STDMETHOD(PageUnlock)(THIS_ DWORD) PURE;
};

#if !defined(__cplusplus) || defined(CINTERFACE)
#define IDirectDrawSurface2_QueryInterface(p,a,b)        (p)->lpVtbl->QueryInterface(p,a,b)
#define IDirectDrawSurface2_AddRef(p)                    (p)->lpVtbl->AddRef(p)
#define IDirectDrawSurface2_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawSurface2_AddAttachedSurface(p,a)      (p)->lpVtbl->AddAttachedSurface(p,a)
#define IDirectDrawSurface2_AddOverlayDirtyRect(p,a)     (p)->lpVtbl->AddOverlayDirtyRect(p,a)
#define IDirectDrawSurface2_Blt(p,a,b,c,d,e)             (p)->lpVtbl->Blt(p,a,b,c,d,e)
#define IDirectDrawSurface2_BltBatch(p,a,b,c)            (p)->lpVtbl->BltBatch(p,a,b,c)
#define IDirectDrawSurface2_BltFast(p,a,b,c,d,e)         (p)->lpVtbl->BltFast(p,a,b,c,d,e)
#define IDirectDrawSurface2_DeleteAttachedSurface(p,a,b) (p)->lpVtbl->DeleteAttachedSurface(p,a,b)
#define IDirectDrawSurface2_EnumAttachedSurfaces(p,a,b)  (p)->lpVtbl->EnumAttachedSurfaces(p,a,b)
#define IDirectDrawSurface2_EnumOverlayZOrders(p,a,b,c)  (p)->lpVtbl->EnumOverlayZOrders(p,a,b,c)
#define IDirectDrawSurface2_Flip(p,a,b)                  (p)->lpVtbl->Flip(p,a,b)
#define IDirectDrawSurface2_GetAttachedSurface(p,a,b)    (p)->lpVtbl->GetAttachedSurface(p,a,b)
#define IDirectDrawSurface2_GetBltStatus(p,a)            (p)->lpVtbl->GetBltStatus(p,a)
#define IDirectDrawSurface2_GetCaps(p,b)                 (p)->lpVtbl->GetCaps(p,b)
#define IDirectDrawSurface2_GetClipper(p,a)              (p)->lpVtbl->GetClipper(p,a)
#define IDirectDrawSurface2_GetColorKey(p,a,b)           (p)->lpVtbl->GetColorKey(p,a,b)
#define IDirectDrawSurface2_GetDC(p,a)                   (p)->lpVtbl->GetDC(p,a)
#define IDirectDrawSurface2_GetFlipStatus(p,a)           (p)->lpVtbl->GetFlipStatus(p,a)
#define IDirectDrawSurface2_GetOverlayPosition(p,a,b)    (p)->lpVtbl->GetOverlayPosition(p,a,b)
#define IDirectDrawSurface2_GetPalette(p,a)              (p)->lpVtbl->GetPalette(p,a)
#define IDirectDrawSurface2_GetPixelFormat(p,a)          (p)->lpVtbl->GetPixelFormat(p,a)
#define IDirectDrawSurface2_GetSurfaceDesc(p,a)          (p)->lpVtbl->GetSurfaceDesc(p,a)
#define IDirectDrawSurface2_Initialize(p,a,b)            (p)->lpVtbl->Initialize(p,a,b)
#define IDirectDrawSurface2_IsLost(p)                    (p)->lpVtbl->IsLost(p)
#define IDirectDrawSurface2_Lock(p,a,b,c,d)              (p)->lpVtbl->Lock(p,a,b,c,d)
#define IDirectDrawSurface2_ReleaseDC(p,a)               (p)->lpVtbl->ReleaseDC(p,a)
#define IDirectDrawSurface2_Restore(p)                   (p)->lpVtbl->Restore(p)
#define IDirectDrawSurface2_SetClipper(p,a)              (p)->lpVtbl->SetClipper(p,a)
#define IDirectDrawSurface2_SetColorKey(p,a,b)           (p)->lpVtbl->SetColorKey(p,a,b)
#define IDirectDrawSurface2_SetOverlayPosition(p,a,b)    (p)->lpVtbl->SetOverlayPosition(p,a,b)
#define IDirectDrawSurface2_SetPalette(p,a)              (p)->lpVtbl->SetPalette(p,a)
#define IDirectDrawSurface2_Unlock(p,b)                  (p)->lpVtbl->Unlock(p,b)
#define IDirectDrawSurface2_UpdateOverlay(p,a,b,c,d,e)   (p)->lpVtbl->UpdateOverlay(p,a,b,c,d,e)
#define IDirectDrawSurface2_UpdateOverlayDisplay(p,a)    (p)->lpVtbl->UpdateOverlayDisplay(p,a)
#define IDirectDrawSurface2_UpdateOverlayZOrder(p,a,b)   (p)->lpVtbl->UpdateOverlayZOrder(p,a,b)
#define IDirectDrawSurface2_GetDDInterface(p,a)          (p)->lpVtbl->GetDDInterface(p,a)
#define IDirectDrawSurface2_PageLock(p,a)                (p)->lpVtbl->PageLock(p,a)
#define IDirectDrawSurface2_PageUnlock(p,a)              (p)->lpVtbl->PageUnlock(p,a)
#else
#define IDirectDrawSurface2_QueryInterface(p,a,b)        (p)->QueryInterface(a,b)
#define IDirectDrawSurface2_AddRef(p)                    (p)->AddRef()
#define IDirectDrawSurface2_Release(p)                   (p)->Release()
#define IDirectDrawSurface2_AddAttachedSurface(p,a)      (p)->AddAttachedSurface(a)
#define IDirectDrawSurface2_AddOverlayDirtyRect(p,a)     (p)->AddOverlayDirtyRect(a)
#define IDirectDrawSurface2_Blt(p,a,b,c,d,e)             (p)->Blt(a,b,c,d,e)
#define IDirectDrawSurface2_BltBatch(p,a,b,c)            (p)->BltBatch(a,b,c)
#define IDirectDrawSurface2_BltFast(p,a,b,c,d,e)         (p)->BltFast(a,b,c,d,e)
#define IDirectDrawSurface2_DeleteAttachedSurface(p,a,b) (p)->DeleteAttachedSurface(a,b)
#define IDirectDrawSurface2_EnumAttachedSurfaces(p,a,b)  (p)->EnumAttachedSurfaces(a,b)
#define IDirectDrawSurface2_EnumOverlayZOrders(p,a,b,c)  (p)->EnumOverlayZOrders(a,b,c)
#define IDirectDrawSurface2_Flip(p,a,b)                  (p)->Flip(a,b)
#define IDirectDrawSurface2_GetAttachedSurface(p,a,b)    (p)->GetAttachedSurface(a,b)
#define IDirectDrawSurface2_GetBltStatus(p,a)            (p)->GetBltStatus(a)
#define IDirectDrawSurface2_GetCaps(p,b)                 (p)->GetCaps(b)
#define IDirectDrawSurface2_GetClipper(p,a)              (p)->GetClipper(a)
#define IDirectDrawSurface2_GetColorKey(p,a,b)           (p)->GetColorKey(a,b)
#define IDirectDrawSurface2_GetDC(p,a)                   (p)->GetDC(a)
#define IDirectDrawSurface2_GetFlipStatus(p,a)           (p)->GetFlipStatus(a)
#define IDirectDrawSurface2_GetOverlayPosition(p,a,b)    (p)->GetOverlayPosition(a,b)
#define IDirectDrawSurface2_GetPalette(p,a)              (p)->GetPalette(a)
#define IDirectDrawSurface2_GetPixelFormat(p,a)          (p)->GetPixelFormat(a)
#define IDirectDrawSurface2_GetSurfaceDesc(p,a)          (p)->GetSurfaceDesc(a)
#define IDirectDrawSurface2_Initialize(p,a,b)            (p)->Initialize(a,b)
#define IDirectDrawSurface2_IsLost(p)                    (p)->IsLost()
#define IDirectDrawSurface2_Lock(p,a,b,c,d)              (p)->Lock(a,b,c,d)
#define IDirectDrawSurface2_ReleaseDC(p,a)               (p)->ReleaseDC(a)
#define IDirectDrawSurface2_Restore(p)                   (p)->Restore()
#define IDirectDrawSurface2_SetClipper(p,a)              (p)->SetClipper(a)
#define IDirectDrawSurface2_SetColorKey(p,a,b)           (p)->SetColorKey(a,b)
#define IDirectDrawSurface2_SetOverlayPosition(p,a,b)    (p)->SetOverlayPosition(a,b)
#define IDirectDrawSurface2_SetPalette(p,a)              (p)->SetPalette(a)
#define IDirectDrawSurface2_Unlock(p,b)                  (p)->Unlock(b)
#define IDirectDrawSurface2_UpdateOverlay(p,a,b,c,d,e)   (p)->UpdateOverlay(a,b,c,d,e)
#define IDirectDrawSurface2_UpdateOverlayDisplay(p,a)    (p)->UpdateOverlayDisplay(a)
#define IDirectDrawSurface2_UpdateOverlayZOrder(p,a,b)   (p)->UpdateOverlayZOrder(a,b)
#define IDirectDrawSurface2_GetDDInterface(p,a)          (p)->GetDDInterface(a)
#define IDirectDrawSurface2_PageLock(p,a)                (p)->PageLock(a)
#define IDirectDrawSurface2_PageUnlock(p,a)              (p)->PageUnlock(a)
#endif

/*
 * IDirectDrawSurface3 and related interfaces
 */
#undef INTERFACE
#define INTERFACE IDirectDrawSurface3
DECLARE_INTERFACE_( IDirectDrawSurface3, IUnknown )
{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    /*** IDirectDrawSurface methods ***/
    STDMETHOD(AddAttachedSurface)(THIS_ LPDIRECTDRAWSURFACE3) PURE;
    STDMETHOD(AddOverlayDirtyRect)(THIS_ LPRECT) PURE;
    STDMETHOD(Blt)(THIS_ LPRECT,LPDIRECTDRAWSURFACE3, LPRECT,DWORD, LPDDBLTFX) PURE;
    STDMETHOD(BltBatch)(THIS_ LPDDBLTBATCH, DWORD, DWORD ) PURE;
    STDMETHOD(BltFast)(THIS_ DWORD,DWORD,LPDIRECTDRAWSURFACE3, LPRECT,DWORD) PURE;
    STDMETHOD(DeleteAttachedSurface)(THIS_ DWORD,LPDIRECTDRAWSURFACE3) PURE;
    STDMETHOD(EnumAttachedSurfaces)(THIS_ LPVOID,LPDDENUMSURFACESCALLBACK) PURE;
    STDMETHOD(EnumOverlayZOrders)(THIS_ DWORD,LPVOID,LPDDENUMSURFACESCALLBACK) PURE;
    STDMETHOD(Flip)(THIS_ LPDIRECTDRAWSURFACE3, DWORD) PURE;
    STDMETHOD(GetAttachedSurface)(THIS_ LPDDSCAPS, LPDIRECTDRAWSURFACE3 FAR *) PURE;
    STDMETHOD(GetBltStatus)(THIS_ DWORD) PURE;
    STDMETHOD(GetCaps)(THIS_ LPDDSCAPS) PURE;
    STDMETHOD(GetClipper)(THIS_ LPDIRECTDRAWCLIPPER FAR*) PURE;
    STDMETHOD(GetColorKey)(THIS_ DWORD, LPDDCOLORKEY) PURE;
    STDMETHOD(GetDC)(THIS_ HDC FAR *) PURE;
    STDMETHOD(GetFlipStatus)(THIS_ DWORD) PURE;
    STDMETHOD(GetOverlayPosition)(THIS_ LPLONG, LPLONG ) PURE;
    STDMETHOD(GetPalette)(THIS_ LPDIRECTDRAWPALETTE FAR*) PURE;
    STDMETHOD(GetPixelFormat)(THIS_ LPDDPIXELFORMAT) PURE;
    STDMETHOD(GetSurfaceDesc)(THIS_ LPDDSURFACEDESC) PURE;
    STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, LPDDSURFACEDESC) PURE;
    STDMETHOD(IsLost)(THIS) PURE;
    STDMETHOD(Lock)(THIS_ LPRECT,LPDDSURFACEDESC,DWORD,HANDLE) PURE;
    STDMETHOD(ReleaseDC)(THIS_ HDC) PURE;
    STDMETHOD(Restore)(THIS) PURE;
    STDMETHOD(SetClipper)(THIS_ LPDIRECTDRAWCLIPPER) PURE;
    STDMETHOD(SetColorKey)(THIS_ DWORD, LPDDCOLORKEY) PURE;
    STDMETHOD(SetOverlayPosition)(THIS_ LONG, LONG ) PURE;
    STDMETHOD(SetPalette)(THIS_ LPDIRECTDRAWPALETTE) PURE;
    STDMETHOD(Unlock)(THIS_ LPVOID) PURE;
    STDMETHOD(UpdateOverlay)(THIS_ LPRECT, LPDIRECTDRAWSURFACE3,LPRECT,DWORD, LPDDOVERLAYFX) PURE;
    STDMETHOD(UpdateOverlayDisplay)(THIS_ DWORD) PURE;
    STDMETHOD(UpdateOverlayZOrder)(THIS_ DWORD, LPDIRECTDRAWSURFACE3) PURE;
    /*** Added in the v2 interface ***/
    STDMETHOD(GetDDInterface)(THIS_ LPVOID FAR *) PURE;
    STDMETHOD(PageLock)(THIS_ DWORD) PURE;
    STDMETHOD(PageUnlock)(THIS_ DWORD) PURE;
    /*** Added in the V3 interface ***/
    STDMETHOD(SetSurfaceDesc)(THIS_ LPDDSURFACEDESC, DWORD) PURE;
};

#if !defined(__cplusplus) || defined(CINTERFACE)
#define IDirectDrawSurface3_QueryInterface(p,a,b)        (p)->lpVtbl->QueryInterface(p,a,b)
#define IDirectDrawSurface3_AddRef(p)                    (p)->lpVtbl->AddRef(p)
#define IDirectDrawSurface3_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawSurface3_AddAttachedSurface(p,a)      (p)->lpVtbl->AddAttachedSurface(p,a)
#define IDirectDrawSurface3_AddOverlayDirtyRect(p,a)     (p)->lpVtbl->AddOverlayDirtyRect(p,a)
#define IDirectDrawSurface3_Blt(p,a,b,c,d,e)             (p)->lpVtbl->Blt(p,a,b,c,d,e)
#define IDirectDrawSurface3_BltBatch(p,a,b,c)            (p)->lpVtbl->BltBatch(p,a,b,c)
#define IDirectDrawSurface3_BltFast(p,a,b,c,d,e)         (p)->lpVtbl->BltFast(p,a,b,c,d,e)
#define IDirectDrawSurface3_DeleteAttachedSurface(p,a,b) (p)->lpVtbl->DeleteAttachedSurface(p,a,b)
#define IDirectDrawSurface3_EnumAttachedSurfaces(p,a,b)  (p)->lpVtbl->EnumAttachedSurfaces(p,a,b)
#define IDirectDrawSurface3_EnumOverlayZOrders(p,a,b,c)  (p)->lpVtbl->EnumOverlayZOrders(p,a,b,c)
#define IDirectDrawSurface3_Flip(p,a,b)                  (p)->lpVtbl->Flip(p,a,b)
#define IDirectDrawSurface3_GetAttachedSurface(p,a,b)    (p)->lpVtbl->GetAttachedSurface(p,a,b)
#define IDirectDrawSurface3_GetBltStatus(p,a)            (p)->lpVtbl->GetBltStatus(p,a)
#define IDirectDrawSurface3_GetCaps(p,b)                 (p)->lpVtbl->GetCaps(p,b)
#define IDirectDrawSurface3_GetClipper(p,a)              (p)->lpVtbl->GetClipper(p,a)
#define IDirectDrawSurface3_GetColorKey(p,a,b)           (p)->lpVtbl->GetColorKey(p,a,b)
#define IDirectDrawSurface3_GetDC(p,a)                   (p)->lpVtbl->GetDC(p,a)
#define IDirectDrawSurface3_GetFlipStatus(p,a)           (p)->lpVtbl->GetFlipStatus(p,a)
#define IDirectDrawSurface3_GetOverlayPosition(p,a,b)    (p)->lpVtbl->GetOverlayPosition(p,a,b)
#define IDirectDrawSurface3_GetPalette(p,a)              (p)->lpVtbl->GetPalette(p,a)
#define IDirectDrawSurface3_GetPixelFormat(p,a)          (p)->lpVtbl->GetPixelFormat(p,a)
#define IDirectDrawSurface3_GetSurfaceDesc(p,a)          (p)->lpVtbl->GetSurfaceDesc(p,a)
#define IDirectDrawSurface3_Initialize(p,a,b)            (p)->lpVtbl->Initialize(p,a,b)
#define IDirectDrawSurface3_IsLost(p)                    (p)->lpVtbl->IsLost(p)
#define IDirectDrawSurface3_Lock(p,a,b,c,d)              (p)->lpVtbl->Lock(p,a,b,c,d)
#define IDirectDrawSurface3_ReleaseDC(p,a)               (p)->lpVtbl->ReleaseDC(p,a)
#define IDirectDrawSurface3_Restore(p)                   (p)->lpVtbl->Restore(p)
#define IDirectDrawSurface3_SetClipper(p,a)              (p)->lpVtbl->SetClipper(p,a)
#define IDirectDrawSurface3_SetColorKey(p,a,b)           (p)->lpVtbl->SetColorKey(p,a,b)
#define IDirectDrawSurface3_SetOverlayPosition(p,a,b)    (p)->lpVtbl->SetOverlayPosition(p,a,b)
#define IDirectDrawSurface3_SetPalette(p,a)              (p)->lpVtbl->SetPalette(p,a)
#define IDirectDrawSurface3_Unlock(p,b)                  (p)->lpVtbl->Unlock(p,b)
#define IDirectDrawSurface3_UpdateOverlay(p,a,b,c,d,e)   (p)->lpVtbl->UpdateOverlay(p,a,b,c,d,e)
#define IDirectDrawSurface3_UpdateOverlayDisplay(p,a)    (p)->lpVtbl->UpdateOverlayDisplay(p,a)
#define IDirectDrawSurface3_UpdateOverlayZOrder(p,a,b)   (p)->lpVtbl->UpdateOverlayZOrder(p,a,b)
#define IDirectDrawSurface3_GetDDInterface(p,a)          (p)->lpVtbl->GetDDInterface(p,a)
#define IDirectDrawSurface3_PageLock(p,a)                (p)->lpVtbl->PageLock(p,a)
#define IDirectDrawSurface3_PageUnlock(p,a)              (p)->lpVtbl->PageUnlock(p,a)
#define IDirectDrawSurface3_SetSurfaceDesc(p,a,b)        (p)->lpVtbl->SetSurfaceDesc(p,a,b)
#else
#define IDirectDrawSurface3_QueryInterface(p,a,b)        (p)->QueryInterface(a,b)
#define IDirectDrawSurface3_AddRef(p)                    (p)->AddRef()
#define IDirectDrawSurface3_Release(p)                   (p)->Release()
#define IDirectDrawSurface3_AddAttachedSurface(p,a)      (p)->AddAttachedSurface(a)
#define IDirectDrawSurface3_AddOverlayDirtyRect(p,a)     (p)->AddOverlayDirtyRect(a)
#define IDirectDrawSurface3_Blt(p,a,b,c,d,e)             (p)->Blt(a,b,c,d,e)
#define IDirectDrawSurface3_BltBatch(p,a,b,c)            (p)->BltBatch(a,b,c)
#define IDirectDrawSurface3_BltFast(p,a,b,c,d,e)         (p)->BltFast(a,b,c,d,e)
#define IDirectDrawSurface3_DeleteAttachedSurface(p,a,b) (p)->DeleteAttachedSurface(a,b)
#define IDirectDrawSurface3_EnumAttachedSurfaces(p,a,b)  (p)->EnumAttachedSurfaces(a,b)
#define IDirectDrawSurface3_EnumOverlayZOrders(p,a,b,c)  (p)->EnumOverlayZOrders(a,b,c)
#define IDirectDrawSurface3_Flip(p,a,b)                  (p)->Flip(a,b)
#define IDirectDrawSurface3_GetAttachedSurface(p,a,b)    (p)->GetAttachedSurface(a,b)
#define IDirectDrawSurface3_GetBltStatus(p,a)            (p)->GetBltStatus(a)
#define IDirectDrawSurface3_GetCaps(p,b)                 (p)->GetCaps(b)
#define IDirectDrawSurface3_GetClipper(p,a)              (p)->GetClipper(a)
#define IDirectDrawSurface3_GetColorKey(p,a,b)           (p)->GetColorKey(a,b)
#define IDirectDrawSurface3_GetDC(p,a)                   (p)->GetDC(a)
#define IDirectDrawSurface3_GetFlipStatus(p,a)           (p)->GetFlipStatus(a)
#define IDirectDrawSurface3_GetOverlayPosition(p,a,b)    (p)->GetOverlayPosition(a,b)
#define IDirectDrawSurface3_GetPalette(p,a)              (p)->GetPalette(a)
#define IDirectDrawSurface3_GetPixelFormat(p,a)          (p)->GetPixelFormat(a)
#define IDirectDrawSurface3_GetSurfaceDesc(p,a)          (p)->GetSurfaceDesc(a)
#define IDirectDrawSurface3_Initialize(p,a,b)            (p)->Initialize(a,b)
#define IDirectDrawSurface3_IsLost(p)                    (p)->IsLost()
#define IDirectDrawSurface3_Lock(p,a,b,c,d)              (p)->Lock(a,b,c,d)
#define IDirectDrawSurface3_ReleaseDC(p,a)               (p)->ReleaseDC(a)
#define IDirectDrawSurface3_Restore(p)                   (p)->Restore()
#define IDirectDrawSurface3_SetClipper(p,a)              (p)->SetClipper(a)
#define IDirectDrawSurface3_SetColorKey(p,a,b)           (p)->SetColorKey(a,b)
#define IDirectDrawSurface3_SetOverlayPosition(p,a,b)    (p)->SetOverlayPosition(a,b)
#define IDirectDrawSurface3_SetPalette(p,a)              (p)->SetPalette(a)
#define IDirectDrawSurface3_Unlock(p,b)                  (p)->Unlock(b)
#define IDirectDrawSurface3_UpdateOverlay(p,a,b,c,d,e)   (p)->UpdateOverlay(a,b,c,d,e)
#define IDirectDrawSurface3_UpdateOverlayDisplay(p,a)    (p)->UpdateOverlayDisplay(a)
#define IDirectDrawSurface3_UpdateOverlayZOrder(p,a,b)   (p)->UpdateOverlayZOrder(a,b)
#define IDirectDrawSurface3_GetDDInterface(p,a)          (p)->GetDDInterface(a)
#define IDirectDrawSurface3_PageLock(p,a)                (p)->PageLock(a)
#define IDirectDrawSurface3_PageUnlock(p,a)              (p)->PageUnlock(a)
#define IDirectDrawSurface3_SetSurfaceDesc(p,a,b)        (p)->SetSurfaceDesc(a,b)
#endif

/*
 * IDirectDrawSurface4 and related interfaces
 */
#undef INTERFACE
#define INTERFACE IDirectDrawSurface4
DECLARE_INTERFACE_( IDirectDrawSurface4, IUnknown )
{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    /*** IDirectDrawSurface methods ***/
    STDMETHOD(AddAttachedSurface)(THIS_ LPDIRECTDRAWSURFACE4) PURE;
    STDMETHOD(AddOverlayDirtyRect)(THIS_ LPRECT) PURE;
    STDMETHOD(Blt)(THIS_ LPRECT,LPDIRECTDRAWSURFACE4, LPRECT,DWORD, LPDDBLTFX) PURE;
    STDMETHOD(BltBatch)(THIS_ LPDDBLTBATCH, DWORD, DWORD ) PURE;
    STDMETHOD(BltFast)(THIS_ DWORD,DWORD,LPDIRECTDRAWSURFACE4, LPRECT,DWORD) PURE;
    STDMETHOD(DeleteAttachedSurface)(THIS_ DWORD,LPDIRECTDRAWSURFACE4) PURE;
    STDMETHOD(EnumAttachedSurfaces)(THIS_ LPVOID,LPDDENUMSURFACESCALLBACK2) PURE;
    STDMETHOD(EnumOverlayZOrders)(THIS_ DWORD,LPVOID,LPDDENUMSURFACESCALLBACK2) PURE;
    STDMETHOD(Flip)(THIS_ LPDIRECTDRAWSURFACE4, DWORD) PURE;
    STDMETHOD(GetAttachedSurface)(THIS_ LPDDSCAPS2, LPDIRECTDRAWSURFACE4 FAR *) PURE;
    STDMETHOD(GetBltStatus)(THIS_ DWORD) PURE;
    STDMETHOD(GetCaps)(THIS_ LPDDSCAPS2) PURE;
    STDMETHOD(GetClipper)(THIS_ LPDIRECTDRAWCLIPPER FAR*) PURE;
    STDMETHOD(GetColorKey)(THIS_ DWORD, LPDDCOLORKEY) PURE;
    STDMETHOD(GetDC)(THIS_ HDC FAR *) PURE;
    STDMETHOD(GetFlipStatus)(THIS_ DWORD) PURE;
    STDMETHOD(GetOverlayPosition)(THIS_ LPLONG, LPLONG ) PURE;
    STDMETHOD(GetPalette)(THIS_ LPDIRECTDRAWPALETTE FAR*) PURE;
    STDMETHOD(GetPixelFormat)(THIS_ LPDDPIXELFORMAT) PURE;
    STDMETHOD(GetSurfaceDesc)(THIS_ LPDDSURFACEDESC2) PURE;
    STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, LPDDSURFACEDESC2) PURE;
    STDMETHOD(IsLost)(THIS) PURE;
    STDMETHOD(Lock)(THIS_ LPRECT,LPDDSURFACEDESC2,DWORD,HANDLE) PURE;
    STDMETHOD(ReleaseDC)(THIS_ HDC) PURE;
    STDMETHOD(Restore)(THIS) PURE;
    STDMETHOD(SetClipper)(THIS_ LPDIRECTDRAWCLIPPER) PURE;
    STDMETHOD(SetColorKey)(THIS_ DWORD, LPDDCOLORKEY) PURE;
    STDMETHOD(SetOverlayPosition)(THIS_ LONG, LONG ) PURE;
    STDMETHOD(SetPalette)(THIS_ LPDIRECTDRAWPALETTE) PURE;
    STDMETHOD(Unlock)(THIS_ LPRECT) PURE;
    STDMETHOD(UpdateOverlay)(THIS_ LPRECT, LPDIRECTDRAWSURFACE4,LPRECT,DWORD, LPDDOVERLAYFX) PURE;
    STDMETHOD(UpdateOverlayDisplay)(THIS_ DWORD) PURE;
    STDMETHOD(UpdateOverlayZOrder)(THIS_ DWORD, LPDIRECTDRAWSURFACE