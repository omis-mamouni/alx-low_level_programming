#include <stdio.h>


/**
 * print_alphabet - a function that prints the alphabet, in lowercase
 *
 * Return: no return  (Succes)
 */
void print_alphabet(void)
{
	char i;
	for (i ='a' ; i <= 'z' ; i++)
		putchar (i);
	putchar('\n');
}
