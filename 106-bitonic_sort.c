#include "sort.h"

void swap_vals(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq_size,
char direction);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq_size,
char direction);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_vals(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * bitonic_merge - sorts a bitonic sequence inside an array.
 * @array: the array to be sorted.
 * @size: the size of the array.
 * @start: the starting index of the sequence in array to sort.
 * @seq_size: the size of the sequence to sort.
 * @direction: the direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq_size,
char direction)
{
size_t i, jump = seq_size / 2;

if (seq_size > 1)
{
for (i = start; i < start + jump; i++)
{
if ((direction == UP && array[i] > array[i + jump]) ||
(direction == DOWN && array[i] < array[i + jump]))
swap_vals(array + i, array + i + jump);
}
bitonic_merge(array, size, start, jump, direction);
bitonic_merge(array, size, start + jump, jump, direction);
}
}

/**
 * bitonic_seq - converts an array into a bitonic sequence.
 * @array: the array to convert.
 * @size: the size of the array.
 * @start: the starting index of the bitonic sequence.
 * @seq_size: the size of the bitonic sequence.
 * @direction: the direction to sort the bitonic sequence in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq_size,
char direction)
{
size_t cut = seq_size / 2;
char *str = (direction == UP) ? "UP" : "DOWN";

if (seq_size > 1)
{
printf("Merging [%lu/%lu] (%s):\n", seq_size, size, str);
print_array(array + start, seq_size);

bitonic_seq(array, size, start, cut, UP);
bitonic_seq(array, size, start + cut, cut, DOWN);
bitonic_merge(array, size, start, seq_size, direction);

printf("Result [%lu/%lu] (%s):\n", seq_size, size, str);
print_array(array + start, seq_size);
}
}

/**
 * bitonic_sort - sorts an array using the bitonic sort algorithm.
 * @array: the array to be sorted.
 * @size: the size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

bitonic_seq(array, size, 0, size, UP);
}
