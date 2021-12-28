#include "lists.h"

/**
 * insert_node - Inserts a number into a sorted singly linked list
 * @head: pointer to head of list
 * @number: number to insert in the linked list
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current = *head, *new_node = NULL;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = number;
	new_node->next = NULL;

	if (!*head || current->n >= number)
	{
		new_node->next = *head;
		return (*head = new_node);
	}
	while (current)
	{
		if (!current->next || current->next->n >= number)
		{
			new_node->next = current->next;
			return (current->next = new_node);
		}
		current = current->next;
	}
	return (NULL);
}
