/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "tetris.h"

void static display_help(command_t command, char *name)
{
    my_putstr("Usage: ");
    my_putstr(name);
    my_putstr(" [options]\nOptions:\n--help\t\t\t");
    my_putstr("Display this help\n-L --level={num}\tStart Tetris at");
    my_putstr(" level num (def: 1)\n-l --key-left={K}\tMove the tetrimino");
    my_putstr(" LEFT using the K key (def: left arrow)\n-r --key-right={K}");
    my_putstr("\tMove the tetrimino RIGHT using the K key (def: right ");
    my_putstr("arrow)\n-t --key-turn={K}\tTURN the tetrimino clockwise 90d");
    my_putstr(" using the K key (def: top arrow)\n-d --key-drop={K}\tDROP");
    my_putstr(" the tetrimino using the K key (def: down arrow)\n-q --key");
    my_putstr("-quit={K}\tQUIT the game using the K key (def: 'q' key)\n");
    my_putstr("-p --key-restart={K}\tRESTART the game using the game ");
    my_putstr("using the K key (def: space bar)\n--map-size={row,col}");
    my_putstr("\tSet the numbers of rows and columns of the map (def:");
    my_putstr(" 20, 10)\n-w --without-next\tHide next tetrimino (def:");
    my_putstr(" false)\n-D --debug\t\tDebug mode (def: false)\n");
}

void static launch_help_debug_mode(char *name, tetro_t *form, command_t cmd)
{
    if (cmd.help == 1) {
        display_help(cmd, name);
        exit(0);
    }
    if (cmd.debug_mode == 1)
        debug_mode(form, cmd);
}

int static clear_form(tetro_t *form)
{
    tetro_t *pointer = form;

    if (form == NULL || form->next == NULL)
        return (0);
    pointer = pointer->next;
    while (pointer != NULL) {
        if (pointer->form == NULL && pointer->next != NULL) {
            pointer->prev->next = pointer->next;
            pointer->next->prev = pointer->prev;
        } else if (pointer->form == NULL)
            pointer->prev->next = pointer->next;
        pointer = pointer->next;
    }
}

int main(int argc, char **argv)
{
    command_t command = {1,'C','D','B','A','q',' ',10,20,0,0,0,0,0};
    char **map = NULL;
    tetro_t *form = NULL;

    if (handle_arg(argv, &command) == ERROR)
      return (ERROR);
    map = create_map(command);
    form = read_forms();
    if (form != NULL && command.debug_mode == 1 || command.help == 1)
        launch_help_debug_mode(argv[0], form, command);
    clear_form(form);
    if (map!=NULL&&form!=NULL&&form->next!=NULL&&form->next->next!=NULL) {
        game_loop(&command, map, form);
        while (command.restart == 1)
            game_loop(&command, map, form);
    }
}
