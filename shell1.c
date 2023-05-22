#include "shell.h"
#define BUFFER_SIZE 1030
#define PATH_SIZE 1030

/**
 * main: terminal
 * descreption: program c UNIX command line interpreter
 * @command: command passed
 * Return: Always return 0
 */

int main(void)
{
	char command[BUFFER_SIZE];
	char prompt[] = "simple_shell> ";

	while (1)
	{
		printf("%s", prompt);

		if (fgets(command, sizeof(command), stdin) == NULL)
			break;
		command[strcspn(command, "\n")] = '\0';

		if (fork() == 0)
		{
			char path[BUFFER_SIZE];

			snprintf(path, sizeof(path), "/bin/%s", command);
			execl(path, command, (char *)NULL);
			perror("exec");
			exit(EXIT_FAILURE);
		}
		else
			wait(NULL);
	}
	return (0);
}
