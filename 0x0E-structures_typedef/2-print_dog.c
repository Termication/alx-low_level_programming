#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * print_dog - prints a struct dog
 * @d: struct dog to print
 *
 * Description: This function prints the information contained in a struct dog.
 * If the pointer to the struct is NULL, the function returns without printing.
 * The function also checks if name or owner is NULL and substitutes "(nil)" in
 * such cases to ensure a more informative output.
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	if (d->name == NULL)
		d->name = "(nil)";
	if (d->owner == NULL)
		d->owner = "(nil)";

	printf("Name: %s\nAge: %f\nOwner: %s\n", d->name, d->age, d->owner);
}

