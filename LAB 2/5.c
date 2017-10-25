#include <stdio.h>
#include <unistd.h>

void parent()
{
	int pid;

	pid = fork();

	if(fork == 0)
	{
		printf("Parent's child\n");
		printf("PID : %d, PPID: %d\n",getpid(),getppid());
	}
	else
	{
		printf("Parent\n");
		printf("PID : %d, PPID: %d\n",getpid(),getppid());
	}

}

void child()
{
	int pid;

	pid = fork();

	if(fork == 0)
	{
		printf("Child's child\n");
		printf("PID : %d, PPID: %d\n",getpid(),getppid());
	}
	else
	{
		printf("Child\n");
		printf("PID : %d, PPID: %d\n",getpid(),getppid());
	}

}

int main()
{
	int pid;

	pid = fork();

	if(fork == 0)
	{
		printf("Initial child\n");
		child();
		printf("PID : %d, PPID: %d\n",getpid(),getppid());
	}
	else
	{
		printf("Initial parent\n");
		parent();
		printf("PID : %d, PPID: %d\n",getpid(),getppid());
	}

	return 0;
}