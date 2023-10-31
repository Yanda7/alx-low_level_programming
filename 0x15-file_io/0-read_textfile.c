#include "main.h"

/**
 * read_textfile - read a text file and print it to stdout
 * @filename: the name of the file to read
 * @letters: the number of letters to be read and printed
 *
 * Return: If filename is NULL, the file cannot be opened or read, or
 * write fails or returns an unexpected number of bytes, return 0.
 * Otherwise, return the actual number of letters read and printed.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer = NULL;
	ssize_t r_read;
	ssize_t w_written;
	int fdx;

	if (!(filename && letters))
		return (0);

	fdx = open(filename, O_RDONLY);
	if (fdx == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
		return (0);

	r_read = read(fdx, buffer, letters);
	close(fd);

	if (r_read < 0)
	{
		free(buffer);
		return (0);
	}
	if (!r_read)
		r_read = letters;

	w_written = write(STDOUT_FILENO, buffer, r_read);
	free(buffer);

	if (w_written < 0)
		return (0);

	return (w_written);
}
