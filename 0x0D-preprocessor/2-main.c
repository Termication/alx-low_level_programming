#include <stdio.h>

/**
 * main - Betty-style function to print the name of the file
 *
 * Description:
 *     This main function adheres to the Betty coding style. It prints
 *     the name of the file using the predefined macro __FILE__.
 *
 * Return:
 *     Always 0 (Success)
 */
int main(void)
{
	printf("%s\n", __FILE__);
	return (0);
}
