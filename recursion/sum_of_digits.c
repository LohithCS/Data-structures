#include<stdio.h>
int sumOfDigits(long int n)
{
	if (n / 10 == 0)
		return(n);
	return(sumOfDigits(n / 10) + n % 10);
}
void main()
{
	long int n;
	printf("enter n:\n");
	scanf("%ld", &n);
	printf("sum of digits of %ld is %d\n", n, sumOfDigits(n));
	system("pause");
}