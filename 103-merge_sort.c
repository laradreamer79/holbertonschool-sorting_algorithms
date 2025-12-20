#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
* print_subarray - Prints a subarray
* @label: Label for the subarray
* @array: The array to print
* @start: Starting index
* @end: Ending index
*/
void print_subarray(char *label, int *array, size_t start, size_t end)
{
size_t i;

printf("[%s]: ", label);
for (i = start; i <= end; i++)
{
if (i > start)
printf(", ");
printf("%d", array[i]);
}
printf("\n");
}

/**
* merge - Merges two sorted subarrays
* @array: The main array
* @temp: Temporary array for merging
* @left_start: Start index of left subarray
* @mid: Middle index (end of left, start of right)
* @right_end: End index of right subarray
*/
void merge(int *array, int *temp, size_t left_start,
size_t mid, size_t right_end)
{
size_t left = left_start;
size_t right = mid + 1;
size_t i = left_start;
size_t k;

/* Print left and right subarrays being merged */
print_subarray("left", array, left_start, mid);
print_subarray("right", array, mid + 1, right_end);

/* Merge the two subarrays into temp */
while (left <= mid && right <= right_end)
{
if (array[left] <= array[right])
temp[i++] = array[left++];
else
temp[i++] = array[right++];
}

/* Copy remaining elements from left subarray */
while (left <= mid)
temp[i++] = array[left++];

/* Copy remaining elements from right subarray */
while (right <= right_end)
temp[i++] = array[right++];

/* Copy merged elements back to original array */
for (k = left_start; k <= right_end; k++)
array[k] = temp[k];

/* Print the merged result */
printf("[Done]: ");
for (k = left_start; k <= right_end; k++)
{
if (k > left_start)
printf(", ");
printf("%d", array[k]);
}
printf("\n");
}

/**
* merge_sort_recursive - Recursively divides and sorts array
* @array: The array to sort
* @temp: Temporary array for merging
* @left: Left index
* @right: Right index
*/
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
size_t mid;

if (left < right)
{
/* Calculate mid point, ensuring left size <= right size */
mid = left + (right - left - 1) / 2;

/* Recursively sort left and right halves */
merge_sort_recursive(array, temp, left, mid);
merge_sort_recursive(array, temp, mid + 1, right);

/* Merge the sorted halves */
printf("Merging...\n");
merge(array, temp, left, mid, right);
}
}

/**
* merge_sort - Sorts an array of integers in ascending order
*              using the Merge sort algorithm
* @array: The array to be sorted
* @size: Number of elements in the array
*/
void merge_sort(int *array, size_t size)
{
int *temp;

if (array == NULL || size < 2)
return;

/* Allocate temporary array (only one malloc call allowed) */
temp = malloc(sizeof(int) * size);
if (temp == NULL)
return;

/* Start recursive merge sort */
merge_sort_recursive(array, temp, 0, size - 1);

/* Free temporary array */
free(temp);
}
