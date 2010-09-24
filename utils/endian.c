#define be16(val) (unsigned int((val & 0xFF) << 8) + unsigned int((val & 0xFF00) >> 8))
#define be24(val) (unsigned int((val & 0xFF) << 16) + unsigned int(val & 0xFF00) + \
                   unsigned int((val & 0xFF0000) >> 16))
#define be32(val) (unsigned int((val & 0xFF) << 24) + unsigned int((val & 0xFF00) << 8) + \
                   unsigned int((val & 0xFF0000) >> 8) + unsigned int((val & 0xFF000000) >> 24))

inline void put_byte(unsigned char* buffer, unsigned char value)
{
    *buffer = value;
}

inline void put_be8(unsigned char* buffer, unsigned char value)
{
    *buffer = value;
}

inline void put_be16(unsigned char* buffer, unsigned short value)
{
    put_be8(buffer, unsigned char(value >> 8));
    put_be8(buffer + 1, unsigned char(value));
}

inline void put_be32(unsigned char* buffer, unsigned long value)
{
    put_be16(buffer, unsigned short(value >> 16));
    put_be16(buffer + 2, unsigned short(value));
}

inline unsigned short get_be16(unsigned char* buffer)
{
    unsigned short ret = buffer[0] << 8 | buffer[1];
    return ret;
}

inline unsigned short get_be16(unsigned short value)
{
    return get_be16((unsigned char*)&value);
}

inline unsigned long get_be32(unsigned char* buffer)
{
    unsigned long ret = buffer[0] << 24 |
                        buffer[1] << 16 |
                        buffer[2] << 8  |
                        buffer[3];
    return ret;
}

inline unsigned long get_be32(unsigned long value)
{
    return get_be32((unsigned char*)&value);
}

inline unsigned long get_le32(unsigned char* buffer)
{
    unsigned long ret = buffer[3] << 24 |
                        buffer[2] << 16 |
                        buffer[1] << 8  |
                        buffer[0];
    return ret;
}

inline long long get_be64(unsigned char* buffer)
{
    return((long long)get_be32(buffer)) << 32 | get_be32(buffer + 4);
}

inline long long get_le64(unsigned char* buffer)
{
    return((long long)get_le32(buffer + 4)) << 32 | get_le32(buffer);
}

inline unsigned long reverse(unsigned long value)
{
    return get_be32((unsigned char*)&value);
}

inline unsigned long bswap(int i)
{
    __asm mov eax, i;
    __asm bswap eax;
}