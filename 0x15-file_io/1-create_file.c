#include "main.h"

/**
 * _strlen - compute the length of a NULL-terminated string
 * @str: the string to measure
 *
 * Return: the length of str, or -1 if str is NULL
 */
ssize_t _strlen(const char *str)
{
	ssize_t len = 0;

	if (!str)
		return (-1);

	while (*str++)
		++len;

	return (len);
}

/**
 * create_file - create a file
 * @filename: the name of the file to create
 * @text_content: the data to write to filename
 *
 * Return: Upon success, return 1. Otherwise, return -1.
 */
int create_file(const char *filename, char *text_content)
{
	ssize_t w_written = 0;
	int fdx;

	if (!filename)
		return (-1);

	fdx = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);

	if (fdx < 0)
		return (-1);

	if (text_content)
		w_written = write(fdx, text_content, _strlen(text_content));

	close(fdx);

	if (w_written < 0)
		return (-1);
	return (1);
}
