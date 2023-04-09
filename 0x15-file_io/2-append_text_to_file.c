#include "main.h"

/**
 * append_text_to_file -  function that appends text
 * at the end of a file.
 * @filename: name of file to have text appended to
 * @text_content: the NULL terminated string to add
 * at the end of the file
 * Return: 1 on success and -1 on failure
 * If text_content is NULL, do not add anything to the file.
 *  Return 1 if the file exists and -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file;
	int result_out;
	int a;

	file = open(filename, O_RDWR | O_APPEND);
	if (filename == NULL)
		return (-1);
	if (file == -1)
	return (-1);
	if (text_content == NULL)
		return (1);
	while (*(text_content + a) != '\0')
		a++;
	result_out = write(file, text_content, a);
	if (result_out == -1)
		return (-1);
	return (1);
}
