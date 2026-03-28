#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the file
 * @text_content: NULL terminated string to add
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t w;
	int len = 0;

	if (filename == NULL)
		return (-1);

	/* open file in append mode (do NOT create it) */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	/* if text_content is NULL, do nothing */
	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	/* calculate length */
	while (text_content[len])
		len++;

	/* write to file */
	w = write(fd, text_content, len);
	if (w == -1 || w != len)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
