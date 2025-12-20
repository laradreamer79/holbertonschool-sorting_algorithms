#include "sort.h"

/**
* swap_adjacent - Swaps two adjacent nodes in a doubly linked list
* @list: Double pointer to the head of the list
* @node1: First node (comes before node2)
* @node2: Second node (comes after node1)
*/
void swap_adjacent(listint_t **list, listint_t *node1, listint_t *node2)
{
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

/**
* swap_non_adjacent - Swaps two non-adjacent nodes
* @list: Double pointer to the head of the list
* @node1: First node
* @node2: Second node
*/
void swap_non_adjacent(listint_t **list, listint_t *node1, listint_t *node2)
{
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

/**
* swap_nodes - Swaps two nodes in a doubly linked list
* @list: Double pointer to the head of the list
* @node1: First node to swap
* @node2: Second node to swap
*/
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
if (node1->next == node2)
swap_adjacent(list, node1, node2);
else if (node2->next == node1)
swap_adjacent(list, node2, node1);
else
swap_non_adjacent(list, node1, node2);
}

/**
* cocktail_pass - Performs one pass of cocktail sort
* @list: Double pointer to the head of the list
* @current: Current node pointer
* @boundary: Boundary marker
* @forward: Direction flag (1 for forward, 0 for backward)
* Return: 1 if any swap occurred, 0 otherwise
*/
int cocktail_pass(listint_t **list, listint_t **current,
listint_t *boundary, int forward)
{
int swapped = 0;
listint_t *next_node;

while (forward ? (*current)->next != boundary
: (*current)->prev != boundary)
{
if (forward)
next_node = (*current)->next;
else
next_node = (*current)->prev;

if ((forward && (*current)->n > next_node->n) ||
(!forward && (*current)->n < next_node->n))
{
swap_nodes(list, forward ? *current : next_node,
forward ? next_node : *current);
print_list(*list);
swapped = 1;
}
else
{
*current = forward ? (*current)->next : (*current)->prev;
}
}

return (swapped);
}

/**
* cocktail_sort_list - Sorts a doubly linked list of integers
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

if (cocktail_pass(list, &current, end, 1))
swapped = 1;

if (!swapped)
break;

swapped = 0;
end = current;

if (cocktail_pass(list, &current, start, 0))
swapped = 1;

start = current;
}
}
