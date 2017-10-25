#include <sys/types.h>
// #include <sys/stat.h>
#include <stdlib.h>
// #include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main( int argc, char **argv)
{
int a;
int b;
int res=0;

a = *argv[0] – 48;
b = *argv[1] – 48;

printf (“\n %d %d “, a, b );

if ( *argv[2] == ‘+’)
	res = a+b;
else res = a-b;

return res;
}
