#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 *	using the Insertion sort algorithm.
 * @list: Pointer to a pointer to the head of the linked list.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current = NULL, *temp = NULL;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = *list;
    current = current->next;
    
    while (current)
    {
        while (current->prev && current->n < current->prev->n)
        {
            temp = current;
            if (current->next)
                (current->next)->prev = temp->prev;
            (temp->prev)->next = temp->next;
            current = current->prev;
            temp->prev = current->prev;
            temp->next = current;
            if (current->prev)
                (current->prev)->next = temp;
            current->prev = temp;
            if (temp->prev == NULL)
                *list = temp;
            print_list(*list);
            current = current->prev;
        }
        current = current->next;
    }
}

