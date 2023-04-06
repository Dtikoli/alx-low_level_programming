#include "main.h"

/**
 * create_file - creates a read/write user access file
 * @filename: name of file to create
 * @text_content: null terminated string to write to file
 * Return: 1 on success, -1 on error
 */
int create_file(const char *filename, char *text_content)
{
	int fd, len, w_count;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);

	if (fd == -1)
		return (-1);

	if (text_content)
	{
		for (len = 0; text_content[len]; len++)
			;
		w_count = write(fd, text_content, len);

		if (w_count == -1)
			return (-1);
	}

	close(fd);

	return (1);
}
