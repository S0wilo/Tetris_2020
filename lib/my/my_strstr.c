/*
** EPITECH PROJECT, 2019
** strstr
** File description:
** search str in a string
*/

int len_find(char const *to_find)
{
    int count = 0;

    for (int i = 0; to_find[i] != '\0'; i++) {
        count++;
    }
    return (count);
}

int test_find(char *str, char const *to_find, int len, int i)
{
    int same = 0;

    for (int j = 0; j < len; j++) {
        if (str[j+i] == to_find[j]) {
            same++;
        }
    }
    if (same == len) {
        return (i);
    } else {
        return (0);
    }
}

char *my_strstr(char *str, char const *to_find)
{
    int len = len_find(to_find);
    int result = 0;
    int switch_nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find[0] && result == 0) {
            result = test_find(str, to_find, len, i);
        }
    }
    str = str + result;
    return (str);
}
