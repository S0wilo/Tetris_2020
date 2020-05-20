/*
** EPITECH PROJECT, 2020
** game_event
** File description:
** game_event
*/

#include "tetris.h"

void static restart_game(objects_t *obj)
{
    for (int i = 0; obj->map[i]; i++)
        for (int k = 0; obj->map[i][k]; k++)
            obj->map[i][k] = ' ';
    obj->command->restart = 1;
}

void static quit_game(void)
{
    endwin();
    exit(0);
}

void static other_keys(int ch, objects_t *obj)
{
    if (ch == obj->command->k_quit)
        quit_game();
    if (ch == obj->command->k_restart)
        restart_game(obj);
}

int static arrow_handling(int ch)
{
    if (ch > 250)
        return (ch - 193);
    return (ch);
}

void game_event(objects_t *obj)
{
    command_t *cmd = obj->command;
    int ch = getch();

    ch = arrow_handling(ch);
    if (obj->actl != NULL)
        if (ch==cmd->k_left||ch==cmd->k_right)
            game_event_move(ch, obj, cmd);
        else if (ch==cmd->k_drop||ch==cmd->k_turn)
            game_event_move(ch, obj, cmd);
    other_keys(ch, obj);
}
