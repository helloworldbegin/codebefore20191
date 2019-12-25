#include <stdio.h>
#include <stdlib.h>

FILE * fp;

int main(int count, char * fname[])
{
	//char fname[50];
	//scanf("%s", fname);
	//printf("%s", fname);
	printf("number is %d\n", count);
	if((fp = fopen(fname[1], "rb")) == NULL)
	{
		printf("Open file fail");
		exit(0);
	}
	int ch;
	ch = fgetc(fp);
	while(ch != EOF)
	{
		printf("%c", ch);
		ch = fgetc(fp);
	}
	//fputc(ch, fp);
	fclose(fp);
	return 0;
}
