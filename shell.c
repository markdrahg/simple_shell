#include "main.h"

#define MAX_LINE_LENGTH 80

/**
 *  execute_command - First stage of command
 *  interpritation and execution.
 *  @command: The passed on cmd to
 *  run in shell
 *
 * Return: (NUll)
 */

void execute_command(char *command)
{
	char *argv[MAX_LINE_LENGTH / 2 + 1];
	int argc = 0;
	char *token = strtok(command, " \n");

	while (token != NULL)
	{
		argv[argc++] = token;
		token = strtok(NULL, " \n");
	}

	argv[argc] = NULL;

	if (fork() == 0)
	{
		if (custom_execvp(argv[0], argv) < 0)
		{
			execve(command, argv, environ);
			perror("Error executing command");
		}
		exit(0);
	}
	else
	{
		wait(NULL);
	}
}

/**
 * call_shell - The main shell where command
 *  is passed on to
 *
 * Return: (0)
 */

int call_shell(void)
{
	char command[MAX_LINE_LENGTH];

	while (1)
	{
		signal(SIGINT, ctrl_c);
		showchar("$ ");
		if (_getline(command, MAX_LINE_LENGTH, STDIN_FILENO) != NULL)
		{
			if (my_strncmp(command, "exit", 4) == 0)
			{
				return (0);
			}
			else if (my_strncmp(command, "cd", 2) == 0)
			{
				showchar("CD Activated\n");
			}
			else
			{
				execute_command(command);
			}
		}
		else
		{
			showchar("\n");
			break;
		}
	}
	return (0);
}
