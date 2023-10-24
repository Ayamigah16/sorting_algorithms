#include "sort.h"

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
 * shell_sort - Sort an array of integers in ascending.
 * @array: the array to be sorted.
 * @size: the array size
 */
void shell_sort(int *array, size_t size)
{
size_t interval, i, j;

if (array == NULL || size < 2)
return;

for (interval = 1; interval < (size / 3);)
interval = interval * 3 + 1;

for (; interval >= 1; interval /= 3)
{
for (i = interval; i < size; i++)
{
j = i;
while (j >= interval && array[j - interval] > array[j])
{
swap_vals(array + j, array + (j - interval));
j -= interval;
}
}
print_array(array, size);
}
}
