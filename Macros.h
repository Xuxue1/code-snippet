





#ifndef HAVE_MAX_MACRO
#define	MAX(a,b) (((a)>(b))?(a):(b))
#endif
#ifndef HAVE_MIN_MACRO
#define	MIN(a,b) (((a)<(b))?(a):(b))
#endif

#define ABSVAL( v ) ((v >= 0) ? v : -v)

#define SCALE(v, cur, des) ((v * des) / cur)

// Sets a bit in DWORD
#define BSETDW( b, dwrd )	( dwrd |= 0x00000001 << b )

// Clears a bit in DWORD
#define BCLRDW( b, dwrd ) ( dwrd &= ~( 0x00000001 << b ) )

// Toggles a bit in DWORD
#define BTOGDW( b, dwrd ) ( dwrd ^= ( 0x00000001 << b ) )

// Gets the value of a particular bit
#define BGETDW( b, dwrd ) ( ( ( 0x00000001 << b ) & dwrd ) != 0 )

#define UNPACK_BGR15(packed_pixel, r, g, b) \
  b = (packed_pixel & 0x7C00) >> 7; \
  g = (packed_pixel & 0x03E0) >> 2; \
  r = (packed_pixel & 0x001F) << 3;

#define UNPACK_BGR16(packed_pixel, r, g, b) \
  b = (packed_pixel & 0xF800) >> 8; \
  g = (packed_pixel & 0x07E0) >> 3; \
  r = (packed_pixel & 0x001F) << 3;

#define UNPACK_RGB15(packed_pixel, r, g, b) \
  r = (packed_pixel & 0x7C00) >> 7; \
  g = (packed_pixel & 0x03E0) >> 2; \
  b = (packed_pixel & 0x001F) << 3;

#define UNPACK_RGB16(packed_pixel, r, g, b) \
  r = (packed_pixel & 0xF800) >> 8; \
  g = (packed_pixel & 0x07E0) >> 3; \
  b = (packed_pixel & 0x001F) << 3;
