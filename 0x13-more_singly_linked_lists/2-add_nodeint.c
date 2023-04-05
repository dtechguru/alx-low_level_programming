#include "lists.h"

/**
 * add_nodient-adds a new node at the begining of a linked list
 * @head: pointer to the first node in the lists
 * @n: data to insert in that new code
 *
 * Return: pointer to the new node, or NULL if fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;
	new = malloc(sizeof(listint_t));
	if(!new)
	return(NULL);

	new->n=n;
	new->next- *head;
	*head = new;

	return(new);
}
