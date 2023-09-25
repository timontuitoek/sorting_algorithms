#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_quick_sort(array, 0, size - 1, size);
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: The array to be sorted
 * @lowest: The lowest index of the partition
 * @highest: The highest index of the partition
 * @size: The size of the array
 * Return: The index of the pivot element
 */
int lomuto_partition(int *array, int lowest, int highest, size_t size)
{
	int i = lowest - 1, j = lowest;
	int pivot = array[highest], temp = 0;

	for (; j < highest; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[highest])
	{
		temp = array[i + 1];
		array[i + 1] = array[highest];
		array[highest] = temp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * recursive_quick_sort - Recursive function to perform quick sort
 * @array: The array to be sorted
 * @lowest: The lowest index of the partition
 * @highest: The highest index of the partition
 * @size: The size of the array
 */
void recursive_quick_sort(int *array, int lowest, int highest, size_t size)
{
	int pivot;

	if (lowest < highest)
	{
		pivot = lomuto_partition(array, lowest, highest, size);
		recursive_quick_sort(array, lowest, pivot - 1, size);
		recursive_quick_sort(array, pivot + 1, highest, size);
	}
}

