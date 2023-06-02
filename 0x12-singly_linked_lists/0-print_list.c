#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a linked list
 * @h: pointer to the list_t list to print
 *
 * Return: the number of nodes printed
 */
typedef struct list {
    char *str;
    struct list *next;
} list_t;

size_t print_list(const list_t *h) {
    size_t count = 0;

    while (h != NULL) {
        printf("%s\n", (h->str != NULL) ? h->str : "[0] (nil)");
        count++;
        h = h->next;
    }

    return count;
}
