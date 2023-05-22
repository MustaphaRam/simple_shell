#include "shell.h"

#define MAX_COMMAND_LENGTH 100

/**
 * executeCommand - execute command
 * Description: get command user
 * @command: user command
 * Return: Nothing
 *
**/

void executeCommand(char *command)
{
	pid_t child_pid;
	int status;

	/* Frok a child process */
	child_pid = fork();

	if (child_pid < 0)
	{
		/* Forking failed */
		fprintf(stderr, "Error: Fork failed\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		/* Child process */
		if (execlp(command, command, NULL) == -1)
		{
			/*  If the command is not found, the following line will be executed */
			fprintf(stderr, "Error: Command not found: %s\n", command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		/* Wait for the child process to complete */
		waitpid(child_pid, &status, 0);
	}
}

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

	while (1)
	{
		printf("$ ");

		/* Read command from user */
		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			/* Handle end of file(Ctrl+D)*/
			printf("\n");
			break;
		}

		/* Remove trailing newline character */
		command[strcspn(command, "\n")] = '\0';

		/* Fork a child process */
		executeCommand(command);
	}
	return (0);
}
