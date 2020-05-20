/*
** EPITECH PROJECT, 2020
** game_render
** File description:
** game_render
*/

#include "tetris.h"

void static display_line(char *line, int i)
{
    int k = 0;

    mvprintw(i + 1, 33, "|");
    mvprintw(i + 1, k + 34, "%c", line[0]);
    for (k = 0; line[k]; k = k + 2) {
        attron(COLOR_PAIR(line[k + 1] - 99));
        mvprintw(i + 1, k + 34, " %c", line[k]);
        attroff(COLOR_PAIR(line[k + 1] - 99));
    }
    mvprintw(i + 1, k + 33, "|");
}

void static display_actual_form_line(char *line, int y, int x)
{
    for (int k = 0; line[k]; k++)
        if (line[k] == '*')
            mvprintw(y + 1, x + k * 2 + 34, "%c", line[k]);
}

void static display_actual_form(objects_t *obj)
{
    int x = obj->actl->pos_x * 2 + 1;
    int y = obj->actl->pos_y;

    attron(COLOR_PAIR(obj->actl->color + 1));
    for (int i = 0; obj->actl->form[i]; i++)
        display_actual_form_line(obj->actl->form[i], y + i, x);
    attroff(COLOR_PAIR(obj->actl->color + 1));
}

void static display_map(objects_t *obj)
{
    mvprintw(0, 33, "+");
    for (int i = 0; i < obj->command->m_size_x * 2 - 1; i++) {
        mvprintw(0, 33 + i + 1, "-");
        mvprintw(0, 33 + i + 2, "+");
    }
    for (int i = 0; i < obj->command->m_size_y; i++)
        display_line(obj->map[i], i);
    mvprintw(obj->command->m_size_y + 1, 33, "+");
    for (int i = 0; i < obj->command->m_size_x * 2 - 1; i++) {
        mvprintw(obj->command->m_size_y + 1, 33 + i + 1, "-");
        mvprintw(obj->command->m_size_y + 1, 33 + i + 2, "+");
    }
}

void game_render(objects_t *obj)
{
    clear();
    display_interface(obj);
    display_map(obj);
    if (obj->actl != NULL)
        display_actual_form(obj);
}
