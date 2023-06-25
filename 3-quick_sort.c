#include <stdio.h>
#include "sort.h"

void quick_sort_recurcive(int *array, int left, int right);
int partition(int *array, int left, int right);
void swap(int *a, int *b);

/**
 * swap - swaps two values
 * @a: value a
 * @b: value b
 * Return: nothing
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * partition - partitions arr into tow parts
 * @array: pointer to the array to partition
 * @left: left part
 * @right: right part
 * Return: pivot
 */
int partition(int *array, int left, int right)
{
	int pivot = array[right];
	int i = left - 1, j;

	for (j = left; j <= right - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[right]);
	print_array(array, size);
	return (i + 1);
}
/**
 * quick_sort - sorts an rray using quick sort algorithm
 * @array: pointer to array to sort
 * @size: size of the array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recurcive(array, 0, size - 1);
}
/**
 * quick_sort_recurcive - compares left and right partitions
 * @array: pointer to array
 * @left: left part
 * @right: right part
 * Return: nothing
 */
void quick_sort_recurcive(int *array, int left, int right)
{
	if (left < right)
	{
		int pivotIndex;

		pivotIndex = partition(array, left, right);
		quick_sort_recurcive(array, left, pivotIndex - 1);
		quick_sort_recurcive(array, pivotIndex + 1, right);
	}
}
