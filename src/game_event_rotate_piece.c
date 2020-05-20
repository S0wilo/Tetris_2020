/*
** EPITECH PROJECT, 2020
** game_event_rotate_piece
** File description:
** game_event_rotate_piece
*/

#include "tetris.h"

int static check_line(objects_t *obj, char *line, int i)
{
    int x = obj->actl->pos_x;
    int y = obj->actl->pos_y;

    if (obj->actl->pos_x < 0)
        obj->actl->pos_x += 1;
    if (obj->actl->pos_y < 0)
        obj->actl->pos_y += 1;
    for (int k = 0; line[k]; k++)
        if (line[k]=='*'&&x+k>=obj->command->m_size_x-1)
            return (1);
    for (int k = 0; line[k]; k++)
        if (line[k] == '*' && obj->map[y + i][(k + x) * 2] == '*')
            return (1);
}

void static check_place(objects_t *obj)
{
    int size_y = obj->command->m_size_y - 1;
    int y = obj->actl->pos_y;

    for (int i = 0; obj->actl->form[i]; i++)
        if (y+i>=size_y||check_line(obj,obj->actl->form[i],i)==1) {
            i = -1;
            obj->actl->pos_x -= 1;
            obj->actl->pos_y -= 1;
        }
}

void game_event_rotate_piece(objects_t *obj)
{
    char **shape = NULL;
    int i = 0;
    int k = 0;

    for (i; obj->actl->form[0][i]; i++);
    shape = malloc(sizeof(char *) * (i + 1));
    for (k; obj->actl->form[k]; k++);
    for (int j = 0; j < i; j++) {
        shape[j] = malloc(sizeof(char) * (k + 1));
        for (int m = 0; m < k; m++) {
            shape[j][m] = obj->actl->form[k - m - 1][j];
            shape[j][m + 1] = '\0';
        }
        shape[j + 1] = NULL;
    }
    for (int j = 0; obj->actl->form[j]; j++)
        free(obj->actl->form[j]);
    free(obj->actl->form);
    obj->actl->form = shape;
    check_place(obj);
}
