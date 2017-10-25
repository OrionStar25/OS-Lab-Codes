// C program to implement one side of FIFO
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
 
int main()
{
    int fd[2];
 
    // FIFO file path
    char * myfifo = "/tmp/mypipe";
 
    // Creating the named file(FIFO)
    // mkfifo(<pathname>,<permission>)
    mkfifo(myfifo, 0666);
    printf("Creating a named pipe: /tmp/mypipe\n");
 
    char str1[80];
    while (1)
    {
        // First open in read only and read
        fd[0] = open(myfifo,O_RDONLY);
	printf("Waiting for input.... Got it!\n");
        read(fd[0], str1, 80);
 
        // Print the read string and close
        printf("User1: %s\n", str1);

	if(strcmp(str1,"exit")==10)
        {
		printf("Exiting\n");
		break; 
	}
        close(fd[0]);
    }

    return 0;
}
