#include "sort.h"

int get_max(int *array, int size);
void radix_count_sort(int *array, size_t size, int sig, int *buffer);
void radix_sort(int *array, size_t size);

/**
 * get_max - gets the maximum value in an array.
 * @array: the array of integers.
 * @size: the size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
int max, i;

for (max = array[0], i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}

return (max);
}

/**
 * radix_count_sort - sorts the significant digits of an array
 * @array: the array of integers.
 * @size: the size of the array.
 * @sig_digit: the significant digit to sort on.
 * @buffer: A buffer to store the sorted array.
 */
void radix_count_sort(int *array, size_t size, int sig_digit, int *buffer)
{
int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
size_t i;

for (i = 0; i < size; i++)
count[(array[i] / sig_digit) % 10] += 1;

for (i = 0; i < 10; i++)
count[i] += count[i - 1];

for (i = size - 1; (int)i >= 0; i--)
{
buffer[count[(array[i] / sig_digit) % 10] - 1] = array[i];
count[(array[i] / sig_digit) % 10] -= 1;
}

for (i = 0; i < size; i++)
array[i] = buffer[i];
}

/**
 * radix_sort - sorts an array using the radix sort algorithm.
 *
 * @array: the array to be sorted.
 * @size: the size of the array.
 */
void radix_sort(int *array, size_t size)
{
int max, sig, *buffer;

if (array == NULL || size < 2)
return;

buffer = malloc(sizeof(int) * size);
if (buffer == NULL)
return;

max = get_max(array, size);
for (sig = 1; max / sig > 0; sig *= 10)
{
radix_count_sort(array, size, sig, buffer);
print_array(array, size);
}

free(buffer);
}
