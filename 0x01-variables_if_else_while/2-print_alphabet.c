#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void){

        int n, co;

        co = 0;

        while (co < 10)
        {
                for (n = 'a'; n <= 'z'; n++)
                {
                        putchar(n);
                }
                co++;
                putchar('\n');
	}
return (0);
}
