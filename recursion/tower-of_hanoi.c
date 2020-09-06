#include<stdio.h>
#include<stdlib.h>
void hanoi(int n, char source, char temp, char dest)
{
	if (n == 1)
	{
		printf("move disk %d from %c-->%c\n", n, source, dest);
		return;
	}
	hanoi(n - 1, source, dest, temp);
	printf("move disk %d from %c-->%c
		\n", n, source, dest);
	hanoi(n - 1, temp, source, dest);
}
void main()
{
	int n;
	printf("enter the no of diskes:\n");
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
	system("pause");

}