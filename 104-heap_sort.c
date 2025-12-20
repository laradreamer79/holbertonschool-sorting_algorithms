#include "sort.h"

/**
* swap_ints - Swaps two integers in an array
* @a: First integer to swap
* @b: Second integer to swap
*/
void swap_ints(int *a, int *b)
{
int tmp = *a;
*a = *b;
*b = tmp;
}

/**
* sift_down - Performs sift-down operation on a heap
* @array: The array to heapify
* @size: Size of the array
* @start: Starting index of the heap
* @end: Ending index of the heap
*/
void sift_down(int *array, size_t size, size_t start, size_t end)
{
size_t root = start;
size_t child, swap;

while ((root * 2 + 1) <= end)
{
child = root * 2 + 1;  /* Left child */
swap = root;

/* Check if left child is greater than root */
if (array[swap] < array[child])
swap = child;

/* Check if right child exists and is greater than current max */
if (child + 1 <= end && array[swap] < array[child + 1])
swap = child + 1;

/* If root is already the largest, heap property is satisfied */
if (swap == root)
return;

/* Swap root with the larger child */
swap_ints(&array[root], &array[swap]);
print_array(array, size);
root = swap;
}
}

/**
* heapify - Builds a max heap from an array
* @array: The array to heapify
* @size: Size of the array
*/
void heapify(int *array, size_t size)
{
int start;

/* Start from the last non-leaf node */
start = (size / 2) - 1;

while (start >= 0)
{
sift_down(array, size, start, size - 1);
start--;
}
}

/**
* heap_sort - Sorts an array of integers in ascending order
*             using the Heap sort algorithm
* @array: The array to be sorted
* @size: Number of elements in the array
*/
void heap_sort(int *array, size_t size)
{
size_t end;

if (array == NULL || size < 2)
return;

/* Build max heap */
heapify(array, size);

/* Extract elements from heap one by one */
end = size - 1;
while (end > 0)
{
/* Swap root (max element) with last element */
swap_ints(&array[0], &array[end]);
print_array(array, size);

/* Reduce heap size and restore heap property */
end--;
sift_down(array, size, 0, end);
}
}
