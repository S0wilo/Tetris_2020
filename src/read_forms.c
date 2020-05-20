/*
** EPITECH PROJECT, 2020
** read_forms
** File description:
** read_forms
*/

#include "tetris.h"
#include <errno.h>

int static compare_ext(char *name)
{
    char good_name[10] = ".tetrimino";
    int i = 0;

    for (i; name[i + 1]; i++);
    if (i < 10)
        return (ERROR);
    for (int k = 9; k >= 0; k--, i--)
        if (good_name[k] != name[i])
            return (ERROR);
}

int static check_param(FILE *fd, int *param)
{
    char *line = NULL;
    int k = 0;

    getline(&line, (size_t[1]){1024}, fd);
    for (int i = 0; line[i] && line[i] != '\n'; i++)
        if (line[i]<'0'&&line[i]!=' '||line[i]>'9'&&line[i]!=' ')
            return (ERROR);
    for (k; line[k + 1] && line[k + 1] != ' '; k++);
    for (int i = 0, n = 1; i <= k; i++, n = n * 10)
        param[0] += line[k - i] - '0' * n;
    k++;
    for (k; line[k + 1] && line[k + 1] != ' '; k++);
    for (int i = 0, n = 1;line[k-i]&&line[k-i]!=' ';i++,n=n*10)
        param[1] += line[k - i] - '0' * n;
    k++;
    for (k; line[k + 1] && line[k + 1] != '\n'; k++);
    for (int i = 0, n = 1;line[k-i]&&line[k-i]!=' ';i++,n=n*10)
        param[2] += line[k - i] - '0' * n;
    free(line);
}

int static stock_file(tetro_t *form, struct dirent *file)
{
    FILE *fd = fopen(my_strcat("tetriminos/",file->d_name), "r");
    tetro_t *new_form = malloc(sizeof(tetro_t));
    int param[3] = {0, 0, 0};

    if (fd == NULL||check_param(fd,param)==ERROR||new_form==NULL)
        param[0] = -1;
    if (param[0] == 0 || param[1] == 0 || param[2] < 0 || param[2] > 7)
        param[0] = -1;;
    form->next = new_form;
    new_form->next = NULL;
    new_form->prev = form;
    new_form->color = param[2];
    new_form->name = file->d_name;
    if (param[0] != -1)
        new_form->form = read_form_shape(fd, param);
    else
        new_form->form = NULL;
    new_form->x = param[0];
    new_form->y = param[1];
}

void static init_form(tetro_t *form)
{
    form->prev = NULL;
    form->next = NULL;
    form->color = 0;
    form->form = NULL;
    form->name = NULL;
}

tetro_t *read_forms(void)
{
    DIR *dir = opendir("tetriminos");
    struct dirent *rd_f = NULL;
    tetro_t *form = malloc(sizeof(tetro_t));

    if (dir == NULL || form == NULL)
        return (NULL);
    rd_f = readdir(dir);
    init_form(form);
    while (rd_f != NULL) {
        if (compare_ext(rd_f->d_name) != ERROR) {
            stock_file(form,rd_f);
            form = form->next;
        }
        rd_f = readdir(dir);
    }
    while (form->prev != NULL)
        form = form->prev;
    return (form);
}
