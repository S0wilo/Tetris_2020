/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/
#include <unistd.h>

int power(int n)
{
    int power = 1;

    for (int i = 0; i < n; i++) {
        power = power * 10;
    }
    return (power);
}

int my_put_nbr(int nb)
{
    int var1 = nb;
    int i = 0;
    char str;

    for (i = 0; var1 >= 10; i++) {
        var1 = var1/10;
    }
    for (i = i; i >= 0; i--) {
        str = (nb/power(i))%10 + 48;
        write( 1, &str, 1);
    }
}
