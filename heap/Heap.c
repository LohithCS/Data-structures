#include<stdio.h>
#include<stdlib.h>
#define LARGE_VALUE 999
void restoreUp(int a[], int i)
{
	int k, iparent;
	k = a[i];
	iparent = i / 2;
	while (a[iparent]<k)
	{
		a[i] = a[iparent];
		i = iparent;
		iparent = i / 2;
	}
	a[i] = k;
}
void restoredown(int a[], int i, int n)
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
		rchild = lchild+1;
	}
	//if n is even and heap dont ahve rchild
	if (lchild == n && k < a[lchild])
	{
		a[i] = a[lchild];
		i = lchild;
	}
	a[i] = k;
}
int deleteRoot(int a[], int* pn)
{
	int value=a[1];
	a[1] = a[*pn];
	(*pn)--;
	restoredown(a, 1, *pn);
	return(value);
}
void insert(int value, int a[], int* pn)
{
	(*pn)++;
	a[*pn] = value;
	restoreUp(a, *pn);
}
void display(int a[], int n)
{
	printf("heap size is %d \n", n);
	for (int i = 1; i <=n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void main()
{
	int a[50];
	int n = 0,value,choice; //heap size
	a[0] = LARGE_VALUE;

	while (1)
	{
		printf("1: insert\n");
		printf("2: delete\n");
		printf("3: display\n");
		printf("4; quit\n");
		scanf("%d", &choice);
		if (choice == 4)
			break;
		switch (choice)
		{
		case 1:
			printf("enter the valuse to be inserted\n");
			scanf("%d", &value);
			insert(value, a, &n);
			break;
		case 2:
			if (n == 0)
				printf("heap is empty\n");
			else
			{
				value = deleteRoot(a, &n);
				printf("the max value is %d\n", value);
			}
			break;
		case 3:
			display(a, n);
			break;
		default:
			printf("wrong choice\n");
			break;
		}
	}
}