#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 *
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{

	listint_t *curr;
	listint_t *key;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
                return;

	while (curr != NULL)
	{
		key = curr;
		temp = curr->prev;

		while (temp != NULL && temp->n > key->n)
		{
			/* Swap key and temp */
			if (temp->prev != NULL)
				temp->prev->next = key;
			else
				*list = key;

			if (key->next != NULL)
				key->next->prev = temp;

			temp->next = key->next;
			key->prev = temp->prev;
			key->next = temp;
			temp->prev = key;

			/* Print the list after swapping */
			print_list(*list);

			temp = key->prev;
		}

		curr = curr->next;
	}
}
