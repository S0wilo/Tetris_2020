/*
** EPITECH PROJECT, 2020
** debug_mode
** File description:
** debug_mode
*/

#include "tetris.h"

int static display_key(char key)
{
    char arrow_code[5] = {'A', 'B', 'C', 'D', ' '};
    char *arrow[5] = {"^EOB\0", "^EOA\0", "^EOD\0", "^EOC\0", "(space)\0"};

    for (int i = 0; i < 5; i++)
        if (key == arrow_code[i]) {
            my_putstr(arrow[i]);
            return (0);
        }
    my_putchar(key);
}

void static display_last_opt(command_t command)
{
    my_putstr("Level :  ");
    my_put_nbr(command.level);
    my_putstr("\nSize :  ");
    my_put_nbr(command.m_size_y);
    my_putchar('*');
    my_put_nbr(command.m_size_x);
}

void static display_command(command_t command)
{
    my_putstr("*** DEBUG MODE ***\n");
    my_putstr("Key Left :  ");
    display_key(command.k_left);
    my_putstr("\nKey Right :  ");
    display_key(command.k_right);
    my_putstr("\nKey Turn :  ");
    display_key(command.k_turn);
    my_putstr("\nKey Drop :  ");
    display_key(command.k_drop);
    my_putstr("\nKey Quit :  ");
    display_key(command.k_quit);
    my_putstr("\nKey Pause :  ");
    display_key(command.k_restart);
    my_putstr("\nNext :  ");
    if (command.hide_next == 1)
        my_putstr("Yes\n");
    else
        my_putstr("No\n");
    display_last_opt(command);
}

void debug_mode(tetro_t *form, command_t command)
{
    display_command(command);
    debug_mode_tetri(form);
}
