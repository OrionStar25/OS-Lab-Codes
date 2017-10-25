#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int frv,pid,status;

	frv = fork(); //create a child process
 	if(frv > 0) //parent process
 	{
  		printf("I am in the parent, my process id  = %d, my parent's process id = %d, the child's process id  = %d and return value of the fork  = %d\n",getpid(),getppid(),frv,frv);
  		pid = wait(&status);
		printf("I am in the parent after the child exited and the exited child's process id  = %d \n ",pid );
	}
	else //child process
	{
		printf("I am in the child, my process id  = %d,  and my parents's process id = %d and return value of the fork  = %d\n",getpid(),getppid(),frv);
		exit(0);
	}
}

