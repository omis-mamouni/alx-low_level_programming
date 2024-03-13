#include "search_algos.h"
#include <math.h>

/**
 * jump_search - searches for a value in a sorted array of integers
 * using the Jump search algorithm
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 * Return: The index of the search value if found, -1 otherwise
 */
int jump_search(int *array, size_t size, int value)
{
	size_t jump, do_jump = 1, i = 0;

	if (!array)
		return (-1);

	jump = sqrt(size);

	while (i < size)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);

		if (i + jump < size && do_jump)
		{
			if (value <= array[i + jump])
			{
				printf("Value found between indexes [%ld] and [%ld]\n", i, i + jump);
				do_jump = 0;
				i -= 1;
			}
		}

		if (i + jump >= size && do_jump)
		{
			printf("Value found between indexes [%ld] and [%ld]\n", i, i + jump);
			do_jump = 0;
			i -= 1;
		}

		if (do_jump)
			i += jump;
		else
			i += 1;
	}

	return (-1);
}
