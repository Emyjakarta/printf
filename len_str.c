#include "main.h"
/**
 * len_str - Count the number of characters in a string.
 * @pt: The string to count.
 *
 * Return: Length of the string.
 */
int len_str(char *pt)
{
	int count = 0;

	while (pt[count] != '\0')
	{
		count++;
	}
	return (count);
}
