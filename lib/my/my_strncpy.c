/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** copies a string into another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int len = 1;

    for (int j = 0; dest[j] != '\0'; j++) {
        dest[j] = '\0';
    }
    while (src[len] != '\0') {
        len++;
    }
    for (i = 0; i < n; i = i +1) {
        dest[i] = src[i];
    }
    if (n = len) {
        dest[i-1] = '\0';
    }
    return (dest);
}
