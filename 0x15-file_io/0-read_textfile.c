#include "main.h"

/**
 * read_textfile - reads a text file and printsit to standard output
 * @filename: name of file.
 * @letters: numbers of letters to be read and printed.
 * Return: actual number of letters read and printed. If fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t r_count, w_count;
	char *buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	r_count = read(fd, buffer, letters);
	w_count = write(STDOUT_FILENO, buffer, r_count);

	if (w_count != r_count || w_count == -1)
		return (0);

	close(fd);

	free(buffer);

	return (w_count);
}

