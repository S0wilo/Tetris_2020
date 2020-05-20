/*
** EPITECH PROJECT, 2020
** game_event_move_check
** File description:
** game_event_move_check
*/

#include "tetris.h"

int static left_line_collision(objects_t *obj, char *line, int i)
{
    int y = obj->actl->pos_y;
    int x = obj->actl->pos_x;

    for (int k = 0; line[k]; k++)
        if (line[k] == '*' && obj->map[y + i][(x + k - 1) * 2] == '*')
            return (1);
}

int check_go_left(objects_t *obj)
{
    if (obj->actl->pos_x <= 0)
        return (0);
    for (int i = 0; obj->actl->form[i]; i++)
        if (left_line_collision(obj, obj->actl->form[i], i) == 1)
            return (0);
    return (1);
}

int static right_line_collision(objects_t *obj, char *line, int i)
{
    int y = obj->actl->pos_y;
    int x = obj->actl->pos_x;

    for (int k = 0; line[k]; k++)
        if (line[k] == '*' && obj->map[y + i][(x + k + 1) * 2] == '*')
            return (1);
}

int check_go_right(objects_t *obj)
{
    int x = obj->actl->pos_x + my_strlen(obj->actl->form[0]);

    if (x >= obj->command->m_size_x - 1)
        return (0);
    for (int i = 0; obj->actl->form[i]; i++)
        if (right_line_collision(obj, obj->actl->form[i], i) == 1)
            return (0);
    return (1);
}
