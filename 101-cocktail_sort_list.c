#include "sort.h"

/**
* swap_nodes - Swaps two nodes in a doubly linked list
* @list: Double pointer to the head of the list
* @node1: First node to swap
* @node2: Second node to swap
*/
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
/* Handle adjacent nodes */
if (node1->next == node2)
{
/* Node1 is before Node2 */
node1->next = node2->next;
if (node2->next)
node2->next->prev = node1;
node2->prev = node1->prev;
node1->prev = node2;
node2->next = node1;

if (node2->prev)
node2->prev->next = node2;
else
*list = node2;
}
else if (node2->next == node1)
{
/* Node2 is before Node1 */
swap_nodes(list, node2, node1);
return;
}
else
{
/* Non-adjacent nodes */
listint_t *temp_prev = node1->prev;
listint_t *temp_next = node1->next;

node1->prev = node2->prev;
node1->next = node2->next;
node2->prev = temp_prev;
node2->next = temp_next;

if (node1->prev)
node1->prev->next = node1;
else
*list = node1;

if (node1->next)
node1->next->prev = node1;

if (node2->prev)
node2->prev->next = node2;
else
*list = node2;

if (node2->next)
node2->next->prev = node2;
}
}

/**
* cocktail_sort_list - Sorts a doubly linked list of integers in ascending
*                      order using the Cocktail shaker sort algorithm
* @list: Double pointer to the head of the list
*/
void cocktail_sort_list(listint_t **list)
{
int swapped = 1;
listint_t *current;
listint_t *start = NULL;
listint_t *end = NULL;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

current = *list;

while (swapped)
{
swapped = 0;

/* Forward pass (left to right) */
while (current->next != end)
{
if (current->n > current->next->n)
{
swap_nodes(list, current, current->next);
print_list(*list);
swapped = 1;
}
else
{
current = current->next;
}
}

if (!swapped)
break;

swapped = 0;
end = current;

/* Backward pass (right to left) */
while (current->prev != start)
{
if (current->n < current->prev->n)
{
swap_nodes(list, current->prev, current);
print_list(*list);
swapped = 1;
}
else
{
current = current->prev;
}
}

start = current;
}
}
