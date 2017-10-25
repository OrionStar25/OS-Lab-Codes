// C program to implement writer side of FIFO
#include <stdio.h>
#include <string.h>
#include <fcntl.h> //file handling
#include <sys/stat.h> //for myfifo()
#include <sys/types.h>
#include <unistd.h> //for nulls
 
int main()
{
    int fd[2];
 
    // FIFO file path
    char * myfifo = "/tmp/mypipe";
 
    // Creating the named file(FIFO) mkfifo(<pathname>, <permission>)
    mkfifo(myfifo, 0666);
    printf("Opening named pipe: /tmp/mypipe\n");
 
    char arr1[80];
    while (1)
    {
        // Open FIFO for write only
        fd[1] = open(myfifo, O_WRONLY);
 
        // Take an input arr1 string from user.
        // 80 is maximum length
	printf("Enter Input: ");
        fgets(arr1, 80, stdin);
 
        // Write the input arr1 stringing on FIFO
        // and close it
	printf("\nWriting buffer to pipe...done\n");
        write(fd[1], arr1, strlen(arr1)+1);

	if(strcmp(arr1,"exit")==10)
	{
		printf("Exiting\n");
		break;
	}
        close(fd[1]);
    }
    return 0;
}
