/*
** EPITECH PROJECT, 2019
** my_sort_int_array
** File description:
** sorts an integer
*/

void my_sort_int_array(int *array, int size)
{
    int count = 0;
    int test = 0;

    while (count <= size) {
        if (array[count] <= array[count+1]) {
            count++;
        } else {
            test = array[count];
            array[count] = array[count+1];
            array[count+1] = test;
            count = 0;
        }
    }
}
