/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** return the square root
*/

int my_compute_square_root(int nb)
{
    int root = 0;
    int i = 0;

    while (root < nb) {
        i++;
        root = i * i;
    }
    if (root = nb) {
        return (i);
    } else {
        return (0);
    }
}
