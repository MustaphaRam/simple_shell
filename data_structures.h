#ifndef STRUCTURES_H
#define STRUCTURES_H

/**
 * file - struct info- struct for the program's data
 * description : struct file programe data
 * @a: the name of the executable
 * @b: pointer to the input read for _getline
 * @c: pointer to the first command typed by the user
 * @d: number of excecuted comands
 * @e: file descriptor to the input of commands
 * @f: pointer to array of tokenized input
 * @g: copy of the environ
 * @h: array of pointers with aliases.
 */
typedef struct file
{
	char *a;
	char *b;
	char *c;
	int d;
	int e;
	char **f;
	char **env;
	char **h;
} _st;

/**
 * struct objects - struct for the objects
 * @builtin: the name of the object
 * @function: the associated function to be called for each object
 */
typedef struct objects
{
	char *object;
	int (*function)(_st *nick);
} objects;

#endif /* STRUCTURES */
