#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

int _vasprintf(char **buffer, const char *format, va_list ap)
{
    char *buf = NULL;
    int size = 128;

    for (;;)
    {
        int ret;
        va_list cp;
        char *newbuf = realloc(buf, size *= 2);
        if (!newbuf)
        {
            free (buf);
            return -1;
        }
        buf = newbuf;

        va_copy(cp, ap);
        ret = vsnprintf(buf, size, format, cp);
        va_end (cp);

        if (ret >= 0 && ret < size)
        {
            *buffer = realloc (buf, ret + 1);
            return ret;
        }
    }
}

int _asprintf(char **buffer, const char *format, ...)
{
    int ret;
    va_list ap;
    va_start(ap, format);
    ret = _vasprintf(buffer, format, ap);
    va_end(ap);
    return ret;
}
