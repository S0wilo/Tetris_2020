/*
** EPITECH PROJECT, 2020
** game_loop
** File description:
** game_loop
*/

#include "tetris.h"

void static down_piece(objects_t *obj)
{
    if (obj->actl != NULL)
        obj->actl->pos_y += 1;
}

void static define_init(objects_t *obj)
{
    initscr();
    curs_set(0);
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, 0, 0);
    init_pair(2, 1, 0);
    init_pair(3, 2, 0);
    init_pair(4, 3, 0);
    init_pair(5, 4, 0);
    init_pair(6, 5, 0);
    init_pair(7, 6, 0);
    init_pair(8, 7, 0);
    obj->command->restart = 0;
}

int static check_lose(objects_t *obj)
{
    for (int i = 0; obj->map[0][i]; i++)
        if (obj->map[0][i] == '*')
            return (1);
}

int static check_terminal_size(command_t *cmd)
{
    int row = 0;
    int col = 0;

    getmaxyx(stdscr, row, col);
    if (row < cmd->m_size_y + 4 || col < cmd->m_size_x * 2 + 50) {
        refresh();
        clear();
        return (1);
    }
    return (0);
}

int game_loop(command_t *cmd, char **map, tetro_t *form)
{
    objects_t obj = {cmd,map,form,NULL,cmd->level*10,clock(),clock()};

    define_init(&obj);
    while (cmd->restart == 0) {
        game_event(&obj);
        game_handling_piece(&obj);
        delete_full_line(&obj);
        game_render(&obj);
        if (obj.time + 100000 / (obj.level - obj.level % 10) < clock()) {
            obj.time = clock();
            down_piece(&obj);
        }
        usleep(50000);
        if (check_lose(&obj) == 1) {
            endwin();
            return (0);
        }
        while (check_terminal_size(cmd) == 1)
            mvprintw(0, 0, "Your terminal is to small.");
    }
}
