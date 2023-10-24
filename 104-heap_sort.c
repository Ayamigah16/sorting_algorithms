#include "sort.h"

void swap_vals(int *a, int *b);
void heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * heapify - turns a binary tree into a complete binary heap.
 * @array: the binary tree array.
 * @size: the size of the array/tree.
 * @base: the index of the base row of the tree.
 * @root: the root node of the binary tree.
 */
void heapify(int *array, size_t size, size_t base, size_t root)
{
size_t left, right, large;

left = 2 * root + 1;
right = 2 * root + 2;
large = root;

if (left < base && array[left] > array[large])
large = left;
if (right < base && array[right] > array[large])
large = right;

if (large != root)
{
swap_vals(array + root, array + large);
print_array(array, size);
heapify(array, size, base, large);
}
}

/**
 * heap_sort - Sort an array
 * using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
int i;

if (array == NULL || size < 2)
return;

for (i = (size / 2) - 1; i >= 0; i--)
heapify(array, size, size, i);

for (i = size - 1; i > 0; i--)
{
swap_vals(array, array + i);
print_array(array, size);
heapify(array, size, i, 0);
}
}
