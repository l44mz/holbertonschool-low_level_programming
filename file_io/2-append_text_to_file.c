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
	int fd, i = 0, written;

	if (filename == NULL)
		return (-1);

	/* Open file in write + append mode (DO NOT create) */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	/* If text_content exists, compute length and write */
	if (text_content != NULL)
	{
		while (text_content[i])
			i++;

		written = write(fd, text_content, i);
		if (written == -1 || written != i)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
