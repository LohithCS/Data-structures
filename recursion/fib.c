#include<stdio.h>
int fib(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	else
		return(fib(n - 1) + fib(n - 2));
}
void main()
{
	int terms, i;
	printf("enter the no of terms:\n");
	scanf("%d", &terms);
	for (i = 0; i <= terms; i++)
		printf("%d ", fib(i));
	printf("\n");
	system("pause");
}