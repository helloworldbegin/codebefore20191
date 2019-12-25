#include <stdio.h>

int main(int args, char * argv[])
{
	printf("There are %d arguments ( include appname itself ).\n", args);
	printf("App name is %s.\n", argv[0]);
	for (int i = 1; i < args; i = i + 1)
	{
		printf("The %d argument is %s.\n", i, argv[i]);
	}
	return 0;
}
