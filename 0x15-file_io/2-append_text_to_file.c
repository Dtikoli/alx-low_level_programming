#include "main.h"

/**
 * append_text_to_file - Appends a text at the end of a file
 * @filename: name of file
 * @text_content: null terminated string to add to end of file
 * Return: 1 on success, -1 on error
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, len, w_count;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_APPEND | O_WRONLY);
	
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

