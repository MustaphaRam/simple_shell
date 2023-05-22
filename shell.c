#include "shell.h"

/**
 * main: UNIX command line interpreter
 * description: simple_shell
 * @command: command passed
 * Return: Always return 0
*/

int main(void)
{
	char command[BUFFER_SIZE];
	char prompt[];
	int status;
	char path[PATH_SIZE];

	prompt[] = "simple_shell> "

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
		{
			snprintf(path, sizeof(path), "/bin/%s", command);

			char *args[];

			*args[] = {command, NULL};
			execve(path, args, NULL);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
				fprintf(stderr, "Command not found: %s\n", command);
		}
	}
	return 0;
}
