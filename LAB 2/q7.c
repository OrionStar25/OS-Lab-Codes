#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    FILE *file1;
    file1 = fopen("text.txt","w"); 
	int i,pid;

	for(i = 1 ;i<=10;i++)
	{
		pid = fork();
		printf("%d id PID\n",pid);
	}

	fprintf(file1,"%s","1");
	fclose(file1);
	
	return 0;
}
		

