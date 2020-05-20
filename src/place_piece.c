/*
** EPITECH PROJECT, 2020
** place_piece
** File description:
** place_piece
*/

#include "tetris.h"

void static place_line(objects_t *obj, char *line, int i)
{
    int x = obj->actl->pos_x;
    int y = obj->actl->pos_y;

    for (int k = 0; line[k]; k++)
        if (line[k] == '*') {
            obj->map[y + i][(x + k) * 2] = line[k];
            obj->map[y + i][(x + k) * 2 + 1] = obj->actl->color + 100;
        }
}

void place_piece(objects_t *obj)
{
    for (int i = 0; obj->actl->form[i]; i++)
        place_line(obj, obj->actl->form[i], i);
    for (int i = 0; obj->actl->form[i]; i++)
        free(obj->actl->form[i]);
    free(obj->actl->form);
    free(obj->actl);
    obj->actl = NULL;
}
