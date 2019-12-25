#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node * ptr;
} NODE;

int main(void)
{
	NODE * head, *p;

	p = (NODE*)malloc(sizeof(NODE));
	head = p;

	p -> data = 0;

	while(p -> data != -1)
	{
		p -> ptr = (NODE*)malloc(sizeof(NODE));
		p = p -> ptr;
		printf("Input number: ");
		scanf("%d", &(p -> data));
	}
	p -> ptr = NULL;

	p = head -> ptr;

	while (p -> ptr != NULL)
	{
		printf("%d,", p -> data);
		p = p -> ptr;
		printf("\n");
	}

	p = head -> ptr;
	NODE * q = p;
	int i = 0;
	while(head -> ptr != NULL)
	{
		free(head);
		i += 1;
//		printf("The %d ", i);
		head = p;
		p = p -> ptr;
	}
//	printf("data is %d", head -> data);
	free(head);
/*	printf("---");
	head -> data = 100;
	printf("data is %d ptr is %p", head -> data, (*head).ptr);
	q -> data = 500;
	printf("q.data is %d", q -> data);
	*/
	return 0;
}
