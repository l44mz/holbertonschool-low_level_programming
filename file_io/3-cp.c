#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 1024

/**
 * main - copies content from one file to another
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t r, w;
	char buffer[BUF_SIZE];

	if (argc != 3)
		exit(97);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDOUT_FILENO,
			"Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDOUT_FILENO,
			"Error: Can't write to %s\n", argv[2]);
		if (close(fd_from) == -1)
		{
			dprintf(STDOUT_FILENO,
				"Error: Can't close fd %d\n", fd_from);
			exit(100);
		}
		exit(99);
	}

	r = read(fd_from, buffer, BUF_SIZE);
	while (r > 0)
	{
		w = write(fd_to, buffer, r);
		if (w == -1 || w != r)
		{
			dprintf(STDOUT_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			if (close(fd_from) == -1)
			{
				dprintf(STDOUT_FILENO,
					"Error: Can't close fd %d\n", fd_from);
				exit(100);
			}
			if (close(fd_to) == -1)
			{
				dprintf(STDOUT_FILENO,
					"Error: Can't close fd %d\n", fd_to);
				exit(100);
			}
			exit(99);
		}
		r = read(fd_from, buffer, BUF_SIZE);
	}

	if (r == -1)
	{
		dprintf(STDOUT_FILENO,
			"Error: Can't read from file %s\n", argv[1]);
		if (close(fd_from) == -1)
		{
			dprintf(STDOUT_FILENO,
				"Error: Can't close fd %d\n", fd_from);
			exit(100);
		}
		if (close(fd_to) == -1)
		{
			dprintf(STDOUT_FILENO,
				"Error: Can't close fd %d\n", fd_to);
			exit(100);
		}
		exit(98);
	}

	if (close(fd_from) == -1)
	{
		dprintf(STDOUT_FILENO,
			"Error: Can't close fd %d\n", fd_from);
		exit(100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(STDOUT_FILENO,
			"Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}
