#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_vals - swaps two integer values in an array.
 * @a: the first integer to swap.
 * @b: the second integer to swap.
 */
void swap_vals(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * lomuto_partition - partitions the array
 * @array: the array to be partitioned
 * @size: the array size
 * @left: the left index of the partition
 * @right: the right index of the partition
 *
 * Return: the index of the pivot element
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
int *pivot, higher, lower;

pivot = array + right;
for (higher = lower = left; lower < right; lower++)
{
if (array[lower] < *pivot)
{
if (higher < lower)
{
swap_vals(array + lower, array + higher);
print_array(array, size);
}
higher++;
}
}

if (array[higher] > *pivot)
{
swap_vals(array + higher, pivot);
print_array(array, size);
}

return (higher);
}

/**
 * lomuto_sort - recursively implements the lamuto quicksort algorithm
 * @array: the array to be sorted
 * @size: the array size
 * @left: the left index of the partition
 * @right: the right index of the partition
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
int pivot_idx;

if (right - left > 0)
{
pivot_idx = lomuto_partition(array, size, left, right);
lomuto_sort(array, size, left, pivot_idx - 1);
lomuto_sort(array, size, pivot_idx + 1, right);
}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using Lomuto quick sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

lomuto_sort(array, size, 0, size - 1);
}
