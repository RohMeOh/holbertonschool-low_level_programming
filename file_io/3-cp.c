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
 * print_error_97 - prints usage error
 */
void print_error_97(void)
{
	dprintf(2, "Usage: cp file_from file_to\n");
	exit(97);
}

/**
 * print_error_98 - prints read error
 * @file: file name
 */
void print_error_98(char *file)
{
	dprintf(2, "Error: Can't read from file %s\n", file);
	exit(98);
}

/**
 * print_error_99 - prints write error
 * @file: file name
 */
void print_error_99(char *file)
{
	dprintf(2, "Error: Can't write to %s\n", file);
	exit(99);
}

/**
 * main - copies content from one file to another
 * @argc: number of arguments
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, rd, wr, total;

	char buffer[1024];

	if (argc != 3)
		print_error_97();

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		print_error_98(argv[1]);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		print_error_99(argv[2]);

	rd = read(fd_from, buffer, 1024);
	while (rd > 0)
	{
		total = 0;
		while (total < rd)
		{
			wr = write(fd_to, buffer + total, rd - total);
			if (wr == -1)
				print_error_99(argv[2]);
			total += wr;
		}
		rd = read(fd_from, buffer, 1024);
	}

	if (rd == -1)
		print_error_98(argv[1]);

	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}
