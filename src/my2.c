/*
** EPITECH PROJECT, 2024
** my2.c
** File description:
** lib
*/
#include "my.h"
#include <unistd.h>

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
    }
    dest[i] = '\0';
    return dest;
}

int my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
        }
        return (0);
}

char *my_strcat(char *dest, char const *src)
{
    char *ptr = dest;

    while (*ptr != '\0') {
        ptr++;
    }
    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = '\0';
    return dest;
}

int get_minimum(int a, int b, int c)
{
    int min = (a < b) ? a : b;

    return (min < c) ? min : c;
}
