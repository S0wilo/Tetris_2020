/*
** EPITECH PROJECT, 2019
** test
** File description:
** empty
*/

int my_getnbr_loop(int count, int test_nb, char const *str)
{
    int stock_nb = 0;

    for (int i = 0; i <= count; i = i + 1) {
        if (str[i] >= 48 && str[i] <= 57  && test_nb < 2) {
            stock_nb++;
            test_nb = 1;
        } else if (test_nb == 1) {
            test_nb = 5;
        }
    }
}

int puissance(int nb_puiss)
{
    int result_pui = 1;

    for (int i = 0; i < nb_puiss - 1; i = i + 1) {
        result_pui = result_pui * 10;
    }
    return (result_pui);
}

int negative(char const *str, int loop_nb, int stock, int nb_neg)
{
    int negative = 1;

    if (str[loop_nb] == 45 && stock == 0) {
        negative = -1;
    } else if (str[loop_nb] < 48 && str[loop_nb] > 57 && stock > 0) {
        negative = nb_neg;
    }
    if (str[loop_nb] >= 48 && str[loop_nb] <= 57) {
        negative = nb_neg;
    }
    return (negative);
}

int integer(int stock)
{
    if (stock < -32767 || stock > 32767) {
        stock = 0;
    }
    return (stock);
}

int my_getnbr(char const *str)
{
    int count = 0;
    int test_nb = 0;
}
