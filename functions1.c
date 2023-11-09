#include "main.h"

#define MAX_BUFFER_SIZE 1024

/**
 * custom_execvp - acts as execvp
 * @file: the file
 * @argv: the argument
 *
 * Return: (0)
 */

int custom_execvp(const char *file, char *const argv[])
{
	char *path = my_getenv("PATH");
	char *token;
	char *path_copy;

	if (path == NULL)
	{
		return (-1);
	}
	path_copy = my_strdup(path);

	if (path_copy == NULL)
	{
		perror("strdup");
		return (-1);
	}
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		char full_path[1024];

		my_snout(full_path, sizeof(full_path), token, file);
		if (execve(full_path, argv, environ) == -1)
		{
			token = strtok(NULL, ":");
		}
		else
		{
			free(path_copy);
			return (0);
		}
	}
	free(path_copy);
	return (-1);
}

/**
 * _getline - gets a new line to work out
 * @str: string arg
 * @size: size arg
 * @fd: folder arg
 *
 * Return: (0)
 */

char *_getline(char *str, int size, int fd)
{
	int bytesRead = 0;
	char c;

	if (size <= 0 || str == NULL || fd < 0)
	{
		return (NULL);
	}
	while (bytesRead < size - 1)
	{
		if (read(fd, &c, 1) <= 0)
		{
			break;
		}
		str[bytesRead] = c;
		bytesRead++;

		if (c == '\n')
		{
			break;
		}
	}
	if (bytesRead == 0)
	{
		return (NULL);
	}
	str[bytesRead] = '\0';
	return (str);
}

/**
 * my_strdup - duplicates string
 * @str: string arg
 *
 * Return: (0)
 */
char *my_strdup(const char *str)
{
	size_t len = 0;
	size_t i;
	char *dup_str;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[len] != '\0')
	{
		len++;
	}
	dup_str = (char *)malloc(len + 1);

	if (dup_str == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i <= len; i++)
	{
		dup_str[i] = str[i];
	}
	return (dup_str);
}
