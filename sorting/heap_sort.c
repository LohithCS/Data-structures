#include<stdio.h>
#include<stdlib.h>
#define LARGEVALUE 9999
void heapsort(int a[], int size);
void buildheapBottomUp(int a[], int n);
void restoreDown(int a[], int i, int n);
int deleteroot(int a[], int* pn);
int deleteroot(int a[], int* pn)
{
	int maxvalue = a[1];
	a[1] = a[*pn];
	(*pn)--;
	restoreDown(a, 1, *pn);
	return(maxvalue);
}
void heapsort(int a[], int size)
{
	int max;
	buildheapBottomUp(a, size);
	while (size > 1)
	{
		max = deleteroot(a, &size);
		a[size + 1] = max;
	}
}
void buildheapBottomUp(int a[], int n)
{
	int i;
	for (i = n / 2; i >= 1; i--)
		restoreDown(a, i, n);
}
void restoreDown(int a[], int i, int n)
{
	int k = a[i];
	int lchild = 2 * i, rchild = lchild + 1;
	while (rchild <= n)
	{
		if (k >= a[lchild] && k >= a[rchild])
		{
			a[i] = k;
			return;
		}
		else if (a[lchild] > a[rchild])
		{
			a[i] = a[lchild];
			i = lchild;
		}
		else
		{
			a[i] = a[rchild];
			i = rchild;
		}
		lchild = 2 * i;
		rchild = lchild + 1;
	}
	if(lchild == n && k < a[lchild])
	{
		a[i] = a[lchild];
		i = lchild;
	}
	a[i] = k;
}
void main()
{
	int a[50], i, n;

	printf("enter the number of elements\n");
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		printf("enter the %d th element\n", i);
		scanf("%d", &a[i]);
	}
	printf("the unsorted array is :");
	for (i = 1; i <= n; i++)
		printf("%d ", a[i]);
	printf("\n");

	heapsort(a, n);

	printf("the sorted array is :");
	for (i = 1; i <= n; i++)
		printf("%d ", a[i]);
	printf("\n");

	system("pause");
}

