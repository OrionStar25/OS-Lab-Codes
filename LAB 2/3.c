#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	int pid,status;

	pid = fork(); //creates a child process

	if(pid == 0)
	{
		printf("Child process taking place\n");
		printf("PID : %d, PPID: %d\n",getpid(),getppid());
	}
	else
	{
		pid = wait(&status);
		printf("Child process is done\n");
		printf("PID : %d, return value of fork : %d\n",getpid(),pid);
	}	

	printf("Status :%d\n",status);

	return 0;
}