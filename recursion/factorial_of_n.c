#include<stdio.h>
#include<stdlib.h>
long int factorialOfn(int n);
long int sumOfn(int n);
void main()
{
	long int fact,sum;
	int n;
	printf("enter n :\n");
	scanf("%d",&n);
	fact = factorialOfn(n);
	printf("%d! is %ld\n", n, fact);
	sum= sumOfn(n);
	printf("sum of n numbers from 1 to %d is %ld\n", n, sum);

	system("pause");
}
long int factorialOfn(int n)
{
	if (n == 1)
		return(1);
	else
		return(n * factorialOfn(n - 1));
}
long int sumOfn(int n)
{
	if (n == 1)
		return(1);
	else
		return(n + sumOfn(n - 1));
}