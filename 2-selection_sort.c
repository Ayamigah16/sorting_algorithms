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
 * selection_sort - Sort an array of integers
 * @array: the array to be sorted.
 * @size: the array size.
 */
void selection_sort(int *array, size_t size)
{
size_t i, j;
int *min_index;

if (array == NULL || size < 2)
return;

for (i = 0; i < size - 1; i++)
{
min_index = array + i;
for (j = i + 1; j < size; j++)
min_index = (array[j] < *min_index) ? (array + j) : min_index;

if ((array + i) != min_index)
{
swap_vals(array + i, min_index);
print_array(array, size);
}
}
}
