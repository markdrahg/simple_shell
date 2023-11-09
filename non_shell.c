#include "main.h"

#define MAX_COMMAND_LENGTH 1024

/**
 * my_execl - Takes command and
 *  it path then makes a run
 * @path: the path
 * @args: the argument
 *
 * Return: (0)
 */

int my_execl(const char *path, char *const args[])
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
 * non_shell - initializes the
 *  shell free runner
 *
 * Return: (0)
 */

int non_shell(void)
{
	char command[MAX_COMMAND_LENGTH];
	size_t command_len;
	pid_t child_pid;
	int status;

	if (_getline(command, MAX_COMMAND_LENGTH, STDIN_FILENO) == NULL)
	{
		perror("fgets");
		return (1);
	}
	command_len = my_strlen(command);
	if (command_len > 0 && command[command_len - 1] == '\n')
	{
		command[command_len - 1] = '\0';
	}
	child_pid = fork();
	if (child_pid < 0)
	{
		perror("fork");
		return (1);
	}
	else if (child_pid == 0)
	{
		char *cmd_args[2];

		cmd_args[0] = command;
		cmd_args[1] = NULL;
		if (my_execl(command, cmd_args) == -1)
		{
			perror("execl");
			exit(1);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
	return (0);
}

/**
 * my_strlen - returns the lenght
 *  of a string
 * @str: the passed on string
 *
 * Return: (0)
 */

int my_strlen(const char *str)
{
	int length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}
