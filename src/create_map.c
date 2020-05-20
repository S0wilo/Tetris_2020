/*
** EPITECH PROJECT, 2020
** create_map
** File description:
** create_map
*/

#include "tetris.h"

char **create_map(command_t command)
{
    char **map = malloc(sizeof(char *) * command.m_size_y);

    if (map == NULL)
        return (NULL);
    for (int i = 0; i < command.m_size_y; i++) {
        map[i] = malloc(sizeof(char) * (command.m_size_x * 2 + 1));
        if (map[i] == NULL)
            return (NULL);
        for (int k = 0; k < command.m_size_x * 2; k++) {
            map[i][k] = ' ';
            map[i][k + 1] = '\0';
        }
    }
    return (map);
}
