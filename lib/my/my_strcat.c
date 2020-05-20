/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concatenates two strings
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"

char *my_strcat(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    char *new_str = malloc(sizeof(char) * (len1 + len2 + 1));
    int i = 0;

    if (new_str == NULL)
        return (NULL);
    if (len1 != 0)
        for (i; i < len1; i++)
            new_str[i] = str1[i];
    for (int k = 0; k < len2; k++) {
        new_str[i + k] = str2[k];
        new_str[i + k + 1] = '\0';
    }
    return (new_str);
}
