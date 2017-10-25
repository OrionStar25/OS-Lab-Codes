#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    int i;
    int a=3;
    int pid ;
    printf("%p\n",&a);

    for(i=0;i<3;i++)
    {
        pid = fork();
        if(pid == 0)
            a++;
        else
            a+=2;
        
        printf("%d and %p and %d\n",getpid(),(void *)&a,a);
    }
    return 0;
}


