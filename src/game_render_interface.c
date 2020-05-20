/*
** EPITECH PROJECT, 2020
** game_render_interface
** File description:
** game_render_interface
*/

#include "tetris.h"

void static display_tetris_end(void)
{
    attron(COLOR_PAIR(3));
    mvprintw(0, 18, "* * *");
    mvprintw(1, 18, "*   *");
    mvprintw(2, 18, "* *");
    mvprintw(3, 18, "*   *");
    mvprintw(4, 18, "*   *");
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(6));
    mvprintw(0, 24, "*");
    mvprintw(2, 24, "*");
    mvprintw(3, 24, "*");
    mvprintw(4, 24, "*");
    attroff(COLOR_PAIR(6));
    attron(COLOR_PAIR(7));
    mvprintw(0, 26, "* * *");
    mvprintw(1, 26, "*");
    mvprintw(2, 26, "* * *");
    mvprintw(3, 26, "    *");
    mvprintw(4, 26, "* * *");
    attroff(COLOR_PAIR(7));
}

void static display_tetris(void)
{
    attron(COLOR_PAIR(2));
    mvprintw(0, 0, "* * *\n  *\n  *\n  *\n  *");
    attroff(COLOR_PAIR(2));
    attron(COLOR_PAIR(5));
    mvprintw(0, 6, "* * *");
    mvprintw(1, 6, "*");
    mvprintw(2, 6, "* *");
    mvprintw(3, 6, "*");
    mvprintw(4, 6, "* * *");
    attroff(COLOR_PAIR(5));
    attron(COLOR_PAIR(4));
    mvprintw(0, 12, "* * *");
    mvprintw(1, 12, "  *");
    mvprintw(2, 12, "  *");
    mvprintw(3, 12, "  *");
    mvprintw(4, 12, "  *");
    attroff(COLOR_PAIR(4));
    display_tetris_end();
}

void static display_info(objects_t *obj)
{
    int time = (clock() - obj->real_time) / 30000;

    mvprintw(8, 0, "/---------------------------\\");
    mvprintw(9, 0, "|                           |");
    mvprintw(10, 0, "| High Score                |");
    mvprintw(10, 13, "%d", obj->command->high_score);
    mvprintw(11, 0, "| Score                     |");
    mvprintw(11, 8, "%d", (obj->level - 10) * 10);
    mvprintw(12, 0, "|                           |");
    mvprintw(13, 0, "| Lines                     |");
    mvprintw(13, 8, "%d", obj->level - 10);
    mvprintw(14, 0, "| Level                     |");
    mvprintw(14, 8, "%d", obj->level / 10);
    mvprintw(15, 0, "|                           |");
    mvprintw(16, 0, "| Timer                     |");
    mvprintw(16, 8, "%d:%d", time / 60, time % 60);
    mvprintw(17, 0, "\\---------------------------/");
}

void static display_next(objects_t *obj)
{
    tetro_t *piece = obj->form->next;
    int x = 35 + (obj->command->m_size_x * 2);

    mvprintw(0, x, "/-next------\\");
    mvprintw(1, x, "|           |");
    mvprintw(2, x, "|           |");
    mvprintw(3, x, "|           |");
    mvprintw(4, x, "|           |");
    mvprintw(5, x, "\\-----------/");
    for (int i = 0; piece != NULL && piece->form[i]; i++) {
        attron(COLOR_PAIR(piece->color + 1));
        for (int k = 0; piece->form[i][k]; k++)
            mvprintw(i + 1,x + 1 + k * 2, "%c", piece->form[i][k]);
        attroff(COLOR_PAIR(piece->color + 1));
    }
}

void display_interface(objects_t *obj)
{
    display_tetris();
    display_info(obj);
    if (obj->command->hide_next == 0)
        display_next(obj);
    if ((obj->level - 10) * 10 > obj->command->high_score)
        obj->command->high_score = (obj->level - 10) * 10;
}
