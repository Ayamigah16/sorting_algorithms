#include "sort.h"

void swap_vals(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_vals - swaps two values in an array.
 * @a: the first value to swap.
 * @b: the second value to swap.
 */
void swap_vals(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * hoare_partition - sorts an array's subset using hoare partition scheme
 * @array: the array .
 * @size: the array size.
 * @left: the start index of the subset.
 * @right: the end index of the subset.
 *
 * Return: the final partition index.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
int pivot, higher, lower;

pivot = array[right];
for (higher = left - 1, lower = right + 1; higher < lower;)
{
do {
higher++;
} while (array[higher] < pivot);
do {
lower--;
} while (array[lower] > pivot);

if (higher < lower)
{
swap_vals(array + higher, array + lower);
print_array(array, size);
}
}

return (higher);
}

/**
 * hoare_sort - quicksort algorithm using hoare partition through recursion.
 * @array: the array to be sorted.
 * @size: the size of the array.
 * @left: the start index of the array partition to order.
 * @right: the end index of the array partition to order.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
int pivot_idx;

if (right - left > 0)
{
pivot_idx = hoare_partition(array, size, left, right);
hoare_sort(array, size, left, pivot_idx - 1);
hoare_sort(array, size, pivot_idx, right);
}
}

/**
 * quick_sort_hoare - sorts an array using the quicksort algorithm.
 * @array: the array to be sorted.
 * @size: the size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

hoare_sort(array, size, 0, size - 1);
}
