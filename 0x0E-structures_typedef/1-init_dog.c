#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - initializes a variable of type struct dog
 * @d: pointer to struct dog to initialize
 * @name: name to initialize
 * @age: age to initialize
 * @owner: owner to initialize
 *
 * Description: This function takes a pointer to a struct dog, along with
 * the necessary information (name, age, owner), and initializes the dog
 * structure with the provided values. If the pointer is NULL, it allocates
 * memory for a new struct dog and initializes it.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
	{
		d = malloc(sizeof(struct dog));
		if (d == NULL)
		{
			/* Handle memory allocation failure */
			return;
		}
	}

	d->name = name;
	d->age = age;
	d->owner = owner;
}
