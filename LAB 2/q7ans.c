#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	fp = fopen("text.txt","r");
	int count = 0;
        
    while(1)
	{
		char c = fgetc(fp);
		if( c == EOF )
			break;
		count++;
	}
	printf("count is %d\n",count);
    fclose(fp);
    return 0;
}
