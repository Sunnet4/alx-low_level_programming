#include "main.h"

/**
 * read_textfile - reads a text file so prints it to the POSIX standard output
 * @filename: type is char filename
 * @letters: type is size_t letters
 * Return: if write fails or does not write the expected amount of bytes,
 * return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{

	int fd;
	ssize_t rd, wr;
	char *buffer;

	if (filename == NULL)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (0);
	}
	rd = read(fd, buffer, letters);
	if (rd == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}
	close(fd);
	wr = write(STDOUT_FILENO, buffer, rd);
	if (wr == -1)
	{
		free(buffer);
		return (0);
	}
	if (wr != rd)
		return (0);
	return (rd);

}
