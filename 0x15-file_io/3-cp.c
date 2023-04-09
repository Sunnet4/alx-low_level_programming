#include "main.h"
#define BUFFER_SIZE 1024

/**
 * end_func - function that treats with
 * all standard errors
 * @num: exit status number or the file descriptor
 * @str: file name is either to_file or
 * from_file, or NULL
 * Return: 97, 98, 99, or 100 based on the
 * input number
 */
int end_func(int num, char *str)
{
	int value_f;

	switch (num)
	{
	case 97:
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		value_f = 97;
		break;
	case 98:
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", str);
		value_f = 98;
		break;
	case 99:
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", str);
		value_f = 99;
		break;
	default:
		dprintf(STDERR_FILENO, "Error: Can't close fd %d", num);
		value_f = 100;
		break;
	}
	return (value_f);
}
/**
 * main - copies the content of a file to another file
 * @argc: take arguments count
 * @argv: use pointer to list of the argument strings
 * Return: 0 success for, 97, 98, 99, or 100 on failure
 */
int main(int argc, char **argv)
{
	int fd_to, fd_from, read_value;
	char *file_from, *file_to, buffer[BUFLEN];

	if (argc != 3)
		exit(end_func(97, NULL));
	file_from = argv[1], file_to = argv[2];
	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		exit(end_func(98, file_from));
	fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
		exit(close(fd_from) == -1 ? end_func(fd_from, NULL) :
			 end_func(99, file_to));
	read_value = read(fd_from, &buffer, BUFLEN);
	while (read_value)
	{
		if (read_value == -1)
			exit(close(fd_from) == -1 ? end_func(fd_from, NULL) :
				 close(fd_to) == -1 ? end_func(fd_to, NULL) :
				 end_func(98, file_from));
		if (write(fd_to, &buffer, read_value) == -1)
			exit(end_func(99, file_to));
		read_value = read(fd_from, &buffer, BUFLEN);
	}
	return (close(fd_from) == -1 ? end_func(fd_from, NULL) :
			close(fd_to) == -1 ? end_func(fd_to, NULL) : 0);
}
