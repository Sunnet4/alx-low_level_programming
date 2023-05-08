#include "main.h"

/**
 * create_file - to create a file
 * @filename: the filename.
 * @text_content: content wrote in the file.
 *
 * Return: 1 if it success. -1 if it failure.
 */
int create_file(const char *filename, char *text_content)
{
	int ft;
	int mletters;
	int rwt;

	if (!filename)
		return (-1);

	ft = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (ft == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (mletters = 0; text_content[mletters]; mletters++)
		;

	rwt = write(ft, text_content, mletters);

	if (rwt == -1)
		return (-1);

	close(ft);

	return (1);
}
