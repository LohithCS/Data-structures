#include<stdio.h>
#include<stdlib.h>
int GCD(int a, int b)
{
	if (b == 0)
		return(a);
	return(GCD(b, a % b));
}
void main()
{
	int a, b;
	printf("enter the two numbers a and b:\n");
	scanf("%d %d", &a, &b);
	printf("GCD of numbers %d and %d is : %d\n", a, b, GCD(a, b));
	system("pause");
}