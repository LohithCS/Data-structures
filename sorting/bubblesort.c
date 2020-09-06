#include<stdio.h>
#define MAX 50
void main()
{
	int a[MAX], i, j, n, temp,swaps;
	printf("enter the number of elements\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("enter the %d element\n", i);
		scanf("%d", &a[i]);

	}
	printf("the unsorted array is :\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	for (i = 0; i < n-1; i++)
	{
		swaps = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				swaps++;
			}
			
		}
		if (swaps == 0)
			break;
	}
	printf("the sorted array is :\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
 } 