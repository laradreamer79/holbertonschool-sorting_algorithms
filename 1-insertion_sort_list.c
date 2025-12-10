#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using insertion sort
 * @list: Double pointer to the head of the list
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *node_to_insert;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		node_to_insert = current;
		current = current->next;

		while (node_to_insert->prev &&
		       node_to_insert->prev->n > node_to_insert->n)
		{
			/* unlink node_to_insert */
			node_to_insert->prev->next = node_to_insert->next;
			if (node_to_insert->next)
				node_to_insert->next->prev = node_to_insert->prev;

			/* move node_to_insert before the previous node */
			node_to_insert->next = node_to_insert->prev;
			node_to_insert->prev = node_to_insert->next->prev;

			if (node_to_insert->prev)
				node_to_insert->prev->next = node_to_insert;
			else
				*list = node_to_insert;

			node_to_insert->next->prev = node_to_insert;

			print_list(*list);
		}
	}
}

