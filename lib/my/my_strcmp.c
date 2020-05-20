/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** compare two strings
*/

int my_strcmp(char const *str1, char const *str2)
{
    int i = 0;

    if (!str1 || !str2)
        return (1);
    while (str1[i] && str2[i] && str1[i] == str2[i])
        i++;
    if (str1[i] == '\0')
        return (0);
    else
        return (1);
}
