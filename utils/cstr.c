#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/*
 * Get next token from string *stringp, where tokens are possibly-empty
 * strings separated by characters from delim.
 * Writes NULs into the string at *stringp to end tokens.
 * delim need not remain constant from call to call.
 * On return, *stringp points past the last NUL written (if there might
 * be further tokens), or is NULL (if there are definitely no more tokens).
 * If *stringp is NULL, strsep returns NULL.
 */
char *_strsep(char **stringp, const char *delim)
{
    char *s;
    const char *spanp;
    int c, sc;
    char *tok;

    if ((s = *stringp) == NULL)
    {
        return(NULL);
    }
    for (tok = s;;)
    {
        c = *s++;
        spanp = delim;
        do
        {
            if ((sc = *spanp++) == c)
            {
                if (c == 0)
                    s = NULL;
                else
                    s[-1] = 0;
                *stringp = s;
                return(tok);
            }
        } while (sc != 0);
    }
    /* NOTREACHED */
}
/*
 * Find the first occurrence of find in s, ignore case.
 */
char *_strcasestr(const char *s, const char *find)
{
    char c, sc;
    size_t len;

    if ((c = *find++) != 0)
    {
        c = tolower((unsigned char)c);
        len = strlen(find);
        do
        {
            do
            {
                if ((sc = *s++) == 0)
                {
                    return(NULL);
                }
            } while ((char)tolower((unsigned char)sc) != c);
        } while (strncasecmp(s, find, len) != 0);
        s--;
    }
    return(char *)s;
}

char *_strpbrk(const char *s, const char *accept)
{

    while (*s != '\0')
    {
        const char *a = accept;
        while (*a != '\0')
        {
            if (*a++ == *s)
            {
                return(char *)s;
            }
        }
        ++s;
    }
    return NULL;
}

char *_strndup(const char *str, size_t n)
{
    size_t len = 0;
    char *copy = NULL;

    if (!str)
    {
        return(NULL);
    }

    for (len = 0; len < n && str[len]; len++)
    {
        continue;
    }

    if (!(copy = malloc(len + 1)))
    {
        return(NULL);
    }
    memcpy(copy, str, len);
    copy[len] = '\0';
    return(copy);
}


char *_strtok_r(char *s, const char *delim, char **ptrptr)
{
    char *next;
    size_t toklen, cutlen;

    /* first or next call */
    if (s)
    {
        *ptrptr = s;
    }
    else
    {
        s = *ptrptr;
    }

    /* end of searching */
    if (!s || !*s)
    {
        return NULL;
    }

    /* cut the initial garbage */
    cutlen = strspn(s, delim);
    s = s + cutlen;

    /* pointer before next token */
    if ((toklen = strcspn(s, delim)) == 0)
    {
        *ptrptr = NULL;
        return NULL;
    }
    next = s + toklen;

    /* prepare next call */
    *ptrptr = *next ? next + 1 : NULL;

    /* cut current token */
    *next = '\0';

    /* return the token */
    return s;
}
