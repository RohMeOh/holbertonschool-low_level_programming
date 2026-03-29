#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * close_fd - closes a file descriptor
 * @fd: file descriptor to close
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, rd, wr;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close_fd(fd_from);
		dprintf(2, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	rd = 1024;
	while (rd == 1024)
	{
		rd = read(fd_from, buffer, 1024);
		if (rd == -1)
		{
			close_fd(fd_from);
			close_fd(fd_to);
			dprintf(2, "Error: Can't read from file %s\n", argv[1]);
			exit(98);
		}

		wr = write(fd_to, buffer, rd);
		if (wr == -1)
		{
			close_fd(fd_from);
			close_fd(fd_to);
			dprintf(2, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}

	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}
