#include "sort.h"

/**
 * bubble_sort - sorts an array of int in ascending order using BSA
 * @array: pointer to array to sorted
 * @size: size of array
 *
 * Return: Null
 */

void bubble_sort(int *array, size_t size)
{
        size_t i, j;
        int temp, swapped;

        if (array == NULL || size <= 1)
                return;

        for (i = 0; i < size - 1; i++)
        {
                swapped = 0;

                for (j = 0; j < size - i - 1; j++)
                {
                        if (array[j] > array[j + 1])
                        {
                        /*swap array[j] and array[j + 1]*/
                        temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;

                        /*print array after each swap*/
                        print_array(array, size);
                        swapped = 1;
                        }
                }

        /*if no elements is swapped in inner loop, array is sorted*/
        if (swapped == 0)
                break;
        }
}

