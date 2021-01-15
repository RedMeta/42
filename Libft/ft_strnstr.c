#include "libft.h"
#include <stdio.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t  nLen;
    size_t  cc;
    char    *res;

    cc = 0;
    res = (char *)haystack;
    if (!(*needle))
        return (res);
    nLen = ft_strlen(needle);
    while (*res != '\0' && ((len - nLen) >= 0))
    {
        while (*(res + cc) == needle[cc])
        {
            cc++;
            if ((cc == nLen) && cc <= len)
                return (res);
        }
        res++;
        cc = 0;
        len--;
    }
    return (NULL);
}