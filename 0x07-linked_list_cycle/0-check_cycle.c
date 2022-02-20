#include "lists.h"

/**
 * check_cycle - detect cycles
 * @list: head
 * Return: 0 | 1
 */
int check_cycle(listint_t *list)
{
	listint_t *t = NULL;
	listint_t *r = NULL;

	if (!list)
		return (0);

	t = list;
	r = list;

	while (t && r)
	{
		t = t->next;
		r = r->next->next;
		if (t == r)
			return (1);
	}
	return (0);
}
