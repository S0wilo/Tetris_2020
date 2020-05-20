/*
** EPITECH PROJECT, 2019
** str_to_number
** File description:
** str_to_number
*/

#include "my.h"

int str_to_number(char *str)
{
    int nb = 0;
    int power = 1;
    int len = my_strlen(str);
    int limit = my_strlen(str);

    if (str[0] == '-')
        limit--;
    for (int i = 0; i < limit; i++) {
        nb = nb + (str[len - i - 1] - 48) * power;
        power = power * 10;
    }
    if (str[0] == '-')
        nb = nb * -1;
    return (nb);
}
