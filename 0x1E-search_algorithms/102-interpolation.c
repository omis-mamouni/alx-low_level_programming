#include "search_algos.h"

/**
 * interpolation_search_rec - searches for a value in a
 * sorted array of integers using the Interpolation search algorithm
 * @array: is a pointer to the first element of the array to search in
 * @low: the index of the lowest value in array
 * @high: the index of the highest value in array
 * @value: the value to search for
 * Return: The index of the sought value or -1 on failure
 */
int interpolation_search_rec(int *array, size_t low, size_t high, int value)
{
	size_t pos;

	pos = low + (((double)(high - low) / (array[high] - array[low]))
		     * (value - array[low]));

	if (low > high || value < array[low] || value > array[high])
	{
		printf("Value checked array[%ld] is out of range\n", pos);
		return (-1);
	}

	printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
	if (array[pos] == value)
		return (pos);
	if (array[pos] > value)
		return (interpolation_search_rec(array, low, pos - 1, value));
	if (array[pos] < value)
		return (interpolation_search_rec(array, pos + 1, high, value));

	return (-1);
}

/**
 * interpolation_search - searches for a value in a sorted array of integers
 * using the Interpolation search algorithm
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: the value to search for
 * Return: The index of the sought value or -1 on failure
 */
int interpolation_search(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	return (interpolation_search_rec(array, 0, size - 1, value));
}
