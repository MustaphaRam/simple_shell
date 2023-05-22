#include "shell.h"

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

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
	char *arguments[MAX_ARGUMENTS];
	pid_t child_pid;
	int status;

	/* Tokenize command into arguments */
	char *token;
	int arg_count = 0;

	while (1)
	{
		printf("$ ");

		/* Read command from user */
		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			/* Handle end of file (Ctrl+D) */
			printf("\n");
			break;
		}

		/* Remove trailing newline character */
		command[strcspn(command, "\n")] = '\0';

		token = strtok(command, " ");
		while (token != NULL && arg_count < MAX_ARGUMENTS - 1) 
		{
			arguments[arg_count] = token;
			arg_count++;
			token = strtok(NULL, " ");
		}
		arguments[arg_count] = NULL;

		/* Fork a child process */
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
			execvp(arguments[0], arguments);
			/* If the command is not found, the following line will be executed */
			fprintf(stderr, "Error: Command not found: %s\n", arguments[0]);
			exit(EXIT_FAILURE);
		}
		else
		{
			/* Parent process */
			/* Wait for the child process to complete */
			waitpid(child_pid, &status, 0);
		}
	}
	return 0;
}
