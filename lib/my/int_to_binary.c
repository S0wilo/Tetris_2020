/*
** EPITECH PROJECT, 2020
** int_to_binary
** File description:
** int_to_binary
*/

#include <stddef.h>
#include <stdlib.h>

int static copy_stock(char *binary, char *stock)
{
    if (stock == NULL)
        return (0);
    for (int i = 0; stock[i]; i++) {
        binary[i + 1] = stock[i];
        binary[i + 2] = '\0';
    }
}

char static *empty(void)
{
    char *binary = malloc(sizeof(char) * 2);

    if (binary == NULL)
        return (NULL);
    binary[0] = '0';
    binary[1] = '\0';
    return (binary);
}

char *int_to_binary(int nb)
{
    char *binary = NULL;
    char *stock = NULL;

    if (nb == 0)
        binary = empty();
    for (int i = 1; nb > 0; i++) {
        free(stock);
        stock = binary;
        binary = malloc(sizeof(char) * (i + 1));
        if (binary == NULL)
            return (NULL);
        binary[0] = nb % 2 + '0';
        binary[1] = '\0';
        copy_stock(binary, stock);
        nb = nb / 2;
    }
    return (binary);
}
