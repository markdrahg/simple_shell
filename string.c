#include "main.h"

/**
 * showchar - makes a print out
 * @str: what to be printed
 *
 * Return: (null)
 */
void showchar(const char *str)
{
	while (*str != '\0')
	{
		char ch = *str;

		write(1, &ch, 1);
		str++;
	}
}

/**
 * compare - compares two strings
 * @sa: first string
 * @sb: second string
 *
 * Return: (0)
 */
int compare(const char *sa, const char *sb)
{
	while (*sa && *sb && *sa == *sb)
	{
		sa++;
		sb++;
	}
	return (*sa - *sb);
}

/**
 * my_strncmp - compares two strings with
 *  passed on integer value
 * @sa: first character
 * @sb: second character
 * @n: number of args
 *
 * Return: (0)
 */

int my_strncmp(const char *sa, const char *sb, size_t n)
{
	while (n-- > 0)
	{
		if (*sa != *sb)
		{
			return (*sa - *sb);
		}
		if (*sa == '\0')
		{
			return (0);
		}
		sa++;
		sb++;
	}
	return (0);
}
