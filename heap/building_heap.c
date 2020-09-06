#include<stdio.h>
#include<stdlib.h>
#define LARGE_VALUE 999
void restoreUp(int a[], int i)
{
	int k, iparent;
	k = a[i];
	iparent = i / 2;
	while (a[iparent] < k)
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
		rchild = lchild + 1;
	}
	//if n is even and heap dont ahve rchild
	if (lchild == n && k < a[lchild])
	{
		a[i] = a[lchild];
		i = lchild;
	}
	a[i] = k;
}
void display(int a[], int n)
{
	printf("heap size is %d \n", n);
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void buildheapTopdown(int a[], int n)
{
	int i;
	for (i = 2; i <= n; i++)
		restoreUp(a, i);
}
void buildheapBottomup(int a[], int n)
{
	int i;
	for (i = n/2; i >= 1; i--)
		restoredown(a, i, n);
} 
void main()
{
	int a1[] = { LARGE_VALUE,20,33,15,6,40,60,45,16,75,10,80,12};
	int a2[] = { LARGE_VALUE,20,33,15,6,40,60,45,16,75,10,80,12};

	int n = 12;
	buildheapBottomup(a1, n);
	buildheapTopdown(a2, n);

	printf("bottom up\n");
	display(a1, n);
	printf("top down\n");
	display(a2, n);
	system("pause");
}
