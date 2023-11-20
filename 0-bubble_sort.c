#include <stdio.h>
#include "sort.h"
/**
 * bubble_sort - sorts the algorithm in ascending order
 * @array: array to sort
 * @size: size of array to be sorted
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swap;

	for (i = 0; i < size - 1; ++i)
	{
		swap = 0;
		for (j = 0; j < size - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swap = 1;
			}
		}
		if (swap == 0)
			break;
	}
}
