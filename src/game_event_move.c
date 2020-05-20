/*
** EPITECH PROJECT, 2020
** game_event_move
** File description:
** game_event_move
*/

#include "tetris.h"

int static drop_pce_chk(objects_t *obj, char *line, int i)
{
    int x = obj->actl->pos_x;
    int y = obj->actl->pos_y;

    for (int k = 0; line[k]; k++)
        if (line[k] == '*' && obj->map[y + i + 1][(x + k) * 2] == '*')
            return (1);
}

int static drop_piece(objects_t *obj)
{
    int y = obj->actl->pos_y;
    int size_y = obj->command->m_size_y;

    for (int i = 0; obj->actl->form[i]; i++)
        if (y+i>= size_y-1||drop_pce_chk(obj,obj->actl->form[i],i)==1)
            return (1);
    obj->actl->pos_y += 1;
    return (0);
}

int static event_rotate_drop(int ch, objects_t *obj, command_t *cmd)
{
    int return_val = 0;

    if (ch == cmd->k_drop) {
        while (return_val == 0)
            return_val = drop_piece(obj);
        return (0);
    }
    if (ch == cmd->k_turn)
        game_event_rotate_piece(obj);
}

int game_event_move(int ch, objects_t *obj, command_t *cmd)
{
    int x = obj->actl->pos_x;
    int y = obj->actl->pos_y;

    if (ch == cmd->k_left && check_go_left(obj) == 1) {
        obj->actl->pos_x -= 1;
        return (0);
    }
    if (ch == cmd->k_right && check_go_right(obj) == 1) {
        obj->actl->pos_x += 1;
        return (0);
    }
    event_rotate_drop(ch, obj, cmd);
}
