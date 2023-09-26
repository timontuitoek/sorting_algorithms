#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t mid;
	int *left, *right;
	if (size < 2)
	return;

	mid = size / 2;
	left = array;
	right = array + mid;

	merge_sort(left, mid);
	merge_sort(right, size - mid);

	merge(array, left, mid, right, size - mid);
}

/**
 * merge - Merges two subarrays into one sorted array
 * @array: The original array
 * @left: Pointer to the left subarray
 * @left_size: Size of the left subarray
 * @right: Pointer to the right subarray
 * @right_size: Size of the right subarray
 */
void merge(int *array, int *left, size_t left_size,
		int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
	if (left[i] <= right[j])
	array[k++] = left[i++];
	else
	array[k++] = right[j++];
	}

	while (i < left_size)
	array[k++] = left[i++];

	while (j < right_size)
	array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, left_size + right_size);
}

