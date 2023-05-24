#include "shell.h"


/**
 * obj_in_lst - a program that execute object
 * @nick: a pointer to struct
 *
 * Return: Return a function value,otherwise returns -1.
 **/
int obj_in_lst(_st *nick)
{
	int iterator;
	objects options[] = {
		{"exit", ob_in_ext},
		{"help", ob_in_hlp},
		{"cd", ob_in_cd},
		{"alias", ob_in_alias},
		{"env", ob_in_env},
		{"setenv", ob_set_env},
		{"unsetenv", ob_in_unset_env},
		{NULL, NULL}
	};

	/*the structure*/

	for (iterator = 0; options[iterator].builtin != NULL; iterator++)
	{
		if (str_compare(options[iterator].builtin, nick->c, 0))
		{
			/* execute a function */
			return (options[iterator].function(nick));
		}
	}
	return (-1);
}
