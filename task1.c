#include "shell.h"

#define BUFFER_SIZE 1035
#define PATH_SIZE 1030

/**
 * main - terminal
 * Descreption: program c UNIX command line interpreter
 * execute- this funtcio, executes commands
 * @command: command passed
 * @prompt: name user
 * Return: Always return 0
 */

void execute(const char *command)
{
	char path[PATH_SIZE];
	snprintf(path, sizeof(path), "/bin/%s", command);
	char *args[] = {command, NULL};
	execve(path, args, NULL);
	perror("execve");
	exit(EXIT_FAILURE);
}

int main(void)
{
	char command[BUFFER_SIZE];
	char prompt[] = "$ ";

	while (1)
	{
		printf("%s", prompt);

		if (fgets(command, sizeof(command), stdin) == NULL)
			break;

		command[strcspn(command, "\n")] = '\0';

		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
			execute(command);
		else
		{
			int status;
			waitpid(pid, &status, 0);

			if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
				fprintf(stderr, "Command not found: %s\n", command);
		}
	}
	return 0;
}
