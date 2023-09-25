#include "sort.h"

/**
 * selection_sort - sorts array of int in ascending order using SSA
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: NULL
 */

void selection_sort(int *array, size_t size)
{
	size_t i, k, min_index;
	int temp;

	if (array == NULL || size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		for (k = i + 1; k < size; k++)
		{
			if (array[k] < array[min_index])
				min_index = k;
		}

		if (min_index != i)
		{
			/* swap elements */
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;

			/* print_array after swap */
			print_array(array, size);
		}
	}
}
