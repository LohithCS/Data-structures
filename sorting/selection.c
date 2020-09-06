#include<stdio.h>
#include<stdlib.h>
#define MAX 50

void main()
{
	int n, i, j, minIndex, temp;
	int a[MAX];

	printf("enter the number of elements\n");
	scanf("%d",&n);
	printf("enter the elements of an array\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("the array is : ");
	for (i = 0; i < n; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");

	for (i = 0; i < n - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[minIndex])
				minIndex = j;
		}
		if (i != minIndex)
		{
			temp = a[i];
			a[i] = a[minIndex];
			a[minIndex] = temp;
		}
	}
	printf("the sorted array is: ");
	for (i = 0; i < n; i++)
		printf("%d  ", a[i]);
	printf("\n");
	system("pause");
}