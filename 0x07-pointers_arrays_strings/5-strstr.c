#include "main.h"

/**
 * _strstr - first occurrence of the substring needle in the string haystack
 * @haystack: main str to be examined
 * @needle: searched in haystack
 * Return: return 0
 **/
char  *_strstr(char *haystack, char *needle)
{
        char *s1, *s2;

        while (*haystack)
        {
                if(*haystack == *needle)
                {
                        s1 = haystack;
                        s2 = needle;
                        while (*s1 && *s2)
                        {
                                if(*s1 != *s2)
                                        break;
                                s1++;
                                s2++;
                        }
                        if(*s2 == '\0')
                                return (haystack);
                }
                haystack++;
        }
        return (0);
}
