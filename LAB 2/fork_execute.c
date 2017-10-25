#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <stdlib.h>
#include <unistd.h>

int main()
{

	int pid,status;

 	pid = fork(); //creates a child process
 	if(pid > 0) //if its a parent process
 	{
 		pid = wait(&status); //waits for child processes to terminate and returns id of the dead child
 	}

 	else //its a child process or pid=0
 	{
		execlp("ls","",NULL); //same as writing ls in terminal - lists content of directory
		exit(0);
 	}
}

