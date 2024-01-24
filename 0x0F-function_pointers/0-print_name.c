#include "function_pointers.h"
#include <stdio.h>
/**
 * print_name - print name to function
 * @name: arg 1 string
 * @f: arg 2 pointer to func
 * Return: 0 always
 **/
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;


	f(name);
}

