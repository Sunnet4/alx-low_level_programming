#include "main.h"

/**
 * create_file - function that creates a file.
 * @filename: name of the file to create
 * @text_content: type char pointer of char
 * Return: 1 on success, -1 on failure
 * (file can not be created, file can not
 * be written, write “fails”, etc…)
 * text_content is NULL create an empty file
 */
int create_file(const char *filename, char *text_content)
{
	int result_out = 0;
	int  file = 0;
	int  x = 0;

	if (filename == NULL)
		return (-1);
	file = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (file == -1)
		return (-1);
	if (text_content != NULL)
	{
		while (*(text_content + x) != '\0')
		{
			x++;
		}
		result_out = write(file, text_content, x);
	}
	if (result_out == -1 && result_out != x)
		return (-1);
	return (1);

}
