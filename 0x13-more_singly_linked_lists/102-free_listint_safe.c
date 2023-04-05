#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list
 * @h: data type listint_t double pointer of head
 * Return: the size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	size_t counter = 0;
	listint_t *safe_node = *h;
	listint_t *temp;

	if (!h)
		return (0);
	while (safe_node != NULL)
	{
		counter++;
		temp = safe_node;
		safe_node = safe_node->next;
		free(temp);

		if (temp < safe_node)
			break;
	}
	*h = NULL;
	return (counter);
}
