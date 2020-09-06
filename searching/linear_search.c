#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int linearSearch(int a[], int n, int searchValue)
{
	/*int i;
	for (i = 0; i < n; i++)
	{
		if (a[i] == searchValue)
			return(i);
	}
	return(-1);*/
	// linear search with sentinel

	int i = 0;
	a[n] = searchValue;
	while (a[i] != searchValue)
		i++;
	if (i < n)
		return i;
	else
		return -1;

}
void main()
{
	int a[MAX], n, i, searchValue,index;

	printf("enter the number of elements\n");
	scanf("%d", &n);
	printf("enter the elements:\n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	printf("the array is :");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	printf("enter the value to be searched\n");
	scanf("%d",&searchValue);
	index = linearSearch(a, n, searchValue);

	if (index == -1)
		printf("%d is not found in the list\n", searchValue);
	else
		printf("%d is found a index %d\n", searchValue, index);
	system("pause");
}