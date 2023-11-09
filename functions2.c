#include "main.h"

/**
 * my_snout -  concatenate the buffers
 *  with a slash
 *
 * @out: container
 * @val_w: size of data in the container
 * @stra: string 1
 * @strb: string 2
 *
 * Return: (void)
 */

void my_snout(char *out, size_t val_w, const char *stra, const char *strb)
{
	size_t i = 0;

	if (val_w == 0)
	{
		return;
	}

	while (i < val_w - 1 && *stra != '\0')
	{
		out[i] = *stra;
		i++;
		stra++;
	}

	if (i < val_w - 1)
	{
		out[i] = '/';
		i++;
	}

	while (i < val_w - 1 && *strb != '\0')
	{
		out[i] = *strb;
		i++;
		strb++;
	}
	out[i] = '\0';
}

/**
 * my_execvp2 -  Creates a new
 *  image
 *
 * @path: the path of the process
 * @args: the argument size
 *
 * Return: (0)
 */
int my_execvp2(const char *path, char *const args[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid < 0)
	{
		perror("fork");
		return (1);
	}
	else if (child_pid == 0)
	{
		if (access(path, X_OK) == 0)
		{
			execve(path, args, environ);
			perror("execv");
			exit(1);
		}
		else
		{
			showchar("unkown command");
			showchar("\n");
			exit(1);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}

	return (0);
}

