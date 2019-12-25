#include <stdio.h>
#include <stdlib.h>
int array[100] = { 0 };
void rand_initial(int a[], int n);
int main()
{
    rand_initial(array, 100);
    int i = 10;
    for (i = 0; i < 100; i = i + 1)
	printf("%d ", array[i]);
    printf("\n");
    return 0;
}
void rand_initial(int a[], int n)
{
//    unsigned int seed = 123;
//    int temp;
//    printf("input num: ");
//    scanf("%u", &seed);
//    printf("srandnext");
//    srand(seed);
    a[0] = rand() % 100;
    for (int i = 1; i < n; i = i+ 1)
    {
	a[i] = rand() % 100;
	while (1)
	{
	    int max = 0;
	    for ( int j = 0; j < i; j = j + 1)
	    {
		if (a[i] == a[j])
		{
		    a[i] = rand() % 100;
		    break;
		}
		else
		{
		    max = j;
		}
	    }
	    if (max == i - 1)
	    {
		printf("xxxxx");
		break;
	    }
	}
    }
}
