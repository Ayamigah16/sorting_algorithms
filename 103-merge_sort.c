#include "sort.h"

void merge_subarray(int *subarray, int *buffer, size_t front, size_t mid,
size_t back);
void merge_sort_recursive(int *subarray, int *buffer, size_t front,
size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarray - sorts a subarray.
 * @subarray: the subarray to be sorted.
 * @buffer: the buffer to store the sorted subarray.
 * @front: the front index of the array.
 * @mid: the middle index of the array.
 * @back: the back index of the array.
 */
void merge_subarray(int *subarray, int *buffer, size_t front, size_t mid,
size_t back)
{
size_t i, j, k = 0;

printf("Merging...\n[left]: ");
print_array(subarray + front, mid - front);

printf("[right]: ");
print_array(subarray + mid, back - mid);

for (i = front, j = mid; i < mid && j < back; k++)
buffer[k] = (subarray[i] < subarray[j]) ? subarray[i++] : subarray[j++];
for (; i < mid; i++)
buffer[k++] = subarray[i];
for (; j < back; j++)
buffer[k++] = subarray[j];
for (i = front, k = 0; i < back; i++)
subarray[i] = buffer[k++];

printf("[Done]: ");
print_array(subarray + front, back - front);
}

/**
 * merge_sort_recursive - implements the merge sort
 * algorithm through recursion.
 * @subarray: the subarray of the array to be sorted.
 * @buffer: the buffer to store the sorted result.
 * @front: the front index of the subarray.
 * @back: the back index of the subarray.
 */
void merge_sort_recursive(int *subarray, int *buffer, size_t front,
size_t back)
{
size_t mid_val;

if (back - front > 1)
{
mid_val = front + (back - front) / 2;
merge_sort_recursive(subarray, buffer, front, mid_val);
merge_sort_recursive(subarray, buffer, mid_val, back);
merge_subarray(subarray, buffer, front, mid_val, back);
}
}

/**
 * merge_sort - sorts an array using the merge sort algorithm.
 * @array: the array to be sorted.
 * @size: the array size.
 */
void merge_sort(int *array, size_t size)
{
int *buffer;

if (array == NULL || size < 2)
return;

buffer = malloc(sizeof(int) * size);
if (buffer == NULL)
return;

merge_sort_recursive(array, buffer, 0, size);

free(buffer);
}
