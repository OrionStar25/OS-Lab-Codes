/* ----------------------------------------------------------------- */
/* PROGRAM fork-02.c                                                 */
/*   This program runs two processes, a parent and a child.  Both of */
/* them run the same loop printing some messages.  Note that printf()*/
/* is used in this program.                                          */
/* ----------------------------------------------------------------- */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define   MAX_COUNT  100

void  ChildProcess();                /* child process prototype  */
void  ParentProcess();               /* parent process prototype */

void  main()
{
     pid_t  pid;

     pid = fork(); //creates a child process
     if (pid == 0) 
          ChildProcess();
     else 
          ParentProcess();
}

void  ChildProcess()
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++)
          printf("   This line is from child, value = %d\n", i);
     printf("   *** Child process is done ***\n");
}

void  ParentProcess(void)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++)
          printf("This line is from parent, value = %d\n", i);
     printf("*** Parent is done ***\n");
}
