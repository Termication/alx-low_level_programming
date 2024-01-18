#include "main.h"
#include <stdlib.h>
/**
 * malloc_checked - function to allocate the memory
 *
 * @b: arg inpt integer
 * Return: the function
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	if(ptr == NULL)
	{
		exit(98);
	}
	return (ptr);
}
