#include "main.h"

#define MAX_COMMAND_LENGTH 1024


/**
 * nonshell_error - error printer
 *
 * Return: (Error)
 */

int nonshell_error(void)
{
	perror("read");
	return (EXIT_FAILURE);
}

/**
 * my_execl100 - Takes command and
 *  it path then makes a run
 * @path: the path
 * @args: the argument
 *
 * Return: (0)
 */

int my_execl100(const char *path, char *const args[])
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
		my_execvp2(path, args);
		exit(1);
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
	return (0);
}


/**
 * non_shell2 - initializes the
 *  shell free runner
 * @input_fd: the path
 *
 * Return: (0)
 */

int non_shell2(int input_fd)
{
	char command[MAX_COMMAND_LENGTH];
	size_t command_len;
	pid_t child_pid;
	int status;

	ssize_t read_bytes = read(input_fd, command, MAX_COMMAND_LENGTH);

	if (read_bytes < 0)
	{
		nonshell_error();
	}
	command_len = (size_t)read_bytes;

	if (command_len > 0 && command[command_len - 1] == '\n')
	{
		command[command_len - 1] = '\0';
		command_len--;
	}
	child_pid = fork();
	if (child_pid < 0)
	{
		nonshell_error();
	}
	else if (child_pid == 0)
	{
		char *cmd_args[4];

		cmd_args[0] = "/bin/sh";
		cmd_args[1] = "-c";
		cmd_args[2] = command;
		cmd_args[3] = NULL;
		if (my_execvp2("/bin/sh", cmd_args) == -1)
		{
			nonshell_error();
		}
	} else
	{
		waitpid(child_pid, &status, 0);
	}
	return (EXIT_SUCCESS);
}
