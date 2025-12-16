#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: Array to partition
 * @size: Size of array
 * @low: Starting index
 * @high: Ending index
 *
 * Return: Partition index
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
    int pivot = array[high];  /* Pivot is last element */
    int i = low - 1;          /* Index of smaller element */
    int j;

    for (j = low; j <= high - 1; j++)
    {
        /* If current element is smaller than or equal to pivot */
        if (array[j] <= pivot)
        {
            i++;  /* Increment index of smaller element */
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }
    
    /* Swap pivot with element at i+1 */
    if (i + 1 != high)
    {
        swap(&array[i + 1], &array[high]);
        print_array(array, size);
    }
    
    return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function for Quick sort
 * @array: Array to sort
 * @size: Size of array
 * @low: Starting index
 * @high: Ending index
 */
void quick_sort_recursive(int *array, size_t size, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index */
        int pi = lomuto_partition(array, size, low, high);
        
        /* Separately sort elements before and after partition */
        quick_sort_recursive(array, size, low, pi - 1);
        quick_sort_recursive(array, size, pi + 1, high);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: Array to sort
 * @size: Size of array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    
    quick_sort_recursive(array, size, 0, size - 1);
}
