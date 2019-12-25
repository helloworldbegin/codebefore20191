#include <stdio.h>

typedef enum bool
{
	False,
	True
}BOOL;
typedef struct prime
{
	unsigned int number;
	struct prime * ptr;
}PRIME;
BOOL isPrime(unsigned int n)
{
	for(int i = 2; i < n; i++)
	{
		if(n % i == 0)
		{
			return False;
		}
	}
	return True;
}
int main(void)
{
	int i = 0;
	printf("Input: ");
	scanf("%u", &i);
	while(i <= 0)
	{
		scanf("%u", &i);
	}
	PRIME * head, *p;
	p = (PRIME*)malloc(sizeof(PRIME));
	head = p;
	for(int j = 1; j<= i; j++)
	{
		if(isPrime(j))
		{
			(*p).number = j;
			(*p).ptr = (PRIME*)malloc(sizeof(PRIME));
			p = (*p).ptr;
		}
	}
	(*p).ptr = NULL;
	p = head;
	while((*p).ptr != NULL)
	{
		printf("%d\n", (*p).number);
		p = (*p).ptr;
	}
	p = head;
	i = 1;
	while(p != NULL)
	{
		head = (*p).ptr;
		printf("%u ", (*p).number);
		free(p);
		printf("Free %d\n", i);
		i+=1;
		p = head;
	}
	return 0;
}
