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
 * bubble_sort - sorts an array of integers in ascending order.
 * @array: the array to be sorted
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
bool bubble = false;
size_t i, length = size;

if (array == NULL || size < 2)
return;

while (bubble == false)
{
bubble = true;
for (i = 0; i < length - 1; i++)
{
if (array[i] > array[i + 1])
{
swap_vals(array + i, array + i + 1);
print_array(array, size);
bubble = false;
}
}
length--;
}
}
