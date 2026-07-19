#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a structure for a dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Description: defines a new type struct dog with name, age and owner
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/* إضافة الـ typedef هنا */
typedef struct dog dog_t;

/* البروتوتايبات للدوال السابقة */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif
