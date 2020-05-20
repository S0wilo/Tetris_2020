/*
** EPITECH PROJECT, 2020
** def_firsts_funct
** File description:
** def_firsts_funct
*/

#include "tetris.h"

int def_level(char **argv, command_t *command, int *i)
{
    char *line = NULL;

    if (my_strcmp("-L", argv[i[0]]) == 0 && argv[i[0] + 1]) {
        line = argv[i[0] + 1];
        i[0]++;
    }
    else
        line = argv[i[0]];
    if (my_strcmp("--level=", line) == 0)
        for (int k = 0; line[0]&&line[0]<'0'||line[0]&&line[0]>'9';k++)
            line = line + 1;
    for (int k = 0; line[k]; k++)
        if (line[k] < '0' || line[k] > '9')
            return (ERROR);
    if (line[0] == '\0')
        return (ERROR);
    command->level = str_to_number(line);
}

int def_k_left(char **argv, command_t *command, int *i)
{
    if (my_strcmp("-l",argv[i[0]])==0
        &&argv[i[0]+1]!=NULL&&my_strlen(argv[i[0]+1])==1) {
        command->k_left = argv[i[0] + 1][0];
        i[0]++;
        return (0);
    }
    if (my_strcmp("--key-left=", argv[i[0]]) == 0 && argv[i[0]][11]) {
        command->k_left = argv[i[0]][11];
        return (0);
    }
    return (ERROR);
}

int def_k_right(char **argv, command_t *command, int *i)
{
    if (my_strcmp("-r",argv[i[0]])==0
        &&argv[i[0]+1]!=NULL&&my_strlen(argv[i[0]+1])==1) {
        command->k_right = argv[i[0] + 1][0];
        i[0]++;
        return (0);
    }
    if (my_strcmp("--key-right=", argv[i[0]]) == 0 && argv[i[0]][11]) {
        command->k_right = argv[i[0]][11];
        return (0);
    }
    return (ERROR);
}

int def_k_turn(char **argv, command_t *command, int *i)
{
    if (my_strcmp("-t",argv[i[0]])==0
        &&argv[i[0]+1]!=NULL&&my_strlen(argv[i[0]+1])==1) {
        command->k_turn = argv[i[0] + 1][0];
        i[0]++;
        return (0);
    }
    if (my_strcmp("--key-turn=", argv[i[0]]) == 0 && argv[i[0]][11]) {
        command->k_turn = argv[i[0]][11];
        return (0);
    }
    return (ERROR);
}

int def_k_drop(char **argv, command_t *command, int *i)
{
    if (my_strcmp("-d",argv[i[0]])==0
        &&argv[i[0]+1]!=NULL&&my_strlen(argv[i[0]+1])==1) {
        command->k_drop = argv[i[0] + 1][0];
        i[0]++;
        return (0);
    }
    if (my_strcmp("--key-drop=", argv[i[0]]) == 0 && argv[i[0]][11]) {
        command->k_drop = argv[i[0]][11];
        return (0);
    }
    return (ERROR);
}
