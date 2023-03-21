#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
    char *ch= "_putchar" ;
    
    while (*ch)
    {
        putchar(*ch);
        *ch++;
    }
    putchar('\n');
    return (0);
}
