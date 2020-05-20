/*
** EPITECH PROJECT, 2020
** game_handling_piece
** File description:
** game_handling_piece
*/

#include "tetris.h"

void static create_new_piece(objects_t *obj)
{
    char **shape = obj->form->next->form;
    int y = obj->form->next->y;
    int x = obj->form->next->x;

    obj->actl = malloc(sizeof(piece_t));
    obj->actl->color = obj->form->next->color;
    obj->actl->form = malloc(sizeof(char *) * (y + 1));
    for (int i = 0; i < obj->form->next->y; i++) {
        obj->actl->form[i] = malloc(sizeof(char) * (x + 1));
        for (int k = 0; k < obj->form->next->x; k++) {
            obj->actl->form[i][k] = obj->form->next->form[i][k];
            obj->actl->form[i][k + 1] = '\0';
        }
        obj->actl->form[i + 1] = NULL;
    }
    obj->actl->pos_y = 0;
    obj->actl->pos_x = obj->command->m_size_x / 2 - x / 2;
}

int static check_down_line(objects_t *obj, char *line, int i)
{
    int x = obj->actl->pos_x;
    int y = obj->actl->pos_y;

    for (int k = 0; line[k]; k++)
        if (line[k] == '*'&&obj->map[i+y+1][(k+x)*2]!= ' ')
            return (1);
}

int static check_can_go_down(objects_t *obj)
{
    for (int i = 0; obj->actl->form[i]; i++)
        if (i + obj->actl->pos_y >= obj->command->m_size_y - 1
            || check_down_line(obj, obj->actl->form[i], i) == 1) {
            place_piece(obj);
            return (0);
        }
}

void static switch_piece_order(objects_t *obj)
{
    tetro_t *pointer = obj->form;
    tetro_t *stock = obj->form->next;

    while (pointer->next != NULL)
        pointer = pointer->next;
    obj->form->next = obj->form->next->next;
    obj->form->next->prev = obj->form;
    pointer->next = stock;
    stock->prev = pointer;
    stock->next = NULL;
}

void game_handling_piece(objects_t *obj)
{
    if (obj->actl == NULL) {
        create_new_piece(obj);
        if (obj->form->next->next != NULL)
            switch_piece_order(obj);
    }
    check_can_go_down(obj);
}
