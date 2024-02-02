#include <stdio.h>

void execute_before_main(void) __attribute__ ((constructor));

/**
 * execute_before_main - Prints a message before the main function is executed
 *
 * This function is attributed with the constructor attribute, which ensures
 * that it is executed automatically before the main function during program
 * startup. It prints a couple of lines to the standard output.
 */
void execute_before_main(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
