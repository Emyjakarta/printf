#include "main.h"
/**
 * len_str - Count the number of characters in a string.
 * @P: The string to be counted.
 *
 * Return: Length of the string.
 */
int len_str(char *P)
{
	int Q = 0;

	while (P[Q] != '\0')
	{
		Q++;
	}
	return (Q);
}
