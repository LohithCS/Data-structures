#include<stdio.h>
#include<stdlib.h>
#define MAX 50
void insertList(int num, int addr);
int hashFn(int x, int large);
void addrCalcsort(int a[], int n);
struct node
{
	int info;
	struct node* link;
};
struct node* start[6];
int hashFn(int x, int large)
{
	int addr;
	float temp;
	temp = (float)x / large;
	addr = temp * 5;
	return(addr);
}
void addrCalcsort(int a[], int n)
{
	int i, j, addr, large = 0;
	struct node* p;

	for (i = 0; i < n; i++)
		start[i] = NULL;
	
	for (i = 0; i < n; i++)
	{
		if (a[i] > large)
			large = a[i];
	}

	for (i = 0; i < n; i++)
	{
		addr = hashFn(a[i], large);
		insertList(a[i], addr);
	}
	i = 0;
	for (j = 0; j <= 5; j++)
	{
		p = start[j];
		while (p != NULL)
		{
			a[i++] = p->info;
			p = p->link;
		}
	}
}
void insertList(int num, int addr)
{
	struct node* temp, * q;

	temp = (struct node*)malloc(sizeof(struct node));
	temp->info = num;

	if (start[addr] == NULL || num < start[addr]->info)
	{
		temp->link = start[addr];
		start[addr] = temp;
		return;
	}
	else
	{
		q = start[addr];
		while (q->link != NULL && q->link->info < num)
			q = q->link;
		temp->link = q->link;
		q->link = temp;
	}
}
void main()
{
	int i, n, a[MAX];

	printf("enter the number of elements in the list\n");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("enter element %d ", i + 1);
		scanf("%d", &a[i]);
	}

	addrCalcsort(a, n);

	printf("sorted list:\n");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	system("pause");
}
