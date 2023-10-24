#include "sort.h"

/**
 * get_max - gets the maximum value in an array.
 * @array: the array to find the maximum
 * @size: thesize of the array.
 *
 * Return: The maximum value in the array.
 */
int get_max(int *array, int size)
{
int max_val, i;

for (max_val = array[0], i = 1; i < size; i++)
{
if (array[i] > max_val)
max_val = array[i];
}

return (max_val);
}

/**
 * counting_sort - sorts an array
 * @array: the array to be sorted.
 * @size: the array size.
 */
void counting_sort(int *array, size_t size)
{
int *count, *sorted, max_val, i;

if (array == NULL || size < 2)
return;

sorted = malloc(sizeof(int) * size);
if (sorted == NULL)
return;
max_val = get_max(array, size);
count = malloc(sizeof(int) * (max_val + 1));
if (count == NULL)
{
free(sorted);
return;
}

for (i = 0; i < (max_val + 1); i++)
count[i] = 0;
for (i = 0; i < (int)size; i++)
count[array[i]] += 1;
for (i = 0; i < (max_val + 1); i++)
count[i] += count[i - 1];
print_array(count, max_val + 1);

for (i = 0; i < (int)size; i++)
{
sorted[count[array[i]] - 1] = array[i];
count[array[i]] -= 1;
}

for (i = 0; i < (int)size; i++)
array[i] = sorted[i];

free(sorted);
free(count);
}
