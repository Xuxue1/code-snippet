#include <stdio.h>
/* print a hexdump of length bytes from the data given in buf */
void HexDump (const char *buf, int length)
{
    int i = 0;
    int j = 0;
    unsigned char c = 0;

    /* printf ("Hexdump: %i Bytes\n", length);*/
    for (j = 0; j <69 ; j++)
    {
        printf ("-");
    }
    printf ("\n");

    j = 0;
    while (j < length)
    {
        printf ("%04X ",j);
        for (i = j; i < (j + 16); i++)
        {
            if (i < length)
            {
                printf ("%02X ", (unsigned char)buf[i]);
            }
            else
            {
                printf("   ");
            }
        }
        for (i = j; i < (j + 16 < length ? j+16 : length); i++)
        {
            c = buf[i];
            if ((c >= 32) && (c < 127))
            {
                printf ("%c", c);
            }
            else
            {
                printf (".");
            }
        }
        j = i;
        printf("\n");
    }

    for (j = 0; j < 69; j++)
    {
        printf("-");
    }
    printf("\n");
}


void *malloc_aligned(size_t alignment, size_t size, void **base)
{
    char *ptr = NULL;

    *base = ptr = calloc(1, size + alignment);
    if (ptr == NULL)
    {
        return NULL;
    }
    while ((size_t) ptr % alignment)
    {
        ptr++;
    }

    return ptr;
}
