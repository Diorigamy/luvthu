#include "shell.h"

/**
 * get_line - stores into malloced buffer the user's command into shell
 * @str: buffer
 * Return: number of characters read
 */
size_t get_line(char **str)
{
	ssize_t x = 0, sz = 0, er = 0, er1 = 0, y = 0;
	char buf[1024];

	while (er1 == 0 && (x = read(STDIN_FILENO, buf, 1024 - 1)))
	{
		if (x == -1)
			return (-1);

		buf[x] = '\0';

		y = 0;
		while (buf[y] != '\0')
		{
			if (buf[y] == '\n')
				er1 = 1;
			y++;
		}

		if (er == 0)
		{
			x++;
			*str = malloc(sizeof(char) * x);
			*str = _strcpy(*str, buf);
			sz = x;
			er = 1;
		}
		else
		{
			sz += x;
			*str = _strcat(*str, buf);
		}
	}
	return (sz);
}
