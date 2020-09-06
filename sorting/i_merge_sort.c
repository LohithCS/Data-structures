#include<stdio.h>
#define MAX 50
void copy(int a[], int temp[], int n)
{
	int i;
	for (i = 0; i <= n-1; i++)
		a[i] = temp[i];
}
void merge(int a[], int temp[], int low1, int up1, int low2, int up2)
{
	int i, j, k;
	i = low1;
	j = low2;
	k = low1;
	while (i <= up1 && j <= up2)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <= up1)
		temp[k++] = a[i++];
	while (j <= up2)
		temp[k++] = a[j++];
}
void sortpass(int a[], int temp[], int size, int n)
{
	int i, low1, low2, up1, up2;

	low1 = 0;                      //0
	while (low1 + size <= n - 1)
	{
		up1 = low1 + size - 1;    //7
		low2 = low1 + size;       //8
		up2 = low2 + size - 1;    //15

		if (up2 >= n)             //case of n=11 and size=8 (nbecomes 11 in this step) 
			up2 = n - 1;

		merge(a, temp, low1, up1, low2, up2);

		low1 = up2 + 1;
	}
	for (i = low1; i <= n - 1; i++)   // case, when size is 4 and n=11 0,3,4,7 
		temp[i] = a[i];

	copy(a, temp, n);
}
void mergesort(int a[],int n)
{
	int size = 1;
	int temp[MAX];
	while (size <= n - 1)
	{
		sortpass(a, temp, size, n);
		size = size * 2;
	}
}
void main()
{
	int n, a[50], i;
	printf("enter the number of elements:\n");
	scanf("%d", &n);
	printf("emter the array:\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	mergesort(a, n);

	printf("the sorted list is :\n");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	system("pause");
 }