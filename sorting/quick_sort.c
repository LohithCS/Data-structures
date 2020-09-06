#include<stdio.h>
#define MAX 50
void quicksort(int a[], int low, int up)
{
	int p;
	if (low >= up)              //low>up zero element; low=up one element
		return;
	p = partition(a, low, up);
	quicksort(a, low, p - 1);
	quicksort(a, p + 1, up);
}
int partition(int a[], int low, int up)
{
	int temp, i, j, pivot;
	pivot = a[low];

	i = low + 1;
	j = up;

	while (i <= j)
	{
		while (a[i] < pivot && i < up)
			i++;
		while (a[j] > pivot)
			j--;
		if (i < j)                         // 
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
		else
			break;
	}
	a[low] = a[j];
	a[j] = pivot;
	return(j);
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

	quicksort(a, 0, n - 1);

	printf("the sorted list is :\n");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	system("pause");
}
