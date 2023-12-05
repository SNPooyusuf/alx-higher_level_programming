#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 * @X: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for ALX project
 */
typedef struct listint_s
{
	int X;
	struct listint_s *next;
} listint_t;

size_t print_listint(const listint_t *h);
listint_t *add_nodeint(listint_t **head, const int X);
void free_listint(listint_t *head);
int check_cycle(listint_t *list);

#endif
