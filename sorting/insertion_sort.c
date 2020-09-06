#include<stdio.h>
#define MAX 50

void main()
{
	int n, i, j, temp, a[MAX];

	printf("enter the number of elements\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("enter the element %d\n", i);
		scanf("%d", &a[i]);
	}
	printf("the unsorted array is :\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	for (i = 1; i < n; i++)
	{
		temp = a[i];
		for (j = i - 1; j >= 0 && a[j] > temp; j--)
			a[j + 1] = a[j];
		a[j + 1] = temp;
	}
	printf("the sorted array is: ");
	for (i = 0; i < n; i++)
		printf("%d  ", a[i]);
	printf("\n");
	system("pause");
}