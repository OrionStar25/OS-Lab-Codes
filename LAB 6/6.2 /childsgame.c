#include<stdio.h>
#include<stdlib.h> //for exit
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include <time.h>

#define BUFSIZE 10
//assume MAX=1
//assume MIN=0


int main()
{
	int fd1[2],fd2[2]; //2 pipes for P-C,P-D
	int pidC,pidD; //2 ids for child processes
	char number1[10], number2[10];

	/* Intializes random number generator */
    srand((unsigned) time(0));

	if(pipe(fd1)==-1) //create pipe between P-C
	{	
		printf("Error in creating pipe between P-C\n");
		exit(0);
	}
	if(pipe(fd2)==-1) //create pipe between P-D
	{	
		printf("Error in creating pipe between P-D\n");
		exit(0);
	}

	if((pidC=fork())==0) //Child C is active
	{
		srand(pidC);		
		
		close(fd2[0]); //close pipe 2's read
		close(fd2[1]); //close pipe 2's write
		close(fd1[0]); //close pipe 1's read;

		while(1)
     	{	                   
         int c=rand()%100; //generate a random number between 0- 99		            
         
         sprintf(number1, "%d", c);	     
         write(fd1[1], number1, BUFSIZE);   
         sleep(1);
        }

		printf("Child C is exiting\n");
	}
	else
	if((pidD=fork())==0) //Child D is active
	{
		close(fd1[0]); //close pipe 1's read
		close(fd1[1]); //close pipe 1's write
		close(fd2[0]); //close pipe 2's read;

		while(1)
     	{	                   
         int d=rand()%100; //generate a random number between 0- 99		            
         
         sprintf(number1, "%d", d);	     
         write(fd2[1], number1, BUFSIZE);   
         sleep(1);
        }
		
		printf("Child D is exiting\n");
	}
	else //parent is active
	{
		int scoreC,scoreD,flag,round;
		scoreC=scoreD=0;
		round=0;

		while(scoreC!=10 && scoreD!=10) //iterate for each round
		{
			int check=0;
			flag=rand()%2; //choose a number between 0 and 1
		
			read(fd1[0], number1, BUFSIZE); //read from P-C pipe
        	int c = atoi(number1); //convert string to integer
			printf("C chose %d\n",c);
         	read(fd2[0], number2, BUFSIZE); //read from P-D pipe
         	int d = atoi(number2); //convert string to integer
			printf("D chose %d\n",d);

			if(flag==0) //flag chosen is MIN
			{
				printf("P chose MIN flag\n");
				if(c<d)
				{
					scoreC++;
					printf("C got a point!\n");
					check=1;
				}
				else if(d<c)
				{
					scoreD++;
					printf("D got a point!\n");
					check=1;
				}
			}
			else if(flag==1) //flag chosen is MAX
			{
				printf("P chose MAX flag\n");
				if(c>d)
				{
					scoreC++;
					printf("C got a point!\n");
					check=1;
				}
				else if(d>c)
				{
					scoreD++;
					printf("D got a point!\n");
					check=1;
				}
			}
			if(check==1)
			{
				round++;
			}	
			printf("Round :%d, Score_C = %d, Score_D = %d \n",round,scoreC,scoreD);
		
		}

		if(scoreC==10)
		{
			printf("C won!\n");	
		}
		else
		{
			printf("D won!\n");
		}
	
		printf("parent exiting\n");		
	}
	
	return 0;
}
