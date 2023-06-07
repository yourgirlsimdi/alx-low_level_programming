#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list
 * @head: Pointer to the head of the list
 *
 * Description: The function frees each node of the list
 *              and sets the head to NULL.
 */
void free_listint2(listint_t **head)
{
    listint_t *current;
    listint_t *next;

    if (head == NULL)
        return;

    current = *head;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}
