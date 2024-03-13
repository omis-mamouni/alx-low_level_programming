#include "search_algos.h"

/**
 * binary_search_rec - searches for a value in a sorted array of integers
 * using the Binary search algorithm recursivly
 * @array: is a pointer to the first element of the array to search in
 * @value: the value to search for
 * @start: the index from where to start the binary search
 * @end: the index at which to end the binary search
 * Return: Return the index of the value when found, and -1 otherwise
 */
int binary_search_rec(int *array, int value, size_t start, size_t end)
{
	size_t i, middle;

	/* Base */
	if (end < start)
		return (-1);

	/* Print searching array */
	printf("Searching in array: ");
	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i != end)
			printf(", ");
	}
	printf("\n");

	/* binary search */
	middle = (start + end) / 2;

	if (array[middle] == value)
		return (middle);

	if (value < array[middle])
		return (binary_search_rec(array, value, start, middle - 1));
	else
		return (binary_search_rec(array, value, middle + 1, end));
}
/**
 * binary_search - searches for a value in a sorted array of integers
 * using the Binary search algorithm
 * @array:  is a pointer to the first element of the array to search in
 * @value: the value to search for
 * @size: is the number of elements in array
 * Return: Return the index of the value when found, and -1 otherwise
 */
int binary_search(int *array, size_t size, int value)
{
	size_t start = 0, end = size - 1;

	if (!array)
		return (-1);

	return (binary_search_rec(array, value, start, end));
}
