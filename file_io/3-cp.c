#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * error_exit - prints error and exits with specific code
 * @code: exit code
 * @msg: error message
 * @filename: filename
 */
void error_exit(int code, char *msg, char *filename)
{
	dprintf(STDERR_FILENO, "%s %s\n", msg, filename);
	exit(code);
}

/**
 * main - copies content of a file to another
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd_from, fd_to, n_read, n_write;
	char buffer[1024];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file", av[1]);
	fd_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		error_exit(99, "Error: Can't write to", av[2]);
	}
	while ((n_read = read(fd_from, buffer, 1024)) > 0)
	{
		n_write = write(fd_to, buffer, n_read);
		if (n_write == -1 || n_write != n_read)
		{
			close(fd_from);
			close(fd_to);
			error_exit(99, "Error: Can't write to", av[2]);
		}
	}
	if (n_read == -1)
	{
		close(fd_from);
		close(fd_to);
		error_exit(98, "Error: Can't read from file", av[1]);
	}
	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from == -1 ? fd_to : fd_from);
		exit(100);
	}
	return (0);
}
