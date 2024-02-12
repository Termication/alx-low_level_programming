#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * allocate_buffer - Allocates memory for a file read buffer.
 * @filename: The name of the file associated with the buffer.
 *
 * Return: Pointer to the allocated buffer, or NULL on failure.
 */
char *allocate_buffer(char *filename)
{
	char *buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't allocate memory for buffer (%s)\n",
				filename);
		exit(99);
	}
	return (buffer);
}

/**
 * close_fd - Safely closes a file descriptor.
 * @file_descriptor: The file descriptor to close.
 */
void close_fd(int file_descriptor)
{
	if (close(file_descriptor) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_descriptor);
		exit(100);
	}
}

/**
 * main - Copies the contents of one file to another.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, bytes_read, bytes_written;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buffer = allocate_buffer(argv[2]);

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		exit(98);
	}
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		free(buffer);
		close_fd(file_from);
		exit(99);
	}
	do {
		bytes_read = read(file_from, buffer, 1024);
		if (bytes_read == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			close_fd(file_from);
			close_fd(file_to);
			exit(98);
		}
		bytes_written = write(file_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			close_fd(file_from);
			close_fd(file_to);
			exit(99);
		}
	} while (bytes_read > 0);
	free(buffer);
	close_fd(file_from);
	close_fd(file_to);

	return (0);
}
