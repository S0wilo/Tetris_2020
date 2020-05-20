/*
** EPITECH PROJECT, 2020
** debug_mode_tetri
** File description:
** debug_mode_tetri
*/

#include "tetris.h"
#include <sys/ioctl.h>
#include <termios.h>

void static display_name(char *name)
{
    for (int i = 0; name[i] && name[i] != '.'; i++)
        my_putchar(name[i]);
}

int static nb_len(char *line)
{
    int i = 0;

    for (int k = 0; line[k]; k++)
        if (line[k] == '*')
            i = k + 1;
    return (i);
}

void static display_shape(tetro_t *pointer)
{
    int i = 0;
    int k = 0;

    my_putstr("Size ");
    for (k; pointer->form[k]; k++)
        if (nb_len(pointer->form[k]) > i)
            i = nb_len(pointer->form[k]);
    my_put_nbr(i);
    my_putchar('*');
    my_put_nbr(k);
    my_putstr(" : Color ");
    my_put_nbr(pointer->color);
    my_putstr(" :\n");
    my_putstr(pointer->form[0]);
    for (i = 1; pointer->form[i]; i++) {
        my_putchar('\n');
        my_putstr(pointer->form[i]);
    }
}

void static display_tetriminos(tetro_t *form)
{
    tetro_t *pointer = form->next;

    while (pointer != NULL) {
        my_putstr("\nTetriminos : Name ");
        display_name(pointer->name);
        my_putstr(" : ");
        if (pointer->form == NULL)
            my_putstr("Error");
        else
            display_shape(pointer);
        pointer = pointer->next;
    }
}

void debug_mode_tetri(tetro_t *form)
{
    tetro_t *pointer = form->next;
    int i = 0;
    char *buffer = NULL;
    struct termios raw;
    struct termios stock;

    my_putstr("\nTetriminos : ");
    while (pointer != NULL) {
        pointer = pointer->next;
        i++;
    }
    my_put_nbr(i);
    display_tetriminos(form);
    my_putstr("\nPress any key to start Tetris\n");
    ioctl(STDIN_FILENO, TCGETS, &raw);
    ioctl(STDIN_FILENO, TCGETS, &stock);
    raw.c_lflag &= ~(ECHO | ICANON);
    ioctl(STDIN_FILENO, TCSETSF, &raw);
    read(STDIN_FILENO, &buffer, 1);
    ioctl(STDIN_FILENO, TCSETSF, &stock);
}
