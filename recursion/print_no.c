#include<stdio.h>
#include<stdlib.h>
void print_1_to_n(int n)
{
	if (n == 0)
		return;
	print_1_to_n(n - 1);
	printf("%d ", n);
}
void print_n_to_1(int n)
{
	if (n == 0)
		return;
	printf("%d ", n);
	print_n_to_1(n - 1);
}
int series(int n)
{
	int sum;
	if (n == 0)
		return 0;
	sum = n + series(n - 1);
	printf("%d+", n);
	return(sum);

}
void main()
{
	int n,sum;
	printf("enter n:\n");
	scanf("%d",&n);

	/*print_1_to_n(n);
	printf("\n");
	print_n_to_1(n);*/
	printf("\b =%d\n", series(n));
	system("pause");
}