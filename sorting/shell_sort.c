#include<stdio.h>
#define MAX 50

void main()
{
	int n,h,i, j, temp, a[MAX];

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
	printf("enter the maximum increment odd value:\n");
	scanf("%d", &h);
	while (h >= 1)
	{
		for (i = h; i < n; i++)
		{
			temp = a[i];
			for (j = i - h; j >= 0 && a[j] > temp; j=j - h)
				a[j + h] = a[j];
			a[j + h] = temp;
		}
		h = h - 2;
	}

	printf("the sorted array is: ");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	system("pause");
}