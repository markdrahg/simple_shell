#include "main.h"

#define MAX_COMMAND_LENGTH 1024

/**
 * main - The first processing poin
 * interactive mood or not
 *
 * Return: (0)
 */
int main(void)
{
	if (isatty(STDIN_FILENO))
	{
		call_shell();
	}
	else
	{
		non_shell();
	}
	return (EXIT_FAILURE);
}

