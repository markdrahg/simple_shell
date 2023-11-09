#include "main.h"

/**
 * my_getenv - works like getenv
 *  and seeks the environment pointer
 *
 * @name : The name of the paased
 *  on arg
 * Return: (NULL)
 */
char *my_getenv(const char *name)
{
	char **env;

	if (name == NULL || environ == NULL)
	{
		return (NULL);
	}

	for (env = environ; *env != NULL; env++)
	{
		char *variable = *env;
		char *equals = my_strchr(variable, '=');

		if (equals != NULL)
		{
			ptrdiff_t name_length = equals - variable;

			if (name_length > 0 && my_strncmp(name, variable, (size_t)name_length) == 0)
			{
				return (equals + 1);
			}
		}
	}

	return (NULL);
}

/**
 * my_strchr - works like the strchr
 *  function
 * @c: The passed-on str
 * @a: The passed-on numeric
 *  data
 *
 * Return: (NULL)
 */

char *my_strchr(const char *c, int a)
{
	char ch = (char)my_tolower(a);
	char *ptr = (char *)c;

	while (*ptr != '\0')
	{
		if (my_tolower(*ptr) == ch)
		{
			return (ptr);
		}
		ptr++;
	}

	if (*ptr == ch)
	{
		return (ptr);
	}

	return (NULL);
}

/**
 * my_tolower - works like the tolower
 *  function
 *
 * @c: The passed on args
 * Return: (1)
 */
int my_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}
