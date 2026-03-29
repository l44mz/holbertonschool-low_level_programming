#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>

/**
 * struct dog - structure for a dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

int _putchar(char c);
void init_dog(struct dog *d, char *name, float age, char *owner);

#endif /* MAIN_H */
