#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node structure
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element
 * @next: Pointer to the next element
 */
typedef struct listint_s
{
	int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void print_list(const listint_t *list);
void selection_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);

#endif /* SORT_H */

