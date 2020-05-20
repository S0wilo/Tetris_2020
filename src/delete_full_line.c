/*
** EPITECH PROJECT, 2020
** delete_full_line
** File description:
** delete_full_line
*/

#include "tetris.h"

int static line_is_full(char *line)
{
    for (int i = 0; line[i + 2]; i++)
        if (line[i] == ' ')
            return (0);
    return (1);
}

void static delete_line(char **map, int i)
{
    char *stock = NULL;

    for (int k = 0; map[i][k]; k++)
        map[i][k] = ' ';
    for (i; i > 0; i--) {
        stock = map[i];
        map[i] = map[i - 1];
        map[i - 1] = stock;
    }
}

void delete_full_line(objects_t *obj)
{
    for (int i = 0; obj->map[i]; i++)
        if (line_is_full(obj->map[i]) == 1) {
            delete_line(obj->map, i);
            obj->level += 1;
        }
}
