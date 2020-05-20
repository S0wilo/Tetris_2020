/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/

#include "my.h"

int my_putstr(char const *str)
{
    int count = 0;

    while ( str[count] != 0 ) {
        my_putchar(str[count]);
        count = count + 1;
    }
}
