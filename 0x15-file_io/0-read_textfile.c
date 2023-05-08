#include "main.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - reads a text file then  prints it to POSIX standard output
 * @filename: name of the file to be read
 * @letters: number of letters to be  read and printed
 *
 * Return: actual number of letters it could read and print
 * if the file can not be opened or read, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int ft;
	ssize_t lenrd, lenwr;
	char *buff;

	if (filename == NULL)
		return (0);
	ft = open(filename, O_RDONLY);
	if (ft == -1)
		return (0);
	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
	{
		close(ft);
		return (0);
	}
	lenrd = read(ft, buff, letters);
	close(ft);
	if (lenrd == -1)
	{
		free(buff);
		return (0);
	}
	lenwr = write(STDOUT_FILENO, buff, lenrd);
	free(buff);
	if (lenrd != lenwr)
		return (0);
	return (lenwr);
}
