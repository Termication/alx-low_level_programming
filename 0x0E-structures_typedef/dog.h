#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a dog's basic info
 * @name: First member
 * @age: Second member
 * @owner: Third member
 *
 * Description: Defines a struct named 'dog' representing basic information
 *              about a dog, including its name, age, and owner.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * dog_t - typedef for struct dog
 */
typedef struct dog dog_t;

/**
 * init_dog - initializes a dog structure
 * @d: Pointer to a struct dog
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 */
void init_dog(struct dog *d, char *name, float age, char *owner);

/**
 * print_dog - prints information about a dog
 * @d: Pointer to a struct dog
 */
void print_dog(struct dog *d);

/**
 * new_dog - creates a new dog structure and initializes it
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 * Return: Pointer to the newly created dog structure
 */
dog_t *new_dog(char *name, float age, char *owner);

/**
 * free_dog - frees memory allocated for a dog structure
 * @d: Pointer to a struct dog
 */
void free_dog(dog_t *d);

/**
 * _strcpy - copies a string
 * @dest: Destination buffer
 * @src: Source string
 * Return: Pointer to the destination buffer
 */
char *_strcpy(char *dest, char *src);

/**
 * _strlen - computes the length of a string
 * @s: Input string
 * Return: Length of the string
 */
int _strlen(char *s);

#endif
