#include "main.h"

/**
 * ctrl_c- Reads the input
 *@signum: container
 *
 * Return: void
 */

void ctrl_c(int signum)
{
	if (signum == SIGINT)
	{
		signal(SIGINT, ctrl_c);
		showchar("\n");
		showchar("$ ");
		fflush(stdout);
	}
}
