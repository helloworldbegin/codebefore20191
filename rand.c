#include <stdio.h>
#include <stdlib.h>
int main()
{
    unsigned int seed = 0;
    scanf("%u", &seed);
    srand(seed);
    int i;
    for (i = 0; i < 111; i= i + 1)
    {
	int a = rand();
	printf("%i\n", a % 101);
    }
    return 0;
}
