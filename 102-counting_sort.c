#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
* find_max - Finds the maximum value in an array
* @array: The array to search
* @size: Size of the array
* Return: Maximum value in the array
*/
int find_max(int *array, size_t size)
{
int max = array[0];
size_t i;

for (i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}
return (max);
}

/**
* build_count_array - Builds and initializes the count array
* @array: The original array
* @size: Size of the original array
* @max: Maximum value in the array
* Return: Pointer to count array, or NULL on failure
*/
int *build_count_array(int *array, size_t size, int max)
{
int *count;
size_t i;

count = malloc(sizeof(int) * (max + 1));
if (count == NULL)
return (NULL);

for (i = 0; i <= (size_t)max; i++)
count[i] = 0;

for (i = 0; i < size; i++)
count[array[i]]++;

return (count);
}

/**
* build_output_array - Builds the sorted output array
* @array: The original array
* @size: Size of the original array
* @count: The count array
* @max: Maximum value in the array
* Return: Pointer to output array, or NULL on failure
*/
int *build_output_array(int *array, size_t size, int *count, int max)
{
int *output;
size_t i;

output = malloc(sizeof(int) * size);
if (output == NULL)
return (NULL);

/* Convert count to cumulative count */
for (i = 1; i <= (size_t)max; i++)
count[i] += count[i - 1];

/* Print the counting array as required */
print_array(count, max + 1);

/* Build output array from end to maintain stability */
for (i = size; i > 0; i--)
{
output[count[array[i - 1]] - 1] = array[i - 1];
count[array[i - 1]]--;
}

return (output);
}

/**
* counting_sort - Sorts an array of integers in ascending order
*                 using the Counting sort algorithm
* @array: The array to be sorted
* @size: Number of elements in the array
*/
void counting_sort(int *array, size_t size)
{
int *count, *output;
int max;
size_t i;

if (array == NULL || size < 2)
return;

/* Find maximum value */
max = find_max(array, size);

/* Build and initialize count array */
count = build_count_array(array, size, max);
if (count == NULL)
return;

/* Build output array */
output = build_output_array(array, size, count, max);
if (output == NULL)
{
free(count);
return;
}

/* Copy sorted elements back to original array */
for (i = 0; i < size; i++)
array[i] = output[i];

/* Free allocated memory */
free(count);
free(output);
}
