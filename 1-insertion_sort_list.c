#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 *	using the Insertion sort algorithm.
 * @list: Pointer to a pointer to the head of the linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *sorted;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

	sorted = NULL;

	while (*list != NULL)
	{
	listint_t *current = *list;
	*list = (*list)->next;

	if (sorted == NULL || current->n < sorted->n)
	{
	current->next = sorted;
	current->prev = NULL;
	if (sorted != NULL)
	sorted->prev = current;
	sorted = current;
	}
	else
	{
	temp = sorted;

	while (temp->next != NULL && current->n >= temp->next->n)
	temp = temp->next;

	current->next = temp->next;
	current->prev = temp;
	if (temp->next != NULL)
	temp->next->prev = current;
	temp->next = current;
	}

	print_list(sorted);
	}

	*list = sorted;
}

