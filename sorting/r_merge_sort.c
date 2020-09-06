#include<stdio.h>
void copy(int a[],int temp[],int low,int up)
{
	int i;
	for (i = low; i <= up; i++)
		a[i] = temp[i];
}
void merge(int a[], int temp[], int low1,int up1, int low2, int up2)
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
void mergesort(int a[], int low, int up)
{
	int mid;
	int temp[50];
	if (up == low)
		return;

	mid = (low + up) / 2;
	mergesort(a, low, mid);
	mergesort(a, mid + 1, up);
	
	merge(a, temp, low, mid, mid + 1, up);

	copy(a, temp, low, up); 
}
void main()
{
	int n,a[50],i;
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

	mergesort(a, 0, n - 1);

	printf("the sorted list is :\n");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	system("pause");
}