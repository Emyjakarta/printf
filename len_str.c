#include "main.h"
/**
 * len_str - Count the number of characters in a string.
 * @PTR: The string to count.
 *
 * Return: Length of the string.
 */
int len_str(char *PTR)
{
	int Q = 0;

	while (PTR[Q] != '\0')
	{
		Q++;
	}
	return (Q);
}
