/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/

int my_strlen(char const *str)
{
    int count = 0;

    while (str[count]) {
        count++;
    }
    return (count);
}
