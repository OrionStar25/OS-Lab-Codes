#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	int pid;
	char op1, op2;
	char sign;
	int status;

// printf(“>”);
	scanf(“%c%c%c”, &op1, &sign, &op2);

	pid = fork();

	if (pid == 0)
	{
		if (execl(“server”, &op1, &op2, &sign, NULL)<0)
			perror(“error”);
	}
	else if (pid>0)
	{
		waitpid(pid, &status, 0);
		printf(“result %d\n”, WEXITSTATUS(status));
	}

	exit(0);
}
