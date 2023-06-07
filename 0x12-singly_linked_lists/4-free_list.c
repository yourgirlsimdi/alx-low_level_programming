#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Frees a list_t list.
 * @head: Pointer to the head node.
 */
void free_list(list_t *head)
{
	list_t *current, *tmp;

	current = head;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp->str);
		free(tmp);
	}
}
