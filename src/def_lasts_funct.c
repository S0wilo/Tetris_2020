/*
** EPITECH PROJECT, 2020
** def_lasts_functs
** File description:
** def_lasts_functs
*/

#include "tetris.h"

int def_k_quit(char **argv, command_t *command, int *i)
{
    if (my_strcmp("-q",argv[i[0]])==0
        &&argv[i[0]+1]!=NULL&&my_strlen(argv[i[0]+1])==1) {
        command->k_quit = argv[i[0] + 1][0];
        i[0]++;
        return (0);
    }
    if (my_strcmp("--key-quit=", argv[i[0]]) == 0 && argv[i[0]][11]) {
        command->k_quit = argv[i[0]][11];
        return (0);
    }
    return (ERROR);
}

int def_k_restart(char **argv, command_t *command, int *i)
{
    if (my_strcmp("-p",argv[i[0]])==0
        &&argv[i[0]+1]!=NULL&&my_strlen(argv[i[0]+1])==1) {
        command->k_restart = argv[i[0] + 1][0];
        i[0]++;
        return (0);
    }
    if (my_strcmp("--key-restart=", argv[i[0]]) == 0 && argv[i[0]][11]) {
        command->k_restart = argv[i[0]][11];
        return (0);
    }
    return (ERROR);
}

int def_hide_next(char **argv, command_t *command, int *i)
{
    command->hide_next = 1;
}

int def_debug_mode(char **argv, command_t *command, int *i)
{
    command->debug_mode = 1;
}
