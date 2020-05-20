/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** concatenates two strings
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    for (i = 0; dest[i] != '\0'; i++) {
    }
    for (j = 0; src[j] != '\0' && j < nb; j++) {
        dest[i+j] = src[j];
    }
    dest[i+j+1] = '\0';
    return (dest);
}
