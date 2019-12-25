#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node * ptr;
}NODE;

NODE * createlink(int n)
{
	NODE *p, *head;
	p = (NODE*)malloc(sizeof(NODE));
	head = p;
	for(int i = 1; i < n; i++)
	{
		(*p).ptr = (NODE*)malloc(sizeof(NODE));
		p = (*p).ptr;
	}
	(*p).ptr = NULL;
	return head;
}
void deletelink(NODE* head)
{
	NODE *p = NULL;
	int i = 0;
	while((*head).ptr != NULL)
	{
		p = (*head).ptr;
		free(head);
		i = i + 1;
		printf("Free %d\n", i);
		head = p;
	}
	free(head);
	i = i + 1;
	printf("Free %d\n", i);
}
int main(void)
{
	NODE * head, *p;
	int n = 0;
	printf("Input number: ");
	scanf("%d", &n);
	head = createlink(n);
	p = head;
	int i = 0;
	while((*p).ptr != NULL)
	{
		i++;
		printf("%d, p %p, (*p).ptr %p\n", i, p, (*p).ptr);
	//	printf("is %d, is %p, is %p\n", i, p, (*p).ptr);
		p = (*p).ptr;
	}
	i++;
	printf("%d, p %p, (*p).ptr %p\n", i, p, (*p).ptr);
	//printf("This is %d, address is %p\n", i, (*p).ptr);
	deletelink(head);
	return 0;
}
