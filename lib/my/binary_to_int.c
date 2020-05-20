/*
** EPITECH PROJECT, 2020
** binary_to_int
** File description:
** binary_to_int
*/

#include "my.h"

int binary_to_int(char *str)
{
    int nb = 0;
    int len = my_strlen(str);
    int k = 1;

    for (int i = 0; str[i]; i++, k = k * 2)
        nb = nb + (str[len - i - 1] - '0') * k;
    return (nb);
}
