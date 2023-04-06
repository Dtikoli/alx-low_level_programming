#include "main.h"
#define MAXBUFF 1024

/**
 * _exit_status - exit program with an exit value and print error messages
 * @error: number of either exit value or file descriptor
 * @str: either of the two filenames, str
 * @fd: file descriptor
 * Return: 0 on success
 **/
int _exit_status(int error, char *str, int fd)
{
	switch (error)
	{
	case 97:
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(error);
	case 98:
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", str);
		exit(error);
	case 99:
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", str);
		exit(error);
	case 100:
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(error);
	default:
		return (0);
	}
}

/**
 * main - copies the content of one file to another file
 * @argc: number of CL arguments passed
 * @argv: aaray of strings from the command line
 * Return: 0 (success), 97-100 (exit value errors)
 */
int main(int argc, char *argv[])
{
	int in_fd, out_fd;
	int r_count, w_count;
	char *buffer[MAXBUFF];

	if (argc != 3)
		_exit_status(97, NULL, 0);

	/*set file descriptor of destination file*/
	in_fd = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (in_fd == -1)
		_exit_status(99, argv[2], 0);

	/*set file descriptor for source file*/
	out_fd = open(argv[1], O_RDONLY);
	if (out_fd == -1)
		_exit_status(98, argv[1], 0);

	/* reads contents of source file to the end */
	/* writes contents of source file to destination file */
	do {
		r_count = read(out_fd, buffer, MAXBUFF);
		if (r_count == -1)
			_exit_status(98, argv[1], 0);

		w_count = write(in_fd, buffer, r_count);
		if (w_count == -1)
			_exit_status(99, argv[2], 0);

	} while (r_count > 0);

	close(in_fd) == -1 ? (_exit_status(100, NULL, in_fd)) : close(in_fd);
	close(out_fd) == -1 ? (_exit_status(100, NULL, out_fd)) : close(out_fd);

	return (0);
}

