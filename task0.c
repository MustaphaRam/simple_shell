#include "shell.h"

#define MAX_COMMAND_LENGTH 100

/**
 * main - command interpreter
 * Description: display a promnt
 *
 * Return: Always 0 (Success)
 *
**/

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	pid_t child_pid;
	int status;

	while (1)
	{
		printf("$ ");
		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		child_pid = fork();

		if (child_pid < 0)
		{
			fprintf(stderr, "Error: Fork failed\n");
			exit(EXIT_FAILURE);
		}

		else if (child_pid == 0)
		{
			execlp(command, command, NULL);
			fprintf(stderr, "No such file or directory\n");
			exit(EXIT_FAILURE);
		}
		else
			waitpid(child_pid, &status, 0);
	}
	return (0);
}
