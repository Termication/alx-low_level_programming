#include "main.h"

/**
 * append_text_to_file - Appends text to the end of an existing file.
 * @filename: The name (or path) of the file to modify.
 * @text_content: The text to be appended to the file.
 *
 * Return: 1 on success, -1 on failur
 *         (including if the file doesn't exist or lacks write permissions).
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor;
	ssize_t bytes_written;
	int content_length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[content_length] != '\0')
			content_length++;
	}

	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	if (file_descriptor == -1)
		return (-1);

	bytes_written = write(file_descriptor, text_content, content_length);
	if (bytes_written == -1)
	{
		close(file_descriptor);
		return (-1);
	}

	close(file_descriptor);
	return (1);
}
