#include <stdio.h>
#include "sort.h"

/**
* lomuto_partition - Performs the Lomuto partition scheme on an array.
* @array: Array of integers to be sorted.
* @low: Starting index of the partition.
* @high: Ending index of the partition.
* @size: Number of elements in the array.
* Return: New index to start the next recursive partition.
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot, temp;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (array[i] != array[j])
				print_array(array, size);
			i++;
		}
	}

	temp = array[i];
	array[i] = array[high];
	array[high] = temp;

	if (array[i] != array[high])
		print_array(array, size);

	return (i);
}

/**
* lomuto_quicksort - recursively sorts an array of integers using Lomuto
* quicksort.
* @array: Array of integers to be sorted.
* @low: Starting index of the partition.
* @high: Ending index of the partition.
* @size: Number of elements in the array.
*/
void lomuto_quicksort(int *array, int low, int high, size_t size)
{
	int partition_index;

	if (low < high)
	{
		partition_index = lomuto_partition(array, low, high, size);
		lomuto_quicksort(array, low, partition_index - 1, size);
		lomuto_quicksort(array, partition_index + 1, high, size);
	}
}

/**
* quick_sort - sorts an array of integers in ascending order using Lomuto
* quicksort.
* @array: Array of integers to be sorted.
* @size: Number of elements in the array.
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	lomuto_quicksort(array, 0, (int)size - 1, size);
}
