/*
** EPITECH PROJECT, 2020
** read_form_shape
** File description:
** read_form_shape
*/

#include "tetris.h"

int static check_line(char *line, int *param)
{
    int i = 0;
    int k = 0;

    for (i = 0; line[i] && line[i] != '\n'; i++)
        if (line[i] != '*' && line[i] != ' ')
            return (ERROR);
    line[i] = '\0';
    for (int j = 0; line[j]; j++)
        if (line[j] == '*')
            k++;
    if (k > param[0])
        return (ERROR);
}

int static adapt_line(char **shape, int i, int *param)
{
    char *new_line = malloc(sizeof(char) * (param[0] + 1));
    int k = 0;

    if (new_line == NULL) {
        shape[i] = NULL;
        return (0);
    }
    for (k; shape[i][k]; k++)
        new_line[k] = shape[i][k];
    for (k; k < param[0]; k++) {
        new_line[k] = ' ';
        new_line[k + 1] = '\0';
    }
    free(shape[i]);
    shape[i] = new_line;
}

char **read_form_shape(FILE *fd, int *param)
{
    char **shape = malloc(sizeof(char *) * (param[1] + 1));

    if (shape == NULL)
        return (NULL);
    for (int i = 0; i < param[1]; i++) {
        getline(&shape[i], (size_t[1]){1024}, fd);
        shape[i + 1] == NULL;
        if (shape[i] == NULL)
            return (NULL);
    }
    for (int i = 0; i < param[1]; i++)
        if (check_line(shape[i], param) == ERROR)
            return (NULL);
    for (int i = 0; shape[i]; i++)
        if (my_strlen(shape[i]) < param[0])
            adapt_line(shape, i, param);
    for (int i = 0; i < param[1]; i++)
        if (shape[i] == NULL)
            return (NULL);
    return (shape);
}
