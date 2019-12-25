#include <stdio.h>
int main(int argc, char * argv[], char * envp[])
{
	for (int i = 0; envp[i] != NULL; i+=1)
	{
		printf("%s\n", envp[i]);
	}
	return 0;
}
