#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int binarySearch(int a[], int n, int searchValue)
{
	int first = 0, last = n - 1, mid;
	while (first <= last)
	{
		mid = (first + last) / 2;
		if (searchValue > a[mid]) //search in right half of an Arr
			first = mid + 1;
		else if (searchValue < a[mid])
			last = mid - 1;
		else
			return(mid);
	}
	return(-1);
}
int recursiveBinarySearch(int a[], int first, int last, int searchValue)
{
	int mid;
	if (first > last)
		return(-1);
	mid = (first + last) / 2;
	if (searchValue < a[mid])
		recursiveBinarySearch(a, first, mid - 1, searchValue);
	else if (searchValue > a[mid])
		recursiveBinarySearch(a, mid + 1, last, searchValue);
	else
		return(mid);
}
void main()
{
	int a[MAX], n, i, searchValue, index;

	printf("enter the number of elements\n");
	scanf("%d", &n);
	printf("enter the elements in sorted order\n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("the array is: ");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	printf("enter the element to be searched\n");
	scanf("%d", &searchValue);
	index = recursiveBinarySearch(a, 0,n-1, searchValue);
	if (index == -1)
		printf("%d is not found in the list", searchValue);
	else
		printf("%d is found at index %d\n", searchValue,index);
	system("pause");

}
