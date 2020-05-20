/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** reverse a string into another
*/

char *my_revstr(char *str)
{
    int i = 0;
    int len = 1;
    char *stock = "a";

    while (str[len] != '\0') {
        len++;
    }
    for (i = 0; i < len / 2; i = i + 1) {
        stock[0] = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = stock[0];
    }
    str[len+1] = '\0';
    return (str);
}
