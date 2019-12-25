#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM sizeof(array)/sizeof(int)
#define ARRAY_ELE_NUM(array_name, element_type) sizeof(array_name)/sizeof(element_type)

int array[54] = { 10, 159, 388, 9, 13, 563, 166, 223, 103, 22, 66, 77, 1, 5,};
void sw_sort( int a[], int n);
void display_array(int array[], int n);
void swap_array_element(int a[], int x, int y);
void selecrion_sort(int a[], int n);
int min_in_array(int a[], int n, int m);
void rand_initial(int a[], int n);
int search(int a[], int n, int key);

int main()
{
    rand_initial(array, ARRAY_ELE_NUM(array, int));

    for (int i = 0; i < (sizeof(array)/sizeof(int)); i = i + 1)
    {
	printf("%d ", array[i]);
    }
    printf("\n");

    selecrion_sort(array, ARRAY_ELE_NUM(array, int));
    display_array(array, NUM);
    int key = 0;
    int index;
	printf("search what: ");
	scanf("%d", &key);
    while (key != -12345)
    {
	index = search(array, ARRAY_ELE_NUM(array, int), key);
	if (index == -1)
	{
	    printf("not found\n");
	}
	else
	{
	    printf("key position : %d\n", index);
	}
	printf("search what: ");
	scanf("%d", &key);
    }

    return 0;
}
void sw_sort( int a[], int n)
{
    int temp;
    for (int i = 0; i < n; i = i + 1)
    {
	for (int j = i + 1; j < n; j = j + 1)
	{
	    if (a[i] > a[j])
	    {
		/*temp = a[i];
		a[i] = a[j];
		a[j] = temp;*/
		swap_array_element(a, i, j);
	    }
	}
    }
}
void display_array(int array[], int n)
{
    for (int i = 0; i < n; i = i + 1)
    {
	printf("%d ", array[i]);
    }
    printf("\n");
}
void swap_array_element(int a[], int x, int y)
{
    int temp;
    temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}
void selecrion_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i = i + 1)
    {
	int minimum_index = min_in_array(a, n, i);
	if (a[i] > a[minimum_index])
	{
	    swap_array_element(a, i, minimum_index);
	}
    }
}
int min_in_array(int a[], int n, int m)
{
    int min = m + 1;
    for (int i = m + 2; i < n; i = i + 1)
    {
	if (a[i] < a[min])
	{
	    min = i;
	}
    }
    return min;
}
void rand_initial(int a[], int n)
{
    unsigned int seed = 123;
    int temp;
    int equaltime = 0;
    seed = time(0);
    srand(seed);
    a[0] = 1 + rand() % 100;
    for (int i = 1; i < n; i = i+ 1)
    {
	a[i] = 1 + rand() % 100;
	for (;;)
	{
	    int max = 0;
	    for ( int j = 0; j < i; j = j + 1)
	    {
		if (a[i] == a[j])
		{
		    equaltime = equaltime + 1;
		    printf("%d: array[%d] = array[%d]=%d\n", equaltime, i, j, a[i]);
		    a[i] = 1 + rand() % 100;
		    break;
		}
		else
		{
		    max = j;
		}
	    }
	    if (max == i - 1)
	    {
		break;
	    }
	}
    }
}
int search(int a[], int n, int key)
{
    int left = 0;
    int middle = (n -1) / 2;
    int right = n - 1;
    const int nf = -1;
    while (right >= left)
    {
	if (a[middle] > key)
	{
	    right = middle - 1;
	    middle = (right + left) / 2;
	    printf("大\n");
	}
	else if (a[middle] < key)
	{
	    left = middle + 1;
	    middle = (right + left) / 2;
	    printf("小\n");
	}
	else
	{
	    return middle;
	}
	printf("right = %d, middle = %d, left =%d\n", right, middle, left);
    }
    return nf;
}
