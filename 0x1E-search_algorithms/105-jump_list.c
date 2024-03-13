#include "search_algos.h"
#include <math.h>

/**
 * get_node_by_idx - gets a node by its index
 * @list: The head of the linked list
 * @size: size of the linked list
 * @idx: the index of the node to get
 * Return: Return the node, or NULL on failure
 */
listint_t *get_node_by_idx(listint_t *list, size_t size, size_t idx)
{
	size_t i;

	if (idx >= size)
		return (NULL);

	for (i = 0; i < idx; i++)
		list = list->next;

	return (list);
}

/**
 * jump_list - searches for a value in a sorted list of integers using
 * the Jump search algorithm
 * @list: is a pointer to the head of the list to search in
 * @size: is the number of nodes in list
 * @value: is the value to search for
 * Return: return a pointer to the first node where value is located
 * or NULL on failure
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	listint_t *node;
	size_t jump, i = 0, do_jump = 1;

	if (!list)
		return (NULL);

	jump = sqrt(size);

	while (i < size)
	{
		node = get_node_by_idx(list, size, i);
		printf("Value checked at index [%ld] = [%d]\n", i, node->n);
		if (node->n == value)
			return (node);

		if (i + jump < size && do_jump)
		{
			if (value <= get_node_by_idx(list, size, i + jump)->n)
			{
				printf("Value found between indexes [%ld] and [%ld]\n", i, i + jump);
				do_jump = 0;
				i -= 1;
			}
		}

		if (i + jump >= size && do_jump)
		{
			printf("Value found between indexes [%ld] and [%ld]\n", i, i + jump - 1);
			do_jump = 0;
			i -= 1;
		}

		if (do_jump)
			i += jump;
		else
			i += 1;
	}

	return (NULL);
}
