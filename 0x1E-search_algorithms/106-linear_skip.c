#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: a pointer to the head of the skip list to search in
 * @value: the value to search for
 * Return: a pointer on the first node where value is
 * located or NULL on failure
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node;

	if (!list)
		return (NULL);

	node = list->express;

	while (node->express && node->next && node->n <= value)
	{
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
		if (node->n == value)
			return (node);

		if (value <= node->express->n)
		{
			printf("Value found between indexes [%ld] and [%ld]\n",
			       node->index, node->express->index);
			while (node->next)
			{
				printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
				if (node->n == value)
					return (node);
				node = node->next;
			}
		}

		node = node->express;
	}

	return (NULL);
}
