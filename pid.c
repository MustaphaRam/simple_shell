#include "shell.h"

int main()
{
	pid_t pid;
	pid= fork();

	if(pid<0)
		perror("fork faild");

	else if(pid==0)
		printf("I'am the child with pid %d, My dad is %d\n", (int) getpid(), (int) getppid());

	else
		printf("I'am the parent with pid %d\n", (int) getpid());

	return 0;
}
