/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** return 1 if the number is prime and 0 if not
*/

int my_is_prime(int nb)
{
    int count = 0;

    for (int i = 2; i < nb; i = i + 1) {
        if (nb % i == 0) {
            count++;
        }
    }
    if (count > 0) {
        return (0);
    } else {
        return (1);
    }
}
