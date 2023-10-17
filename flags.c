#include "main.h"
/**
 * handle _ Plus_flag-handle plus flag
 * @num: Number
 * Return: 0 (Success)
 */
int handle_plus_flag(int num)
{
	if (num >= 0)
	{
		write(1, "+", 1);
		return (1);
	}
	return (0);
}
#include "main.h"
/**
 * handle_space_flag-handle space flag
 * @num: number
 * Return:0
 */
int handle_space_flag(int num)
{
	if (num >= 0)
	{
		write(1, " ", 1);
		return (1);
	}
	return (0);
}
#include "main.h"
/**
 * handle_hash_flag-handle hash flag
 * @num: number
 * Return:0
 */
int handle_hash_flag(int num)
{
	if (num >= 0)
	{
		write(1, "#", 1);
		return (1);
	}
	return (0);
}
