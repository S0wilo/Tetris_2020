/*
** EPITECH PROJECT, 2020
** handle_arg
** File description:
** handle_arg
*/

#include "tetris.h"

int static add_map_size_x(char *arg, command_t *cmd, int i)
{
    int nb = 0;

    for (i; arg[i + 1]; i++)
        if (arg[i+1]!=','&&arg[i+1]<'0'||arg[i+1]!=','&&arg[i+1]>'9')
            return (0);
    for (int k = 1; arg[i] != ','; i--, k = k * 10)
        nb += (arg[i] - '0') * k;
    if (nb < 5)
        return (0);
    cmd->m_size_x = nb;
    return (1);
}

int static add_map_size(char *arg, command_t *cmd)
{
    int i = 1;
    int nb = 0;

    for (i; arg[i - 1] && arg[i - 1] != '='; i++);
    for (i; arg[i] && arg[i] != ','; i++)
        if (arg[i] < '0' || arg[i] > '9')
            return (0);
    i--;
    for (int k = 1; arg[i] != '='; i--, k = k * 10)
        nb += (arg[i] - '0') * k;
    if (nb < 5)
        return (0);
    cmd->m_size_y = nb;
    i++;
    if (add_map_size_x(arg, cmd, i) == 0)
        return (0);
    return (1);
}

int static check_help_map(char *arg, command_t *cmd)
{
    if (my_strcmp("--help", arg) == 0) {
        cmd->help = 1;
        return (1);
    } else if (my_strcmp("--map-size=",arg)==0&&add_map_size(arg,cmd)==1)
        return (1);
    return (0);
}

int static check_arg(char *arg, char **argv, command_t *command, int *i)
{
    int (*funct)(char **, command_t *, int *);

    for (int k = 0; arg_list[k].s1; k++) {
        if (my_strcmp(arg_list[k].s1,arg)==0
            ||my_strcmp(arg_list[k].s2,arg)==0) {
            funct = arg_list[k].f;
            return (funct(argv, command, i));
        } else if (check_help_map(arg, command) == 1)
            return (0);
    }
    return (ERROR);
}

int handle_arg(char **arg, command_t *command)
{
    for (int i = 1; arg[i]; i++) {
        if (check_arg(arg[i], arg, command, &i) == ERROR)
            return (ERROR);
    }
}
