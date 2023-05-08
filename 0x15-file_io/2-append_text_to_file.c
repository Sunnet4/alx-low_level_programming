#include "main.h"

/**
 * append_text_to_file - add text at end of a file
 * @filename: the filename.
 * @text_content: to added content.
 *
 * Return: 1 if the file exists. -1 if the fails does not exist
 * or if it a failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int ft;
	int mletters;
	int rwt;

	if (!filename)
		return (-1);

	ft = open(filename, O_WRONLY | O_APPEND);

	if (ft == -1)
		return (-1);

	if (text_content)
	{
		for (mletters = 0; text_content[mletters]; mletters++)
			;

		rwt = write(ft, text_content, mletters);

		if (rwt == -1)
			return (-1);
	}

	close(ft);

	return (1);
}
