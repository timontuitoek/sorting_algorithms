#include "sort.h"

/**
 * counting_sort - Sort an array of integers in ascending order
 *	using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted;
	int max, u;

	if (array == NULL || size < 2)
	return;

	/* Find the maximum value in the array */
	max = array[0];
	for (u = 1; u < (int)size; u++)
	{
	if (array[u] > max)
	max = array[u];
	}

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
	{
	free(count);
	return;
	}

	for (u = 0; u <= max; u++)
	count[u] = 0;

	for (u = 0; u < (int)size; u++)
	count[array[u]] += 1;

	print_array(count, max + 1);

	for (u = 0; u < (int)size; u++)
	{
	sorted[count[array[u]] - 1] = array[u];
	count[array[u]] -= 1;
	}

	for (u = 0; u < (int)size; u++)
	array[u] = sorted[u];

	free(sorted);
	free(count);
}
