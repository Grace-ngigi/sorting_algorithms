#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array of integers
 * @array: pointer to the array to be sorted
 * @size: size of the array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swap_flag;

	for (i = 0; i < size; i++)
	{
		swap_flag = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				swap_flag = 1;
				print_array(array, size);
			}
		}
		if (swap_flag == 0)
			break;
	}
}
