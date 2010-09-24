#ifndef _BASE64_H_
#define _BASE64_H_

#if _MSC_VER >= 1000
    #pragma once
#endif // _MSC_VER >= 1000



class CBase64
{

public:

    /// Default Constructor
    CBase64();

    /// Destructor
    virtual ~CBase64();

    /// Encode data as base-64 string with CRLF
    /**
        \param [in] dst     - Receives encoded string
        \param [in] dstsize - Size of dst
        \param [in] src     - Data to be encoded
        \param [in] srcsize - Size of src

        \return Returns number of bytes encoded

        \warning For multiple calls, size must be divisible by four
    */
    static DWORD Encode( LPSTR dst, DWORD dstsize, LPBYTE src, DWORD srcsize );

    /// Decode base-64 string
    /**
        \param [in] src             - Data to be decoded
        \param [in] srcsize         - Size of src
        \param [in] dst             - Receives decoded data
        \param [in] dstsize         - Size of dst
        \param [out] done           - Set to non-zero when decoding is done

        \return Returns number of bytes decoded
    */
    static BOOL Decode( LPCTSTR src, LPDWORD srcsize, LPBYTE dst, LPDWORD dstsize, LPDWORD done );


    /// Calculates size of encoded string
    /**
        \param [in] size    - Size of unencoded data

        \return Returns calculated size of encoded string

        \warning For multiple calls, must be divisible by four
    */
    static DWORD GetEncodedSize( DWORD size )
    {
        DWORD total = ( size * 8 ) / 6;
        switch (size % 3)
        {
        case 1 : total++;
        case 2 : total++;
        }
        total += ( total / CBASE64_LINELEN ) * 2;
        return total;
    }

    /// Calculates size of decoded string
    /**
        \param [in] size    - Size of encoded data

        \return Returns calculated size of unencoded string

        \warning For multiple calls, must be divisible by four
    */
    static DWORD GetDecodedSize( DWORD size )
    {
        if (( size & 0x03 ) != 0)
        {
            return( ( size * 6 ) / 8 ) + 1;
        }
        return (size * 6) / 8;
    }

    /// Base-64 encoding lookup table
    static BYTE m_b64encode[];

    /// Base-64 decode lookup table
    static BYTE m_b64decode[];

};

#endif //
