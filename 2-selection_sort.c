#include "sort.h"
/**
* swap_f - swaps two elements in array.
* @i: integer 1 to swap
* @j: integer 2 to swap
*
* Return: nothing
*/
void swap_f(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

/**
* selection_sort - sorts an array of integers in
* ascending order using the Selection sort algorithm
* @array: An array of integers.
* @size: The size of the array.
*
* Return: nothing
*/
void selection_sort(int *array, size_t size)
{
	int *min;

	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_f(array + i, min);
			print_array(array, size);
		}
	}
}
