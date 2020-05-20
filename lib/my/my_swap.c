/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/

int my_swap(int *a, int *b)
{
    int var_content_a = *a;
    int var_content_b = *b;

    *b = var_content_a;
    *a = var_content_b;
}
